//---------------------------------------------------------------------------
/*****************************************************************************
******************************************************************************
****               КЛАСС ЗАЗИПОВКИ и РАЗЗИПОВКИ ФАЙЛОВ                    ****
****                                                                      ****
****    Алгоритм взят из пособия "Техника для сжатия данных высокого      ****
****     исполнения", Тэрри A. Уэльский, IEEE Computer Vol 17, No 6       ****
****                       (Июнь 1984), cтр. 8-19                         ****
****                                                                      ****
****    Автор     : Широкий С.М.                                          ****
****    Версия    : 01.01 / 01.04.2006 /                                  ****
******************************************************************************
*****************************************************************************/
//---------------------------------------------------------------------------
#ifndef ZipH
#define ZipH

#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
 
// Класс сжатия данных
class FLYZIP_API Zip
{
private:	// User declarations
#define	min_d(a,b)	((a>b) ? b : a)
#define MAXPATHLEN 1024  // максимальная длина пути к файлам 

// машинные варианты, которые требуют cc -Dmachine: pdp11, z8000, pcxt
// Установите USERMEM на максимальную сумму доступной физической памяти для потребителя в байтах.
// USERMEM использован, чтобы определять максимальные биты, которые могут быть использованы для сжатия.
// SACREDMEM - сумма физической памяти за исключением другой; компресс схватит остальную.
#ifndef SACREDMEM
#define SACREDMEM	0
#endif

#ifndef USERMEM
# define USERMEM 	450000	// встроенная память потребителя
#endif

#ifdef interdata		      // (Perkin-Elmer) 
#define SIGNED_COMPARE_SLOW	//подписанное сравнение медленнее чем неподписанное
#endif

#ifdef pdp11
# define BITS 	12	      // максимум бит/код для 16- битовой машины
# define NO_UCHAR	        // also if "unsigned char" functions as signed char
# undef USERMEM
#endif                    // pdp11  ( don't forget to compile with -i )

#ifdef z8000
# define BITS 	12
# undef vax		            // странный препроцессор
# undef USERMEM 
#endif // z8000

#ifdef pcxt
# define BITS   12
# undef USERMEM
#endif // pcxt

#ifdef USERMEM
# if USERMEM >= (433484+SACREDMEM)
#  define PBITS	16
# else
#  if USERMEM >= (229600+SACREDMEM)
#   define PBITS	15
#  else
#   if USERMEM >= (127536+SACREDMEM)
#    define PBITS	14
#   else
#    if USERMEM >= (73464+SACREDMEM)
#     define PBITS	13
#    else
#     define PBITS	12
#    endif
#   endif
#  endif
# endif
# undef USERMEM
#endif // USERMEM

#ifdef PBITS		        //Предпочтительное количество бит для этого размера памяти
# ifndef BITS
#  define BITS PBITS
# endif // BITS
#endif // PBITS

#if BITS == 16
# define HSIZE	69001		// 95% размещение
#endif
#if BITS == 15
# define HSIZE	35023		// 94% размещение
#endif
#if BITS == 14
# define HSIZE	18013		// 91% размещение
#endif
#if BITS == 13
# define HSIZE	9001		// 91% размещение
#endif
#if BITS <= 12
# define HSIZE	5003		// 80% размещение
#endif

#ifdef M_XENIX			    // Stupid compiler can't handle arrays with 
# if BITS == 16			    // more than 65535 bytes - so we fake it 
#  define XENIX_16
# else
#  if BITS > 13			    // Закодируйте только ручки BITS = 12, 13, or 16
#   define BITS	13
#  endif
# endif
#endif


#if BITS > 15           // переменная code_int должна быть способным подержать величины 2*BITS типа int, и также -1
typedef long int code_int;
#else
typedef int		code_int;
#endif


#ifdef SIGNED_COMPARE_SLOW
typedef unsigned long int count_int;
typedef unsigned short int count_short;
#else
typedef long int	  count_int;
#endif

#ifdef NO_UCHAR
 typedef char	char_type;
#else
 typedef	unsigned char	char_type;
#endif // UCHAR


#ifndef vax
char_type lmask[9], rmask[9];
#endif // vax

//Определяется для третьего байта заголовка
#define BIT_MASK	0x1f
#define BLOCK_MASK	0x80
// Masks 0x40 and 0x20 are free.  I think 0x20 should mean that there is
// a fourth header byte (for expansion).

#define INIT_BITS 9			//начальное количество битов/кода

/*
 * File compression ala IEEE Computer, June 1984.
 *
 * Authors:	Spencer W. Thomas	(decvax!harpo!utah-cs!utah-gr!thomas)
 *		Jim McKie		(decvax!mcvax!jim)
 *		Steve Davies		(decvax!vax135!petsd!peora!srd)
 *		Ken Turkowski		(decvax!decwrl!turtlevax!ken)
 *		James A. Woods		(decvax!ihnp4!ames!jaw)
 *		Joe Orost		(decvax!vax135!petsd!joe)
 *		Dave Mack		(csu@alembic.acs.com)
 *
 * Revision 4.1   91/05/26  	  csu@alembic.acs.com
 * Modified to recursively compress directories ('r' flag). As a side
 * effect, compress will no longer attempt to compress things that
 * aren't "regular" files. See Changes.
 *
 * Revision 4.0  85/07/30  12:50:00  joe
 * Removed ferror() calls in output routine on every output except first.
 * Prepared for release to the world.
 * 
 * Revision 3.6  85/07/04  01:22:21  joe
 * Remove much wasted storage by overlaying hash table with the tables
 * used by decompress: tab_suffix[1<<BITS], stack[8000].  Updated USERMEM
 * computations.  Fixed dump_tab() DEBUG routine.
 *
 * Revision 3.5  85/06/30  20:47:21  jaw
 * Change hash function to use exclusive-or.  Rip out hash cache.  These
 * speedups render the megamemory version defunct, for now.  Make decoder
 * stack global.  Parts of the RCS trunks 2.7, 2.6, and 2.1 no longer apply.
 *
 * Revision 3.4  85/06/27  12:00:00  ken
 * Get rid of all floating-point calculations by doing all compression ratio
 * calculations in fixed point.
 *
 * Revision 3.3  85/06/24  21:53:24  joe
 * Incorporate portability suggestion for M_XENIX.  Got rid of text on #else
 * and #endif lines.  Cleaned up #ifdefs for vax and interdata.
 *
 * Revision 3.2  85/06/06  21:53:24  jaw
 * Incorporate portability suggestions for Z8000, IBM PC/XT from mailing list.
 * Default to "quiet" output (no compression statistics).
 *
 * Revision 3.1  85/05/12  18:56:13  jaw
 * Integrate decompress() stack speedups (from early pointer mods by McKie).
 * Repair multi-file USERMEM gaffe.  Unify 'force' flags to mimic semantics
 * of SVR2 'pack'.  Streamline block-compress table clear logic.  Increase 
 * output byte count by magic number size.
 * 
 * Revision 3.0   84/11/27  11:50:00  petsd!joe
 * Set HSIZE depending on BITS.  Set BITS depending on USERMEM.  Unrolled
 * loops in clear routines.  Added "-C" flag for 2.0 compatibility.  Used
 * unsigned compares on Perkin-Elmer.  Fixed foreground check.
 *
 * Revision 2.7   84/11/16  19:35:39  ames!jaw
 * Cache common hash codes based on input statistics; this improves
 * performance for low-density raster images.  Pass on #ifdef bundle
 * from Turkowski.
 *
 * Revision 2.6   84/11/05  19:18:21  ames!jaw
 * Vary size of hash tables to reduce time for small files.
 * Tune PDP-11 hash function.
 *
 * Revision 2.5   84/10/30  20:15:14  ames!jaw
 * Junk chaining; replace with the simpler (and, on the VAX, faster)
 * double hashing, discussed within.  Make block compression standard.
 *
 * Revision 2.4   84/10/16  11:11:11  ames!jaw
 * Introduce adaptive reset for block compression, to boost the rate
 * another several percent.  (See mailing list notes.)
 *
 * Revision 2.3   84/09/22  22:00:00  petsd!joe
 * Implemented "-B" block compress.  Implemented REVERSE sorting of tab_next.
 * Bug fix for last bits.  Changed fwrite to putchar loop everywhere.
 *
 * Revision 2.2   84/09/18  14:12:21  ames!jaw
 * Fold in news changes, small machine typedef from thomas,
 * #ifdef interdata from joe.
 *
 * Revision 2.1   84/09/10  12:34:56  ames!jaw
 * Configured fast table lookup for 32-bit machines.
 * This cuts user time in half for b <= FBITS, and is useful for news batching
 * from VAX to PDP sites.  Also sped up decompress() [fwrite->putc] and
 * added signal catcher [plus beef in writeerr()] to delete effluvia.
 *
 * Revision 2.0   84/08/28  22:00:00  petsd!joe
 * Add check for foreground before prompting user.  Insert maxbits into
 * compressed file.  Force file being uncompressed to end with ".Z".
 * Added "-c" flag and "zcat".  Prepared for release.
 *
 * Revision 1.10  84/08/24  18:28:00  turtlevax!ken
 * Will only compress regular files (no directories), added a magic number
 * header (plus an undocumented -n flag to handle old files without headers),
 * added -f flag to force overwriting of possibly existing destination file,
 * otherwise the user is prompted for a response.  Will tack on a .Z to a
 * filename if it doesn't have one when decompressing.  Will only replace
 * file if it was compressed.
 *
 * Revision 1.9  84/08/16  17:28:00  turtlevax!ken
 * Removed scanargs(), getopt(), added .Z extension and unlimited number of
 * filenames to compress.  Flags may be clustered (-Ddvb12) or separated
 * (-D -d -v -b 12), or combination thereof.  Modes and other status is
 * copied with copystat().  -O bug for 4.2 seems to have disappeared with
 * 1.8.
 *
 * Revision 1.8  84/08/09  23:15:00  joe
 * Made it compatible with vax version, installed jim's fixes/enhancements
 *
 * Revision 1.6  84/08/01  22:08:00  joe
 * Sped up algorithm significantly by sorting the compress chain.
 *
 * Revision 1.5  84/07/13  13:11:00  srd
 * Added C version of vax asm routines.  Changed structure to arrays to
 * save much memory.  Do unsigned compares where possible (faster on
 * Perkin-Elmer)
 *
 * Revision 1.4  84/07/05  03:11:11  thomas
 * Clean up the code a little and lint it.  (Lint complains about all
 * the regs used in the asm, but I'm not going to "fix" this.)
 *
 * Revision 1.3  84/07/05  02:06:54  thomas
 * Minor fixes.
 *
 * Revision 1.2  84/07/05  00:27:27  thomas
 * Add variable bit length output.
 */


#define ARGVAL() (*++(*argv) || (--argc && *++argv))

int n_bits;				    // число bits/code
int maxbits;		      // потребитель settable max # bits/code
code_int maxcode;			// максимальный код, давший  n_bits
code_int maxmaxcode;	// никогда не должно сгенерировать этот код

#ifdef COMPATIBLE		  // But wrong!
# define MAXCODE(n_bits)	(1 << (n_bits) - 1)
#else
# define MAXCODE(n_bits)	((1 << (n_bits)) - 1)
#endif // COMPATIBLE

#ifdef XENIX_16
count_int htab0[8192];
count_int htab1[8192];
count_int htab2[8192];
count_int htab3[8192];
count_int htab4[8192];
count_int htab5[8192];
count_int htab6[8192];
count_int htab7[8192];
count_int htab8[HSIZE-65536];
count_int * htab[9] = {htab0, htab1, htab2, htab3, htab4, htab5, htab6, htab7, htab8 };

#define htabof(i)	(htab[(i) >> 13][(i) & 0x1fff])
unsigned short code0tab[16384];
unsigned short code1tab[16384];
unsigned short code2tab[16384];
unsigned short code3tab[16384];
unsigned short code4tab[16384];
unsigned short * codetab[5] = {
	code0tab, code1tab, code2tab, code3tab, code4tab };

#define codetabof(i)	(codetab[(i) >> 14][(i) & 0x3fff])

#else	// Нормальная машина
count_int htab [HSIZE];
unsigned short codetab [HSIZE];
#define htabof(i)	htab[i]
#define codetabof(i)	codetab[i]
#endif	// XENIX_16
code_int hsize, fsize;			// для динамической табличной калибровки

char IOoutbuf[65536];

/*
 * To save much memory, we overlay the table used by compress() with those
 * used by decompress().  The tab_prefix table is the same size and type
 * as the codetab.  The tab_suffix table needs 2**BITS characters.  We
 * get this from the beginning of htab.  The output stack uses the rest
 * of htab, and contains characters.  There is plenty of room for any
 * possible stack (stack used to be 8000 characters).
*/

#define tab_prefixof(i)	codetabof(i)
#ifdef XENIX_16
# define tab_suffixof(i)	((char_type *)htab[(i)>>15])[(i) & 0x7fff]
# define de_stack		((char_type *)(htab2))
#else	// Нормальная машина
# define tab_suffixof(i)	((char_type *)(htab))[i]
# define de_stack		((char_type *)&tab_suffixof(1<<BITS))
#endif	// XENIX_16

code_int free_ent; // первый неиспользованный вход
long int getcode();

int exit_stat,
    nomagic,	     // Use a 3-byte magic number header, unless old file
    zcat_flg,	     // Write output on stdout, suppress messages
    quiet;		     // don't tell me about compression


