//--------------------------------------------------------------------------------
// EdfDef.h
#ifndef EDFDEF_H
#define EDFDEF_H
//--------------------------------------------------------------------------------
#define EdfString string
#define EdfLenghtString(s)(s.length())
#define EdfPointString(s) ((char*)s.c_str())
/*
#ifdef _MFC_VER
	// ������ ��� ���������� � �������������� ���������� MFC
	#define  EdfString CString
	#define  EdfLenghtString( s ) ( s.GetLength( ) )
	#define  EdfPointString( s ) ( ( char* )( const char* )s )
	#define  WM_USER_ WM_USER 
#else
	#ifdef INC_VCL
		// ������ ��� ���������� � �������������� ���������� VCL
		#define  ASSERT assert
		#define  EdfString String
		#define  EdfLenghtString( s ) ( s.Length( ) )
		#define  EdfPointString( s ) ( s.c_str( ) )
		#define  WM_USER_ WM_USER 
	#else
		// ������ ��� ���������� � �������������� ���������� QT
		#include <QString>
		#include <QEvent>
		#define  ASSERT assert
		#define  EdfString QString
		#define  EdfLenghtString( s ) ( s.length( ) )
		#define  EdfPointString( s ) ( ( char* )( ( s.toAscii( ) ).data( ) ) )
		#define  WM_USER_ QEvent::User 
	#endif
#endif
*/
//--------------------------------------------------------------------------------
// ������� ������
//--------------------------------------------------------------------------------
#define EDF_NOTFORMAT  0     // ����������������� ���� (������ ������)
// ����
#define EDF_DMY        1     // ���� ����� ���
#define EDF_DMYHMS     2     // ���� ����� ��� ���� ������ �������
// �����
#define EDF_HMS        3     // ���� ������ �������
#define EDF_SSSHMS     4     // ����� ���� ������ �������
#define EDF_MILLIS     5     // �����������
#define EDF_SEC        6     // �������
#define EDF_MIN        7     // ������
#define EDF_HOUR       8     // ����
#define EDF_SSS        9     // �����
// ������� ��������
#define EDF_GMS        10    // ������� ������ �������
#define EDF_GRAD       11    // �������
#define EDF_RAD        12    // �������
#define EDF_VITGMS     13    // ����� + �������� ������ ������� ������ �������
#define EDF_VITGRAD    14    // ����� + �������� ������ �������
#define EDF_VITRAD     15    // ����� + �������� ������ �������
// �����
#define EDF_FLOAT      16    // �������������� ����� � ����� � ��������� ������
#define EDF_FIXED      17    // �������������� ����� � ����� � ������������� ������
// ������������� ������
#define EDF_INTEGER    18    // ����� �����
#define EDF_YESNO      19    // ��� ��  - ���
#define EDF_INSERT     20    // ��� ��� - ����
#define EDF_01         21    // ��� 0   - 1
#define EDF_CHECK      22    // ���          // ������ ��� �������
#define EDF_CHECKYN    23    // ���          // ������ ��� �������
#define EDF_CHECKCOLOR 24    // ���          // ������ ��� �������
#define EDF_ALT        25    // ����� ������������
//
#define EDF_KEYNU      26    // ���� ��        (�����, ���, �����������, ��)
#define EDF_KEYNUFULL  27    // ������ ���� �� (��, �����, ���, �����������, ��)
#define EDF_CUSTOMKEY  28    // ������������ ����� ������
//
#define EDF_DEFAULT	   6	 // ������������ �� ���������
//--------------------------------------------------------------------------------
// ���� ��������
//--------------------------------------------------------------------------------
#define EDF_TFNOTFORMAT  0        // ����������������� ����
#define EDF_TFDATA       1        // ����
#define EDF_TFDATATIME   2        // ���� �����
#define EDF_TFTIME       3        // �����
#define EDF_TFANGL       4        // ������� ��������
#define EDF_TFVITARG     5        // ����� ��������
#define EDF_TFNUMBER     6        // ����� (�� �����)
#define EDF_TFINT        7        // �����
#define EDF_TFBOOL       8        // �������� ��� (��-���, 0-1)
#define EDF_TFCHECK      9        // �������� ��� (�������)
#define EDF_TFKEYNU      10       // ����� ��
#define EDF_TFKEY        11       // ������������ ����� ������
#define EDF_TFCURRENT    100      // ������� ��� ������
//--------------------------------------------------------------------------------
// �������� �������� ������
//--------------------------------------------------------------------------------
#define EDF_TESTVALIVAR_NEVE   0  // �������� ��������
#define EDF_TESTVALIVAR_EXIT   1  // �������� ��� ������ �� �������� ��������������
#define EDF_TESTVALIVAR_EDIT   2  // �������� ������������ � ���� �������������� (��� ����� �������� ����)
//--------------------------------------------------------------------------------
// ����� �������� ������
//--------------------------------------------------------------------------------
#define EDF_FTEST_SETFOCUS     1  // ��������� ������� ������ 
#define EDF_FTEST_BEEP         2  // ����Beep  ��� ������ 
#define EDF_FTEST_KILLLEFTZ    4  // ���������� ����� ����� 
#define EDF_FTEST_             8  // 
//--------------------------------------------------------------------------------
// ����� ���������� ������� ������� CFormatEdit � ��������� ��������������
//--------------------------------------------------------------------------------
#define EDF_BFE_STDCOLOR           1     // ������ ���� �������� �������������� ������� ����� ������������������� �������
#define EDF_BFE_NOTCHANGENAME      2     // ������ ��������� ����� ��������� ��� ������ ������� "������"
#define EDF_BFE_NOTCHANGEHINT      4     // ������ ��������� ��������� ��� ������ ������� "������"
#define EDF_BFE_NOTCHANGEDEC       8     // ������ ��������� �������� ������������� ������ ��� ������ ������� "������"
#define EDF_BFE_NOTCHANGEFORMAT    16    // ������ ��������� ������� ������������� ������ ��� ������ ������� "������"
#define EDF_BFE_NOTCHANGEVIEW      32    // ������ ��������� �������� ���� ������������� ������ ��� ������ ������� "������"
#define EDF_BFE_NOTCHANGEALL       64    //
#define EDF_BFE_NOTEDITFORMAT      128   // ������ ������������� ������� "������"
#define EDF_BFE_NOTUSERCALC        256   // ������ ������������� ������� "�����������"
#define EDF_BFE_NOTUSERSELDATA     512   // ������ ������������� ������� "���������"
#define EDF_BFE_USERLIST           1024  // ������� ������� � ������������� ���� ����������������� �������� (WM_USER_EDF_SELECTLIST)
#define EDF_BFE_USERVIEW           2048  // ������� ������� � ������������� ���� ��������� ����������� �������� �������������� (WM_USER_EDF_VIEWDATA)
#define EDF_BFE_USERVALUETESTING   4096  // ������� ������� � ������������� ���� �������� ������������ �������� (WM_USER_EDF_VALUETESTING)
//--------------------------------------------------------------------------------
// ����� ���������� ������� ������� CFormatGrid � ��������
//--------------------------------------------------------------------------------
#define EDF_BFG_FORMATFROMROW          1          // ������������� ������� �� ������� (������ ��� Grid)

