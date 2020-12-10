//---------------------------------------------------------------------------
#ifndef DConvert
#define DConvert

#pragma hdrstop

#include "DConvert.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------

#include <stdio.h>
#include <vcl.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"

//---------------------------------------------------------------------------
typedef unsigned long long internal_t;
 
static unsigned
char_to_digit (char c, unsigned radix)
{
  unsigned res;
 
  if (c >= '0' && c <= '9')
    res = c - '0';
  else if (c >= 'a' && c <= 'z')
    res = 10 + (c - 'a');
  else if (c >= 'A' && c <= 'Z')
    res = 10 + (c - 'A');
  else
    abort();
 
  if (res >= radix)
    abort();
 
  return res;
}
 
static char
digit_to_char (unsigned digit)
{
  char res;
 
  if (digit <= 9)
    return '0' + digit;
  else if (digit <= 36)
    return 'a' + (digit - 10);
  else
    abort();
 
  return '\0'; /* avoid warning */
}
 
static internal_t
str_to_internal (const char *str, unsigned radix)
{
  unsigned i;
  internal_t res = 0;
 
  for (i = 0; i < strlen (str); i++)
    {
      res *= radix;
      res += char_to_digit (str[i], radix);
    }
 
  return res;
}
 
static void
internal_to_str (internal_t ival, char *dst, unsigned radix)
{
  char buf[256], *p = &buf[0];
  unsigned r;
 
  do
    {
      r = ival % radix;
      *p++ = digit_to_char (r);
      ival = ival / radix;
    }
  while (ival != 0);
 
  do
    *dst++ = *--p;
  while (p != &buf[0]);
 
  *dst = '\0';
}

void
conv_radix (/* const */char *src_str, unsigned src_radix,
            char *dst_str, unsigned dst_radix)
{
  internal_t ival;
 
  ival = str_to_internal (src_str, src_radix);
  internal_to_str (ival, dst_str, dst_radix);
}

char boolsToChar(bool* bools){
     char c = 0;
     for( int i = 0; i < 8; i++ )
          if( bools[i] ) 
              c += pow(2,i);
     return c;
}

void CW_Bin2Oct (bool cw[16], char *cwoct){
  char buf[256],cwchar;
  cwchar = boolsToChar(cw);
  AnsiString fe = cwchar;
  conv_radix (fe.c_str(), 2, buf, 8);
  cwoct = buf;

}
//---------------------------------------------------------------------------

#endif //DConvert
