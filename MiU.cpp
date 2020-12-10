//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainFrm.cpp", MainForm);
USEFORM("ts_frm.cpp", ts_form);
USEFORM("bum_sett_frm.cpp", bum_settings);
USEFORM("toru_frm.cpp", toru_pult);
USEFORM("EnterNuFrm.cpp", EnterNuForm);
USEFORM("kdu_data.cpp", KDUform);
USEFORM("clock_form.cpp", clock_frm);
USEFORM("JouLogFrm.cpp", JouLogForm);
USEFORM("BkuCFrm.cpp", BkuC);
USEFORM("brvi_irvi\irvi_brfi_frm.cpp", IrBrForm);
USEFORM("KSPLForm.cpp", ksplfrm);
USEFORM("KSPPForm.cpp", KSP_right);
USEFORM("sepform.cpp", sep_form);
USEFORM("cdn_clock_frm.cpp", CDN_CLOCK);
USEFORM("graph_a1.cpp", graphics);
USEFORM("USOFrm.cpp", UsoForm);
USEFORM("bfi_formats.cpp", BFI_Simvol_form);
USEFORM("zakon_upr.cpp", zakon_upr_frm);
USEFORM("InstructorFormat_Form.cpp", InstructorFormat_FRM);
USEFORM("help_form.cpp", help_frm);
USEFORM("iss_per_tp.cpp", iss_t_tp);
USEFORM("vku_graph.cpp", vkugraph);
USEFORM("brus_form.cpp", brus_frm);
USEFORM("debug_bum_frm.cpp", bum_debug);
USEFORM("vived_frm.cpp", liftoff_form);
USEFORM("iss\sm_ssvp_PX.cpp", sm_ssvp_plx_frm);
USEFORM("argon\argon_debug_frm.cpp", arg_deb);
USEFORM("SOTR_frm.cpp", sotr);
USEFORM("trassa.cpp", trace);
USEFORM("AboutFrm.cpp", AboutForm);
USEFORM("otkazy.cpp", otkazy_frm);
USEFORM("inpudebugf.cpp", NeptDebug);
USEFORM("sps_frm.cpp", sps_form);
USEFORM("bilu_format.cpp", bilu_frm);
USEFORM("neptun\neptun.cpp", inpu_1);
USEFORM("ssvp_form.cpp", ssvp_frm);
USEFORM("CWFrm.cpp", cwform);
USEFORM("krl_form.cpp", krl_frm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "MIU";
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(Tts_form), &ts_form);
                 Application->CreateForm(__classid(Tbum_settings), &bum_settings);
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
                 Application->CreateForm(__classid(Ttrace), &trace);
                 Application->CreateForm(__classid(Tbrus_frm), &brus_frm);
                 Application->CreateForm(__classid(Totkazy_frm), &otkazy_frm);
                 Application->CreateForm(__classid(Tliftoff_form), &liftoff_form);
                 Application->CreateForm(__classid(Tsm_ssvp_plx_frm), &sm_ssvp_plx_frm);
                 Application->CreateForm(__classid(Targ_deb), &arg_deb);
                 Application->CreateForm(__classid(Tbum_debug), &bum_debug);
                 Application->CreateForm(__classid(Tinpu_1), &inpu_1);
                 Application->CreateForm(__classid(TNeptDebug), &NeptDebug);
                 Application->CreateForm(__classid(Tsps_form), &sps_form);
                 Application->CreateForm(__classid(Tbilu_frm), &bilu_frm);
                 Application->CreateForm(__classid(Tssvp_frm), &ssvp_frm);
                 Application->CreateForm(__classid(Tkrl_frm), &krl_frm);
                 Application->CreateForm(__classid(Tcwform), &cwform);
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
