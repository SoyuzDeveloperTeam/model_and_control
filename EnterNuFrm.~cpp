
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "EnterNuFrm.h"
#include "simdata.h"
#include "dta.h"
#include "IniFiles.hpp"
#include "JouHeader.h"
#include "JouStrings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEnterNuForm *EnterNuForm;
AnsiString F;
byte reg2;
TIniFile *FNUfile;
//---------------------------------------------------------------------------
__fastcall TEnterNuForm::TEnterNuForm(TComponent* Owner)
        : TForm(Owner)
{
EnterNuForm->Position=poDesktopCenter;
}


void __fastcall TEnterNuForm::LoadFromFileBtnClick(TObject *Sender)
{
AnsiString NuFileName;
byte reg, sk_tk, sk_iss;
LoadNuFromFile->Title="Загрузка Начальных Условий из файла...";
LoadNuFromFile->InitialDir=ExtractFileDir(Application->ExeName)+"\\data";
//NuFileName = ExtractFileDir(Application->ExeName)+"\\data"+F;
if(LoadNuFromFile->Execute()){
//if(FileExists(LoadNuFromFile->FileName)) {
FNUfile = new TIniFile(LoadNuFromFile->FileName);
// TK
Jxx_tk->Text=FNUfile->ReadString("ComplexF_TK","Jxx","0");
Jyy_tk->Text=FNUfile->ReadString("ComplexF_TK","Jyy","0");
Jzz_tk->Text=FNUfile->ReadString("ComplexF_TK","Jzz","0");
Jxy_tk->Text=FNUfile->ReadString("ComplexF_TK","Jxy","0");
Jyz_tk->Text=FNUfile->ReadString("ComplexF_TK","Jyz","0");
Jzx_tk->Text=FNUfile->ReadString("ComplexF_TK","Jzx","0");
cm_x_tk->Text=FNUfile->ReadString("ComplexF_TK","cmx","0");
cm_y_tk->Text=FNUfile->ReadString("ComplexF_TK","cmy","0");
cm_z_tk->Text=FNUfile->ReadString("ComplexF_TK","cmz","0");
mass_tk->Text=FNUfile->ReadString("ComplexF_TK","mass","0");
tk_toplivo->Text=FNUfile->ReadString("ComplexF_TK","zapas","0");
b_pol_tk->Text = FNUfile->ReadString("OrbitalElementsF_TK","bpol","0");
e_tk->Text = FNUfile->ReadString("OrbitalElementsF_TK","e","0");
dol_v_tk->Text = FNUfile->ReadString("OrbitalElementsF_TK","dvu","0");
i_tk->Text = FNUfile->ReadString("OrbitalElementsF_TK","i","0");
arg_per_tk->Text = FNUfile->ReadString("OrbitalElementsF_TK","arp","0");
an_is_tk->Text = FNUfile->ReadString("OrbitalElementsF_TK","ian","0");
ball_coef_tk->Text = FNUfile->ReadString("OrbitalElementsF_TK","bcof","0");
tk_vel_x->Text = FNUfile->ReadString("OrbitalElementsF_TK","vx","0");
tk_vel_y->Text = FNUfile->ReadString("OrbitalElementsF_TK","vy","0");
tk_vel_z->Text = FNUfile->ReadString("OrbitalElementsF_TK","vz","0");
tk_pos_x->Text = FNUfile->ReadString("OrbitalElementsF_TK","x","0");
tk_pos_y->Text = FNUfile->ReadString("OrbitalElementsF_TK","y","0");
tk_pos_z->Text = FNUfile->ReadString("OrbitalElementsF_TK","z","0");
ang_psi_tk->Text = FNUfile->ReadString("Orient_TK","psi","0");
ang_thetta_tk->Text = FNUfile->ReadString("Orient_TK","the","0");
ang_gamma_tk->Text = FNUfile->ReadString("Orient_TK","gam","0");
w_x_tk->Text = FNUfile->ReadString("Orient_TK","wx","0");
w_y_tk->Text = FNUfile->ReadString("Orient_TK","wy","0");
w_z_tk->Text = FNUfile->ReadString("Orient_TK","wz","0");
sk_tk = StrToInt(FNUfile->ReadString("Orient_TK","sk","0"));
        if(sk_tk==1)sk_tk_tp->Checked=true; else
        if(sk_tk==2)sk_tk_osk->Checked=true;else
        if(sk_tk==3)sk_tk_vsk->Checked=true;
// ISS
Jxx_iss->Text=FNUfile->ReadString("ComplexF_ISS","Jxx","0");
Jyy_iss->Text=FNUfile->ReadString("ComplexF_ISS","Jyy","0");
Jzz_iss->Text=FNUfile->ReadString("ComplexF_ISS","Jzz","0");
Jxy_iss->Text=FNUfile->ReadString("ComplexF_ISS","Jxy","0");
Jyz_iss->Text=FNUfile->ReadString("ComplexF_ISS","Jyz","0");
Jzx_iss->Text=FNUfile->ReadString("ComplexF_ISS","Jzx","0");
cm_x_iss->Text=FNUfile->ReadString("ComplexF_ISS","cmx","0");
cm_y_iss->Text=FNUfile->ReadString("ComplexF_ISS","cmy","0");
cm_z_iss->Text=FNUfile->ReadString("ComplexF_ISS","cmz","0");
mass_iss->Text =      FNUfile->ReadString("ComplexF_ISS","mass","0");
b_pol_iss->Text =     FNUfile->ReadString("OrbitalElementsF_ISS","bpol","0");
e_iss->Text =         FNUfile->ReadString("OrbitalElementsF_ISS","e","0");
dol_v_iss->Text =     FNUfile->ReadString("OrbitalElementsF_ISS","dvu","0");
i_iss->Text =         FNUfile->ReadString("OrbitalElementsF_ISS","i","0");
arg_per_iss->Text =   FNUfile->ReadString("OrbitalElementsF_ISS","arp","0");
an_is_iss->Text =     FNUfile->ReadString("OrbitalElementsF_ISS","ian","0");
ball_koef_iss->Text = FNUfile->ReadString("OrbitalElementsF_ISS","bcof","0");
iss_vel_x->Text =     FNUfile->ReadString("OrbitalElementsF_ISS","vx","0");
iss_vel_y->Text =     FNUfile->ReadString("OrbitalElementsF_ISS","vy","0");
iss_vel_z->Text =     FNUfile->ReadString("OrbitalElementsF_ISS","vz","0");
iss_pos_x->Text =     FNUfile->ReadString("OrbitalElementsF_ISS","x","0");
iss_pos_y->Text =     FNUfile->ReadString("OrbitalElementsF_ISS","y","0");
iss_pos_z->Text =     FNUfile->ReadString("OrbitalElementsF_ISS","z","0");
ang_psi_iss->Text =   FNUfile->ReadString("Orient_ISS","psi","0");
ang_thetta_iss->Text = FNUfile->ReadString("Orient_ISS","the","0");
ang_gamma_iss->Text = FNUfile->ReadString("Orient_ISS","gam","0");
w_x_iss->Text =       FNUfile->ReadString("Orient_ISS","wx","0");
w_y_iss->Text =       FNUfile->ReadString("Orient_ISS","wy","0");
w_z_iss->Text =       FNUfile->ReadString("Orient_ISS","wz","0");
sk_iss = StrToInt(FNUfile->ReadString("Orient_ISS","sk","0"));
        if(sk_iss==1)sk_iss_tp->Checked=true; else
        if(sk_iss==2)sk_iss_osk->Checked=true;else
        if(sk_iss==3)sk_iss_vsk->Checked=true;
// MISC
FNUfile->ReadString("Orient_ISS","psi",ang_psi_iss->Text);
FNUfile->ReadString("Orient_ISS","the",ang_thetta_iss->Text);
FNUfile->ReadString("Orient_ISS","gam",ang_gamma_iss->Text);
FNUfile->ReadString("Orient_ISS","wx",w_x_iss->Text);
FNUfile->ReadString("Orient_ISS","wy",w_y_iss->Text);
w_z_iss->Text=FNUfile->ReadString("Orient_ISS","wz","0");
ro_init->Text=FNUfile->ReadString("Orient_MISC","Ro","0");
ro_dot_init->Text=FNUfile->ReadString("Orient_MISC","Ro_dot","0");
Edit61->Text=FNUfile->ReadString("Orient_MISC","alpha","0");
Edit62->Text=FNUfile->ReadString("Orient_MISC","betta","0");
Edit63->Text=FNUfile->ReadString("Orient_MISC","OmegaY","0");
Edit64->Text=FNUfile->ReadString("Orient_MISC","OmegaZ","0");
reg = StrToInt(FNUfile->ReadString("Orient_MISC","rgn","0"));
        if(reg==1)docking_pr->Checked=true; else
        if(reg==2)redock10_pr->Checked=true;else
        if(reg==3)avtsbl_pr->Checked=true;
        if(reg==4)rodk_pr->Checked=true;
        if(reg==5)roak_pr->Checked=true;
SetModelDatePicker->Date=FNUfile->ReadString("DateTime","Date","");
SetModelTimePicker->Time=StrToTime(FNUfile->ReadString("DateTime","Time","00:00:00"));
reg2 = StrToInt( FNUfile->ReadString("Other","Flight Mode","-1"));
if(reg2==0) reg_00->Checked; else
if(reg2==1) reg_00->Checked; else
if(reg2==2) reg_00->Checked; else
if(reg2==3) reg_00->Checked; else
if(reg2==4) reg_00->Checked; else
if(reg2==5) reg_00->Checked; 
FNUfile->Free();
JPS(1,"Загруженны НУ из файла.","","","");
}}
//---------------------------------------------------------------------------



