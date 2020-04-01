//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "Ksp.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TKsp *)
{
        new TKsp(NULL);
}
//---------------------------------------------------------------------------
__fastcall TKsp::TKsp(TComponent* Owner)
        : TGraphicControl(Owner)
{
}
//---------------------------------------------------------------------------
namespace Ksp
{
        void __fastcall PACKAGE Register()
        {
                 TComponentClass classes[1] = {__classid(TKsp)};
                 RegisterComponents("Samples", classes, 0);
        }
}
//---------------------------------------------------------------------------
 