#define EDF_BFG_AUTOROWSIZE            2          // ������������� ��������� ������ ����� � ������������ � ������� �������
#define EDF_BFG_AUTOCOLSIZE            4          // ������������� ��������� ������ �������� � ������������ � ������� �������
#define EDF_BFG_AUTOFIXEDUPPSIZE       8          // ������������� ��������� ������ �������� �� ��������� ������������� ����� � ������������ � ������� �������
#define EDF_BFG_AUTOFIXEDLEFTSIZE      16         // ������������� ��������� ������ ����� ������������� �������� �� ��������� � ������������ � ������� �������
#define EDF_BFG_AUTOLSCOLSIZE          32         // ������������� ��������� � ��������������� ������ ��������
#define EDF_BFG_AUTOLSFIELDINDEX       64         //
#define EDF_BFG_AUTOSIZEJUSTUS         128        // ��������� ������ ���� �������� ����� �� ������� ������

#define EDF_BFG_SIZECOLUMNALLCLIENT    256        // ��������� ������ �������� � ������������ � �������� ����
#define EDF_BFG_MINSIZECOLUMNFROMHIDER 512        // ��������� ������ �������� � ������������ � �������� ����

#define EDF_BFG_MOVEDFIELD             1024       //
#define EDF_BFG_MOVEDITEM              2048       //