void __fastcall TEnterNuForm::BitBtn1Click(TObject *Sender)
{
AnsiString NuFileName;
byte reg, sk_tk, sk_iss;
SaveNuToFile->InitialDir=ExtractFileDir(Application->ExeName)+"\\data";
if(SaveNuToFile->Execute()){
Label53->Caption=SaveNuToFile->FileName;
FNUfile = new TIniFile(SaveNuToFile->FileName);
////////
// TK //
//-----------------//
// Моменты инерции //
FNUfile->WriteString("ComplexF_TK","Jxx",Jxx_tk->Text);
FNUfile->WriteString("ComplexF_TK","Jyy",Jyy_tk->Text);
FNUfile->WriteString("ComplexF_TK","Jzz",Jzz_tk->Text);
FNUfile->WriteString("ComplexF_TK","Jxy",Jxy_tk->Text);
FNUfile->WriteString("ComplexF_TK","Jyz",Jyz_tk->Text);
FNUfile->WriteString("ComplexF_TK","Jzx",Jzx_tk->Text);
// Координаты Ц.М. //
FNUfile->WriteString("ComplexF_TK","cmx",cm_x_tk->Text);
FNUfile->WriteString("ComplexF_TK","cmy",cm_y_tk->Text);
FNUfile->WriteString("ComplexF_TK","cmz",cm_z_tk->Text);
FNUfile->WriteString("ComplexF_TK","mass",mass_tk->Text);              // Масса ТК
FNUfile->WriteString("ComplexF_TK","zapas",tk_toplivo->Text);          // Запас топлива ТК
// Орбитальные элементы ТК //
FNUfile->WriteString("OrbitalElementsF_TK","bpol",b_pol_tk->Text);
FNUfile->WriteString("OrbitalElementsF_TK","e",e_tk->Text);
FNUfile->WriteString("OrbitalElementsF_TK","dvu",dol_v_tk->Text);
FNUfile->WriteString("OrbitalElementsF_TK","i",i_tk->Text);
FNUfile->WriteString("OrbitalElementsF_TK","arp",arg_per_tk->Text);
FNUfile->WriteString("OrbitalElementsF_TK","ian",an_is_tk->Text);
FNUfile->WriteString("OrbitalElementsF_TK","bcof",ball_coef_tk->Text);
FNUfile->WriteString("OrbitalElementsF_TK","vx",tk_vel_x->Text);
FNUfile->WriteString("OrbitalElementsF_TK","vy",tk_vel_y->Text);
FNUfile->WriteString("OrbitalElementsF_TK","vz",tk_vel_z->Text);
FNUfile->WriteString("OrbitalElementsF_TK","x",tk_pos_x->Text);
FNUfile->WriteString("OrbitalElementsF_TK","y",tk_pos_y->Text);
FNUfile->WriteString("OrbitalElementsF_TK","z",tk_pos_z->Text);
// Ориентация ТК //
FNUfile->WriteString("Orient_TK","psi",ang_psi_tk->Text);
FNUfile->WriteString("Orient_TK","the",ang_thetta_tk->Text);
FNUfile->WriteString("Orient_TK","gam",ang_gamma_tk->Text);
FNUfile->WriteString("Orient_TK","wx",w_x_tk->Text);
FNUfile->WriteString("Orient_TK","wy",w_y_tk->Text);
FNUfile->WriteString("Orient_TK","wz",w_z_tk->Text);
if(sk_tk_tp->Checked) FNUfile->WriteString("Orient_TK","sk","1"); else
if(sk_tk_osk->Checked) FNUfile->WriteString("Orient_TK","sk","2"); else
if(sk_tk_vsk->Checked) FNUfile->WriteString("Orient_TK","sk","3");
// ISS
FNUfile->WriteString("ComplexF_ISS","Jxx",Jxx_iss->Text);
FNUfile->WriteString("ComplexF_ISS","Jyy",Jyy_iss->Text);
FNUfile->WriteString("ComplexF_ISS","Jzz",Jzz_iss->Text);
FNUfile->WriteString("ComplexF_ISS","Jxy",Jxy_iss->Text);
FNUfile->WriteString("ComplexF_ISS","Jyz",Jyz_iss->Text);
FNUfile->WriteString("ComplexF_ISS","Jzx",Jzx_iss->Text);
FNUfile->WriteString("ComplexF_ISS","cmx",cm_x_iss->Text);
FNUfile->WriteString("ComplexF_ISS","cmy",cm_y_iss->Text);
FNUfile->WriteString("ComplexF_ISS","cmz",cm_z_iss->Text);
FNUfile->WriteString("ComplexF_ISS","mass",mass_iss->Text);
FNUfile->WriteString("OrbitalElementsF_ISS","bpol",b_pol_iss->Text);
FNUfile->WriteString("OrbitalElementsF_ISS","e",e_iss->Text);
FNUfile->WriteString("OrbitalElementsF_ISS","dvu",dol_v_iss->Text);
FNUfile->WriteString("OrbitalElementsF_ISS","i",i_iss->Text);
FNUfile->WriteString("OrbitalElementsF_ISS","arp",arg_per_iss->Text);
FNUfile->WriteString("OrbitalElementsF_ISS","ian",an_is_iss->Text);
FNUfile->WriteString("OrbitalElementsF_ISS","bcof",ball_koef_iss->Text);
FNUfile->WriteString("OrbitalElementsF_ISS","vx",iss_vel_x->Text);
FNUfile->WriteString("OrbitalElementsF_ISS","vy",iss_vel_y->Text);
FNUfile->WriteString("OrbitalElementsF_ISS","vz",iss_vel_z->Text);
FNUfile->WriteString("OrbitalElementsF_ISS","x",iss_pos_x->Text);
FNUfile->WriteString("OrbitalElementsF_ISS","y",iss_pos_y->Text);
FNUfile->WriteString("OrbitalElementsF_ISS","z",iss_pos_z->Text);
FNUfile->WriteString("Orient_ISS","psi",ang_psi_iss->Text);
FNUfile->WriteString("Orient_ISS","the",ang_thetta_iss->Text);
FNUfile->WriteString("Orient_ISS","gam",ang_gamma_iss->Text);
FNUfile->WriteString("Orient_ISS","wx",w_x_iss->Text);
FNUfile->WriteString("Orient_ISS","wy",w_y_iss->Text);
FNUfile->WriteString("Orient_ISS","wz",w_z_iss->Text);
FNUfile->WriteString("Orient_MISC","Ro",ro_init->Text);
FNUfile->WriteString("Orient_MISC","Ro_dot",ro_dot_init->Text);
FNUfile->WriteString("Orient_MISC","alpha",Edit61->Text);
FNUfile->WriteString("Orient_MISC","betta",Edit62->Text);
FNUfile->WriteString("Orient_MISC","OmegaY",Edit63->Text);
FNUfile->WriteString("Orient_MISC","OmegaZ",Edit64->Text);
if(sk_iss_tp->Checked) FNUfile->WriteString("Orient_ISS","sk","1"); else
if(sk_iss_osk->Checked) FNUfile->WriteString("Orient_ISS","sk","2"); else
if(sk_iss_vsk->Checked) FNUfile->WriteString("Orient_ISS","sk","3");
//MISC
if(docking_pr->Checked)FNUfile->WriteString("Orient_MISC","rgn","1"); else
if(redock10_pr->Checked)FNUfile->WriteString("Orient_MISC","rgn","2"); else
if(avtsbl_pr->Checked)FNUfile->WriteString("Orient_MISC","rgn","3"); else
if(rodk_pr->Checked)FNUfile->WriteString("Orient_MISC","rgn","4"); else
if(roak_pr->Checked)FNUfile->WriteString("Orient_MISC","rgn","5");
FNUfile->WriteString("DateTime","Date",DateToStr(SetModelDatePicker->Date));
FNUfile->WriteString("DateTime","Time",TimeToStr(SetModelTimePicker->Time));
if(reg_00->Checked) FNUfile->WriteString("Other","Flight Mode","0"); else
if(reg_01->Checked) FNUfile->WriteString("Other","Flight Mode","1"); else
if(reg_02->Checked) FNUfile->WriteString("Other","Flight Mode","2"); else
if(reg_03->Checked) FNUfile->WriteString("Other","Flight Mode","3"); else
if(reg_04->Checked) FNUfile->WriteString("Other","Flight Mode","4"); else
if(reg_05->Checked) FNUfile->WriteString("Other","Flight Mode","5");
JPS(1,"НУ успешно сохранены.","","","");
}}
//---------------------------------------------------------------------------



