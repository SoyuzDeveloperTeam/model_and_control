//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "neptun.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tinpu_1 *inpu_1;

static int inpu_x0, inpu_y0, inpu_xmax, inpu_ymax, ot_x, ot_y;
static int color1 = 0x006D8E;



//---------------------------------------------------------------------------
__fastcall Tinpu_1::Tinpu_1(TComponent* Owner)
        : TForm(Owner)
{
ot_x = 16;    // Отступ от левого верхнего края
ot_y = 16;
inpu_src->Left = 16;
inpu_src->Top = 16;
inpu_src->Width = 640;
inpu_src->Height = 480;
inpu_x0 = inpu_src->Left;
inpu_y0 = inpu_src->Top;
inpu_xmax = inpu_src->Width;
inpu_ymax = inpu_src->Height;
}
//---------------------------------------------------------------------------
void __fastcall Tinpu_1::FormCreate(TObject *Sender)
{
// Создаем фон //
TRect r; //Создаем структуру, типа TRect
r.Left=0; //Задаем левую границу области
r.right=640; //Задаем правую границу
r.Bottom=480; //Задаем нижнюю границу
r.Top=0; //Задаем верхнюю границу области 
nept_can->Canvas->Brush->Color=clBlack;    // Цвет заливки
nept_can->Canvas->FillRect(r);             // Заливка фона

nept_can->Canvas->Pen->Color=color1;       // Цвет контурных линий
nept_can->Canvas->Rectangle(0,0,640,480);  // Общий контур (по краям ИнПУ)
// Линии Приоритетной Зоны
nept_can->Canvas->MoveTo(0,56);
nept_can->Canvas->LineTo(640,56);
nept_can->Canvas->MoveTo(0,442);
nept_can->Canvas->LineTo(640,442);
nept_can->Canvas->MoveTo(0,28);
nept_can->Canvas->LineTo(158,28);
nept_can->Canvas->MoveTo(63,0);
nept_can->Canvas->LineTo(63,56);
nept_can->Canvas->MoveTo(158,0);
nept_can->Canvas->LineTo(158,56);
nept_can->Canvas->MoveTo(320,0);
nept_can->Canvas->LineTo(320,56);
nept_can->Canvas->MoveTo(473,0);
nept_can->Canvas->LineTo(473,56);
nept_can->Canvas->MoveTo(552,0);
nept_can->Canvas->LineTo(552,56);
nept_can->Canvas->MoveTo(158,40);
nept_can->Canvas->LineTo(320,40);
nept_can->Canvas->MoveTo(320,15);
nept_can->Canvas->LineTo(473,15);
nept_can->Canvas->MoveTo(302,40);
nept_can->Canvas->LineTo(302,56);
nept_can->Canvas->MoveTo(402,0);
nept_can->Canvas->LineTo(402,15);
nept_can->Canvas->MoveTo(473,28);
nept_can->Canvas->LineTo(640,28);
}
//---------------------------------------------------------------------------


