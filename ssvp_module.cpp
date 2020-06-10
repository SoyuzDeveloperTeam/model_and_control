//---------------------------------------------------------------------------
#ifndef SSVP
#define SSVP

#pragma hdrstop

#include "ssvp_module.h"
#include "USOData.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

bool ssvp_power () {
 if(ssvp_otstr) return false;
 else return true;
}

void doking_mode (void){

}

#endif