#define EDF_BFG_NOTSELRANGE            4096       // ������ �� ��������� ���������
#define EDF_BFG_NOTSELCLICKFIELD       8192       // ������ �� ��������� ���� ������ �� ��������� ����
#define EDF_BFG_NOTSELCLICKITEM        16384      // ������ �� ��������� ������ ������ �� ��������� ������

#define EDF_BFG_READONLY               32768      // ������� �������� ������ �� ������
#define EDF_BFG_GRAYREADONLY           65536      // ���������� ������ ��������� ������ �� ������ ������ �����

#define EDF_BFG_FLATFIXED              131072     // ������������� ������ ���������� ��������
#define EDF_BFG_ADGECELL               262144     // �������� ������ ������� ������������� ������ �����������
#define EDF_BFG_INVERTFOCUSRECT        524288     // ����� ������ ����� ���������� ������ ���������������� ���� ������
#define EDF_BFG_NOTHIDEFOCUSRECT       1048576    // ���������� ����� ������ ����� ��� ������ ��������
#define EDF_BFG_NOTHIDESELECT          2097152    // ���������� ���������� �������� ��� ������ ������ �����
#define EDF_BFG_RIGHTCOLFULLCLIENT     4194304    // ������ ������ ������� ����������� ����� ������� ����� ��������� ��� ���������� ����� ����

#define EDF_BFG_VIEWZOOM               8388608    // ��������� �������� ������������� ������
#define EDF_BFG_EMPTYZEROSTRING        16777216   // ���������� ������� ������ � ���� ������ ������
#define EDF_BFG_STRETCHBMP             33554432   // ��������������� ����������� �������
#define EDF_BFG_LIKEFIXEDASFIXED       67108864   // ���������� ������ �� ��������� LikeFixed �� ������������� ������
#define EDF_BFG_LIGHTFOCUSCOLROW       134217728  // ��������� ������ � ������� ������� ��������� � ������ �����
#define EDF_BFG_LIGHTMOUSECOLROW       268435456  // ��������� ������ � ������� ��� �����
#define EDF_BFG_ITEMFULLSELECT         536870912  // ��������� ������ ������� (����������� � EDF_BFG_FIELDFULLSELECT)
#define EDF_BFG_FIELDFULLSELECT        1073741824 // ��������� ���� �������   (����������� � EDF_BFG_ITEMFULLSELECT)
#define EDF_BFG_CHECKSELECT            2147483648 // ��������� ���������� ������� ��� �����
//--------------------------------------------------------------------------------
// �������� ������� �������
//--------------------------------------------------------------------------------
#define ON     1  // �������� 
#define OFF    0  // ���������
//--------------------------------------------------------------------------------
// ����� ������ ��� �������              
//--------------------------------------------------------------------------------
#define EDF_GFONTSTYLE_BOLD     1
#define EDF_GFONTSTYLE_ITALIC   2
#define EDF_GFONTSTYLE_UNDERL   4
#define EDF_GFONTSTYLE_STRIKE   8
//
#define EDF_FONT_BOLD               1     // ������ 
#define EDF_FONT_ITALIC             2     // ���������
#define EDF_FONT_UNDER_LINE         4     // ������������
#define EDF_FONT_STRIKE             8     // �����������
#define EDF_FONT_BOLD_NOTSET        128   // ������        (�� �����)
#define EDF_FONT_ITALIC_NOTSET      256   // ���������     (�� �����) 
#define EDF_FONT_UNDER_LINE_NOTSET  512   // ������������  (�� �����)
#define EDF_FONT_STRIKE_NOTSET      1024  // �����������   (�� �����)
//
#define EDF_FONT_SIZE_ADDIN         16    // ������ ������ ����� ����� �������� � �������� �������
//--------------------------------------------------------------------------------
// ������������ ��������
//--------------------------------------------------------------------------------
#define EDF_GCOLALIGN_DEFAULT   0    //
#define EDF_GCOLALIGN_LEFT      0    //
#define EDF_GCOLALIGN_RIGHT     1    //
#define EDF_GCOLALIGN_CENTER    2    //
#define EDF_GCOLALIGN_NOTSET    127  //
//--------------------------------------------------------------------------------
#define EDF_PROPERTY_NOTSET     127  //
#define EDF_COLOR_NOTSET        0x80000000 //
//--------------------------------------------------------------------------------
// ������� ������� ��� ��������������
//--------------------------------------------------------------------------------
#define EDF_GEDIT_ENABLE        0    //
#define EDF_GEDIT_DISABLE       1    //
#define EDF_GEDIT_READONLY      1    //
//--------------------------------------------------------------------------------
// ����������� ������ ������
//--------------------------------------------------------------------------------
#define EDF_GNOTCANSEL_DISABLE  0    //
#define EDF_GNOTCANSEL_ENABLE   1    //
#define EDF_GNOTCANSEL_NOTSET   2    //
//--------------------------------------------------------------------------------
// �������� ����� �������� �������������
//--------------------------------------------------------------------------------
#define EDF_GFIXEDLIKE_ON       0    //
#define EDF_GFIXEDLIKE_OFF      1    //
#define EDF_GFIXEDLIKE_NOTSET   2    //
//--------------------------------------------------------------------------------
// ��� �����
//--------------------------------------------------------------------------------
#define EDF_GADGE_NORMAL        0    //
#define EDF_GADGE_UPP           1    //
#define EDF_GADGE_DOWN          2    //
#define EDF_GADGE_LOW_UPP       3    //
#define EDF_GADGE_LOW_DOWN      4    //
#define EDF_GADGE_NOTSET        127  //
//--------------------------------------------------------------------------------
// Use this as the classname when inserting this control as a custom control
// in the MSVC++ dialog editor
//--------------------------------------------------------------------------------
#define EDF_EDIT_VCCTRL_CLASSNAME    _T("CFormatEdit")    // Window class name
#define EDF_GRID_VCCTRL_CLASSNAME    _T("CFormatGrid")    // Window class name
#define EDF_GRIDEX_VCCTRL_CLASSNAME  _T("CFormatGridEx")  // Window class name
#define EDF_LIST_VCCTRL_CLASSNAME    _T("CFormatList")    // Window class name
#define EDF_CUST_VCCTRL_CLASSNAME    _T("CFormatCustom")  // Window class name
#define IDC_INPLACE_EDIT             99                   // ID of inplace edit controls
#define IDC_INPLACE_COMBO            100                  // ID of inplace combobox controls
//--------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------
#define EDF_GRID_COL_W_DEF      72     // ����������� ������ ������� � �������
#define EDF_GRID_ROW_H_DEF      12     // ����������� ������ ������ � �������
#define EDF_GRID_W_INDENT_PIXEL 2      // ����������� ������ �� ������� ������
#define EDF_GRID_H_INDENT_PIXEL 1      // ����������� ������ 
//--------------------------------------------------------------------------------
// ����� ����� ���� �������
//--------------------------------------------------------------------------------
#define EDF_GRID_BS_CLIENT      1
#define EDF_GRID_BS_STATIC      2
#define EDF_GRID_BS_MODAL       4
//--------------------------------------------------------------------------------
// ����� �������� ������� � ����� �� ������� �� �������� ����� ������
// ������������ ��� ������ TravelItems, TravelFields, RemoveItems,
// RemoveFields, InsertItems, InsertFields
//--------------------------------------------------------------------------------
#define EDF_TRAVEL_FREESETEMPTY       1    // ���������� ������������� ������� ������� ��������
#define EDF_TRAVEL_FREESETZERO        2    // ���������� ������������� ������� �������� ����������
#define EDF_TRAVEL_WITHFIXED          4    // ����� ������ � �������������� ��������
#define EDF_TRAVEL_FREESETENPTYFIXED  8    // ���������� ������������� ������������� ����� ������� ��������
#define EDF_TRAVEL_WITHATRIBUTS       16   // ����� ������ �� ���������� ������� � �����
#define EDF_TRAVEL_FREEATRIBUTSREMOVE 32   // �������� ���� ������� � �������������� �������
#define EDF_TRAVEL_FREEFORMATREMOVE   64   // �������� ������� � �������������� ����� (���� ���������� ���������)
#define EDF_TRAVEL_WITHWIDTH          256  // ���������� ������� � ����������� �� ������
#define EDF_TRAVEL_ONLIINRANGE        512  // ������������ ������ ������ ���������� ���������
#define EDF_TRAVEL_STDFROMITEMS       1 | 4 | 8 | 16 | 32 | 256
#define EDF_TRAVEL_STDFROMFIELDS      1 | 4 | 8 | 16 | 32 | 64 | 256
//--------------------------------------------------------------------------------
// ����� ������� ������� ������� ����� CGridFieldProperty
//--------------------------------------------------------------------------------
#define EDF_GFP_Interval            1    // ���������� �������� Interval
#define EDF_GFP_Sign                2    // ���������� �������� Sign
#define EDF_GFP_NotShowSign         4    // ���������� �������� NotShowSign
#define EDF_GFP_FixedFields         8    // ���������� �������� FixedFields
#define EDF_GFP_FixedFirstField     16   // ���������� �������� FixedFirstField
#define EDF_GFP_FixedLastField      32   // ���������� �������� FixedLastField
#define EDF_GFP_NotInterval         64   // ������� ��������    Interval
#define EDF_GFP_NotSign             128  // ������� ��������    Sign
#define EDF_GFP_NotNotShowSign      256  // ������� ��������    NotShowSign
#define EDF_GFP_NotFixedFields      512  // ������� ��������    FixedFields
#define EDF_GFP_NotFixedFirstField  1024 // ������� ��������    FixedFirstField
#define EDF_GFP_NotFixedLastField   2048 // ������� ��������    FixedLastField
//--------------------------------------------------------------------------------
// ��������� ������������� ������� ������ ������
//--------------------------------------------------------------------------------
#define EDF_CLIPBOARD_EDIT_KEY  "Format EditBox  for Clipboard"
#define EDF_CLIPBOARD_GRID_KEY  "Format GridLine for Clipboard"
//--------------------------------------------------------------------------------
// �������������� ���������
//--------------------------------------------------------------------------------
// ��� CFormatEdit
#define WM_USER_EDF_FIRST             ( WM_USER_ + 500 )
// ���������� � ������������ ���� ��� ������������� ������ �� �������� (������ F5)
#define WM_USER_EDF_SELECTLIST        WM_USER_EDF_FIRST
// ���������� � ������������ ���� ��� ������������� ���������� ��������� ������ (������ F4)
#define WM_USER_EDF_VIEWDATA          ( WM_USER_EDF_FIRST + 1 )
// ���������� � ������������ ���� ��� ������������� ���������� ������ � Popup ����
#define WM_USER_EDF_UPDATE_SELECTLIST ( WM_USER_EDF_FIRST + 2 )
#define WM_USER_EDF_UPDATE_VIEWDATA   ( WM_USER_EDF_FIRST + 3 )
// ���������� ��� ��������� ��������� �������� � �������� ��������������
#define WM_USER_EDF_CHANGEVALUE       ( WM_USER_EDF_FIRST + 4 )
//
#define WM_USER_EDF_VALUETESTING      ( WM_USER_EDF_FIRST + 5 )
#define WM_USER_EDF_GRID_UPDATE_CW    ( WM_USER_EDF_FIRST + 6 )   // ������ ��� CB
//--------------------------------------------------------------------------------
// ��� CFormatGrid, CFormatList
//--------------------------------------------------------------------------------
// WPARAM WParam = MAKEWPARAM( Field, Item )  
// LPARAM LParam =( LPARAM )IDD_xxx 
// ���������� ��� ��������� ��������� �������� � ������� �������
#define WM_USER_EDF_GRID_CHANGEVALUE  ( WM_USER_EDF_FIRST + 10 )
#define WM_USER_EDF_CELLCHANGEVALUE   WM_USER_EDF_GRID_CHANGEVALUE
// ���������� ��� ������ �������������� ������
#define WM_USER_EDF_GRID_EDITSTART    ( WM_USER_EDF_FIRST + 11 )
#define WM_USER_EDF_CELLEDITSTART     WM_USER_EDF_GRID_EDITSTART
// ���������� ��� ���������� �������������� ������
#define WM_USER_EDF_GRID_EDITEND      ( WM_USER_EDF_FIRST + 12 )
#define WM_USER_EDF_CELLEDITEND       WM_USER_EDF_GRID_EDITEND
// ���������� ��� �������� ������� ������
#define WM_USER_EDF_GRID_SELCHANGE    ( WM_USER_EDF_FIRST + 13 )
#define WM_USER_EDF_CELLCHANGESEL     WM_USER_EDF_GRID_SELCHANGE
// ���������� ��� ����������� ��������� �� ����
// WPARAM WParam = &EdfMessage
// LPARAM LParam =( LPARAM )IDD_xxx
#define WM_USER_EDF_GRID_MOUSE        ( WM_USER_EDF_FIRST + 14 )
// ���������� ��� ����������� ��������� �� ����������
#define WM_USER_EDF_GRID_KEYS         ( WM_USER_EDF_FIRST + 15 )
// ���������� ��� ���������� ������
#define WM_USER_EDF_GRID_PAINT        ( WM_USER_EDF_FIRST + 16 )
// ���������� ��� click-� �� ������ ���� ��� �������� �������
#define WM_USER_EDF_GRID_BTN_CLICK    ( WM_USER_EDF_FIRST + 17 )
// ���� �������� ������ � ������ (CheckSelect-Type)
//  EdfMessage* M = ( EdfMessage )WParam ;
//	M->Message = WM_USER_EDF_GRID_CHECKITEM ;
//	M->wParam  = isCheck ;
//	M->lParam  = ( LPARAM )A->m_ID ;
//	M->Field   = 0 ;
//	M->Item    = Item ;
#define WM_USER_EDF_GRID_CHECKITEM    ( WM_USER_EDF_FIRST + 18 )
//--------------------------------------------------------------------------------
// �������������� �������� ������������ ����
#define WM_USER_EDF_COMMAND1          ( WM_USER_EDF_FIRST + 20 )
#define WM_USER_EDF_COMMAND2          ( WM_USER_EDF_FIRST + 21 )
#define WM_USER_EDF_COMMAND3          ( WM_USER_EDF_FIRST + 22 )
#define WM_USER_EDF_COMMAND4          ( WM_USER_EDF_FIRST + 23 )
#define WM_USER_EDF_COMMAND5          ( WM_USER_EDF_FIRST + 24 )
#define WM_USER_EDF_COMMAND6          ( WM_USER_EDF_FIRST + 25 )
#define WM_USER_EDF_COMMAND7          ( WM_USER_EDF_FIRST + 26 )
#define WM_USER_EDF_COMMAND8          ( WM_USER_EDF_FIRST + 27 )
#define WM_USER_EDF_COMMAND9          ( WM_USER_EDF_FIRST + 28 )
#define WM_USER_EDF_COMMAND10         ( WM_USER_EDF_FIRST + 29 )
#define WM_USER_EDF_COMMAND11         ( WM_USER_EDF_FIRST + 30 )
#define WM_USER_EDF_COMMAND12         ( WM_USER_EDF_FIRST + 31 )
#define WM_USER_EDF_COMMAND13         ( WM_USER_EDF_FIRST + 32 )
#define WM_USER_EDF_COMMAND14         ( WM_USER_EDF_FIRST + 33 )
#define WM_USER_EDF_COMMAND15         ( WM_USER_EDF_FIRST + 34 )
#define WM_USER_EDF_COMMAND16         ( WM_USER_EDF_FIRST + 35 )
#define WM_USER_EDF_COMMAND17         ( WM_USER_EDF_FIRST + 36 )
#define WM_USER_EDF_COMMAND18         ( WM_USER_EDF_FIRST + 37 )
#define WM_USER_EDF_COMMAND19         ( WM_USER_EDF_FIRST + 38 )
#define WM_USER_EDF_COMMAND20         ( WM_USER_EDF_FIRST + 39 )
#define WM_USER_EDF_COMMAND21         ( WM_USER_EDF_FIRST + 40 )
#define WM_USER_EDF_COMMAND22         ( WM_USER_EDF_FIRST + 41 )
#define WM_USER_EDF_COMMAND23         ( WM_USER_EDF_FIRST + 42 )
#define WM_USER_EDF_COMMAND24         ( WM_USER_EDF_FIRST + 43 )
#define WM_USER_EDF_COMMAND25         ( WM_USER_EDF_FIRST + 44 )
#define WM_USER_EDF_COMMAND26         ( WM_USER_EDF_FIRST + 45 )
#define WM_USER_EDF_COMMAND27         ( WM_USER_EDF_FIRST + 46 )
#define WM_USER_EDF_COMMAND28         ( WM_USER_EDF_FIRST + 47 )
#define WM_USER_EDF_COMMAND29         ( WM_USER_EDF_FIRST + 48 )
#define WM_USER_EDF_COMMAND30         ( WM_USER_EDF_FIRST + 49 )
//--------------------------------------------------------------------------------
// Update ��� �������������� ������� ������������ ����
#define WM_USER_EDF_UPDATE_COMMAND1   ( WM_USER_EDF_FIRST + 50 )
#define WM_USER_EDF_UPDATE_COMMAND2   ( WM_USER_EDF_FIRST + 51 )
#define WM_USER_EDF_UPDATE_COMMAND3   ( WM_USER_EDF_FIRST + 52 )
#define WM_USER_EDF_UPDATE_COMMAND4   ( WM_USER_EDF_FIRST + 53 )
#define WM_USER_EDF_UPDATE_COMMAND5   ( WM_USER_EDF_FIRST + 54 )
#define WM_USER_EDF_UPDATE_COMMAND6   ( WM_USER_EDF_FIRST + 55 )
#define WM_USER_EDF_UPDATE_COMMAND7   ( WM_USER_EDF_FIRST + 56 )
#define WM_USER_EDF_UPDATE_COMMAND8   ( WM_USER_EDF_FIRST + 57 )
#define WM_USER_EDF_UPDATE_COMMAND9   ( WM_USER_EDF_FIRST + 58 )
#define WM_USER_EDF_UPDATE_COMMAND10  ( WM_USER_EDF_FIRST + 59 )
#define WM_USER_EDF_UPDATE_COMMAND11  ( WM_USER_EDF_FIRST + 60 )
#define WM_USER_EDF_UPDATE_COMMAND12  ( WM_USER_EDF_FIRST + 61 )
#define WM_USER_EDF_UPDATE_COMMAND13  ( WM_USER_EDF_FIRST + 62 )
#define WM_USER_EDF_UPDATE_COMMAND14  ( WM_USER_EDF_FIRST + 63 )
#define WM_USER_EDF_UPDATE_COMMAND15  ( WM_USER_EDF_FIRST + 64 )
#define WM_USER_EDF_UPDATE_COMMAND16  ( WM_USER_EDF_FIRST + 65 )
#define WM_USER_EDF_UPDATE_COMMAND17  ( WM_USER_EDF_FIRST + 66 )
#define WM_USER_EDF_UPDATE_COMMAND18  ( WM_USER_EDF_FIRST + 67 )
#define WM_USER_EDF_UPDATE_COMMAND19  ( WM_USER_EDF_FIRST + 68 )
#define WM_USER_EDF_UPDATE_COMMAND20  ( WM_USER_EDF_FIRST + 69 )
#define WM_USER_EDF_UPDATE_COMMAND21  ( WM_USER_EDF_FIRST + 70 )
#define WM_USER_EDF_UPDATE_COMMAND22  ( WM_USER_EDF_FIRST + 71 )
#define WM_USER_EDF_UPDATE_COMMAND23  ( WM_USER_EDF_FIRST + 72 )
#define WM_USER_EDF_UPDATE_COMMAND24  ( WM_USER_EDF_FIRST + 73 )
#define WM_USER_EDF_UPDATE_COMMAND25  ( WM_USER_EDF_FIRST + 74 )
#define WM_USER_EDF_UPDATE_COMMAND26  ( WM_USER_EDF_FIRST + 75 )
#define WM_USER_EDF_UPDATE_COMMAND27  ( WM_USER_EDF_FIRST + 76 )
#define WM_USER_EDF_UPDATE_COMMAND28  ( WM_USER_EDF_FIRST + 77 )
#define WM_USER_EDF_UPDATE_COMMAND29  ( WM_USER_EDF_FIRST + 78 )
#define WM_USER_EDF_UPDATE_COMMAND30  ( WM_USER_EDF_FIRST + 79 )
//--------------------------------------------------------------------------------
// Base Popup menu
#define WM_EDF_GRID_FULL_SCREEN       ( WM_USER_EDF_FIRST + 80 )
#define WM_EDF_GRID_COPY              ( WM_USER_EDF_FIRST + 81 )
#define WM_EDF_GRID_CUT               ( WM_USER_EDF_FIRST + 82 )
#define WM_EDF_GRID_PASTE             ( WM_USER_EDF_FIRST + 83 )
#define WM_EDF_GRID_DELETE            ( WM_USER_EDF_FIRST + 84 )
//
#define WM_EDF_GRID_COPY_STR          ( WM_USER_EDF_FIRST + 85 )
#define WM_EDF_GRID_PASTE_STR         ( WM_USER_EDF_FIRST + 86 )
//
#define WM_EDF_GRID_LINE_CUT          ( WM_USER_EDF_FIRST + 87 )
#define WM_EDF_GRID_LINE_PASTE        ( WM_USER_EDF_FIRST + 88 )
#define WM_EDF_GRID_LINE_DELETE       ( WM_USER_EDF_FIRST + 89 )
//--------------------------------------------------------------------------------
#define WM_USER_EDF_GRID_FIRST        WM_USER_EDF_GRID_CHANGEVALUE
#define WM_USER_EDF_GRID_LAST         WM_EDF_GRID_LINE_DELETE     
#define WM_USER_EDF_LAST              WM_USER_EDF_GRID_LAST
//--------------------------------------------------------------------------------
#endif // NEFORMATDEF_H      AnsiString