 // block compression parameters -- after all codes are used up,
 // and compression rate changes, start over.

int clear_flg;
long int ratio;
#if BITS == 16
#define CHECK_GAP 50000	// контрольный интервал коэффициента рекомендуется by jaw
#else
#define CHECK_GAP 10000	// контрольный интервал коэффициента
#endif
count_int checkpoint;

// the next two codes should not be changed lightly, as they must not
// lie within the contiguous general code space.

#define FIRST	257	// сначала свободный вход
#define	CLEAR	256	// table  очистка выходного кода

int force,
    valid;		// установить когда сигнал может удалить ofname

char ofname[MAXPATHLEN];
struct stat statbuf, insbuf;

/*****************************************************************
 *Inputs:
 *	-d:	    If given, decompression is done instead.
 *  -v:	    Write compression statistics
 *	-r:		Recursive. If a filename is a directory, descend
 *			into it and compress everything in it.
 *
 * 	file ...:   Files to be compressed.  If none specified, stdin
 *		    is used.
 * Outputs:
 *	file.Z:	    Compressed form of file with same mode, owner, and utimes
 * 	or stdout   (if stdin used as input)
 *
 * Assumptions:
 *	When filenames are given, replaces with the compressed version
 *	(.Z suffix) only if the file decreases in size.
 * Algorithm:
 * 	Modified Lempel-Ziv method (LZW).  Basically finds common
 * substrings and replaces them with a variable size code.  This is
 * deterministic, and can be done on the fly.  Thus, the decompression
 * procedure needs no input table, but tracks the way the table was built.
 */

