//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainFrm.cpp", MainForm);
USEFORM("forms\toru_frm.cpp", toru_pult);
USEFORM("forms\EnterNuFrm.cpp", EnterNuForm);
USEFORM("forms\kdu_data.cpp", KDUform);
USEFORM("forms\clock_form.cpp", clock_frm);
USEFORM("forms\JouLogFrm.cpp", JouLogForm);
USEFORM("forms\BkuCFrm.cpp", BkuC);
USEFORM("brvi_irvi\irvi_brfi_frm.cpp", IrBrForm);
USEFORM("forms\KSPLForm.cpp", ksplfrm);
USEFORM("forms\KSPPForm.cpp", KSP_right);
USEFORM("forms\sepform.cpp", sep_form);
USEFORM("forms\cdn_clock_frm.cpp", CDN_CLOCK);
USEFORM("forms\graph_a1.cpp", graphics);
USEFORM("forms\USOFrm.cpp", UsoForm);
USEFORM("forms\bfi_formats.cpp", BFI_Simvol_form);
USEFORM("forms\zakon_upr.cpp", zakon_upr_frm);
USEFORM("forms\InstructorFormat_Form.cpp", InstructorFormat_FRM);
USEFORM("forms\help_form.cpp", help_frm);
USEFORM("forms\iss_per_tp.cpp", iss_t_tp);
USEFORM("forms\vku_graph.cpp", vkugraph);
USEFORM("forms\brus_form.cpp", brus_frm);
USEFORM("forms\vived_frm.cpp", liftoff_form);
USEFORM("iss\sm_ssvp_PX.cpp", sm_ssvp_plx_frm);
USEFORM("argon\argon_debug_frm.cpp", arg_deb);
USEFORM("forms\SOTR_frm.cpp", sotr);
USEFORM("forms\AboutFrm.cpp", AboutForm);
USEFORM("forms\otkazy.cpp", otkazy_frm);
USEFORM("forms\inpudebugf.cpp", NeptDebug);
USEFORM("forms\sps_frm.cpp", sps_form);
USEFORM("forms\bilu_format.cpp", bilu_frm);
USEFORM("neptun\neptun.cpp", inpu_1);
USEFORM("forms\ssvp_form.cpp", ssvp_frm);
USEFORM("forms\CWFrm.cpp", cwform);
USEFORM("forms\krl_form.cpp", krl_frm);
USEFORM("forms\ts_frm.cpp", ts_form);
USEFORM("forms\mmTestF.cpp", MDTestForm);
USEFORM("forms\spgs_form.cpp", spgsfrm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "MIU";
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(Ttoru_pult), &toru_pult);
                 Application->CreateForm(__classid(TEnterNuForm), &EnterNuForm);
                 Application->CreateForm(__classid(TKDUform), &KDUform);
                 Application->CreateForm(__classid(Tclock_frm), &clock_frm);
                 Application->CreateForm(__classid(TBkuC), &BkuC);
                 Application->CreateForm(__classid(TIrBrForm), &IrBrForm);
                 Application->CreateForm(__classid(TAboutForm), &AboutForm);
                 Application->CreateForm(__classid(TJouLogForm), &JouLogForm);
                 Application->CreateForm(__classid(Tksplfrm), &ksplfrm);
                 Application->CreateForm(__classid(TUsoForm), &UsoForm);
                 Application->CreateForm(__classid(Tgraphics), &graphics);
                 Application->CreateForm(__classid(Tsep_form), &sep_form);
                 Application->CreateForm(__classid(TCDN_CLOCK), &CDN_CLOCK);
                 Application->CreateForm(__classid(Tsotr), &sotr);
                 Application->CreateForm(__classid(TKSP_right), &KSP_right);
                 Application->CreateForm(__classid(TBFI_Simvol_form), &BFI_Simvol_form);
                 Application->CreateForm(__classid(TInstructorFormat_FRM), &InstructorFormat_FRM);
                 Application->CreateForm(__classid(Tzakon_upr_frm), &zakon_upr_frm);
                 Application->CreateForm(__classid(Thelp_frm), &help_frm);
                 Application->CreateForm(__classid(Tvkugraph), &vkugraph);
                 Application->CreateForm(__classid(Tiss_t_tp), &iss_t_tp);
                 Application->CreateForm(__classid(Tbrus_frm), &brus_frm);
                 Application->CreateForm(__classid(Totkazy_frm), &otkazy_frm);
                 Application->CreateForm(__classid(Tliftoff_form), &liftoff_form);
                 Application->CreateForm(__classid(Tsm_ssvp_plx_frm), &sm_ssvp_plx_frm);
                 Application->CreateForm(__classid(Targ_deb), &arg_deb);
                 Application->CreateForm(__classid(Tinpu_1), &inpu_1);
                 Application->CreateForm(__classid(TNeptDebug), &NeptDebug);
                 Application->CreateForm(__classid(Tsps_form), &sps_form);
                 Application->CreateForm(__classid(Tbilu_frm), &bilu_frm);
                 Application->CreateForm(__classid(Tssvp_frm), &ssvp_frm);
                 Application->CreateForm(__classid(Tkrl_frm), &krl_frm);
                 Application->CreateForm(__classid(Tcwform), &cwform);
                 Application->CreateForm(__classid(Tts_form), &ts_form);
                 Application->CreateForm(__classid(TMDTestForm), &MDTestForm);
                 Application->CreateForm(__classid(Tspgsfrm), &spgsfrm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