 int overwrite,	     // true - перезапись, false - пропустить
     recursive,      // Директории компресса
     block_compress; // Не удаляет исходник
                     // -b:  Параметр ограничивает max количество битов/кода.
 int offset, size;
 
 long int in_count,  // размер при входе
          bytes_out, // размер сжатого выхода
          out_count; // # of codes output (for debugging)

 char_type buf[BITS];
 
 FILE *in;

 // Текст ошибки
 char COD_ERROR[256], Slech[2];

 // Функция получения описания ошибки по номеру
 void error_exit(int i, char *p);

 int comprexx(char *fileptr, char *DirOut, bool flag_zip);
 int compdir(char *dir, char *end_kat);
 int compress();
 int output( code_int  code );
 int decompress();
 int prratio(FILE *stream, long int num, long int den);
 char *rindex(register char *s, register char c, bool excludeExt=false);
 int in_stack(register int c, register int stack_top);
 int cl_hash(register count_int hsize);
 int cl_block();

public:		// User declarations
  Zip();
 ~Zip();

  // Установка флага запаковки каталога
  void set_flg_dir(int p){zcat_flg = p; return;}

  // Функции зазиповки и раззиповки файлов
  int zip_unzip(char *NameFile, char *DirOut, bool flg_zip, bool over, char *cod_return);
  // NameFile   - Название файла и путь к нему
  // DirOut     - Путь выходного файла
  // flag_zip   - true - зазиповать, false - раззиповать
  // over       - true - перезапись, false - пропустить
  // cod_return - Текст ощибки возврата
};
#endif

