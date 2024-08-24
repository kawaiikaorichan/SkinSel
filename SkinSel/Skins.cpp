#include "pch.h"
#include "IniFile.hpp"
#include "SSDCtexlist.h"

//Macros
#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");
#define ReplaceTex(pvm, pvr, folder, folder2, pngname, gbix, x, y) helperFunctions.ReplaceTexture(pvm, pvr, (std::string(path) + "\\textures\\" folder "\\" folder2 "\\" pngname ".png").c_str(), gbix, x, y);

int SUPERSONICGlowtextures[] = { 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90 }; //Textures IDs

//Options
enum KindofTextureDX { LikeDream, OriginalDX, DreamcastT };
enum KindofTextureDC { OriginalDC, LikeDX, DXT };
enum KindofTextureGamma { OriginalG, Reworked };

static bool EnableSonic = true;
static bool EnableSSonic = true;
static bool EnableTails = true;
static bool EnableKnuckles = true;
static bool EnableAmy = true;
static bool EnableGamma = true;
static bool EnableBig = true;
static bool EnableMetal = true;
static bool EnableTikal = true;
static bool EnableEggman = true;
static bool Consistency = true;
static int KindofTextDX = OriginalDX;
static int KindofTextDC = OriginalDC;
static int KindofTextGamma = Reworked;

extern "C"
{
	__declspec(dllexport) __declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		HMODULE handle = GetModuleHandle(L"CHRMODELS_orig");
		NJS_OBJECT** ___SONIC_OBJECTS = (NJS_OBJECT**)GetProcAddress(handle, "___SONIC_OBJECTS");

		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");

		//Enabling or disabling HD textures
		EnableSonic = config->getBool("Characters", "EnableSonic", true);
		EnableSSonic = config->getBool("Characters", "EnableSSonic", true);
		EnableTails = config->getBool("Characters", "EnableTails", true);
		EnableKnuckles = config->getBool("Characters", "EnableKnuckles", true);
		EnableAmy = config->getBool("Characters", "EnableAmy", true);
		EnableGamma = config->getBool("Characters", "EnableGamma", true);
		EnableBig = config->getBool("Characters", "EnableBig", true);
		EnableMetal = config->getBool("Characters", "EnableMetal", true);
		EnableTikal = config->getBool("Characters", "EnableTikal", true);
		EnableEggman = config->getBool("Characters", "EnableEggman", true);
		Consistency = config->getBool("Misc", "Consistency", true);

		//Choosing kind of textures
		std::string KindofTextDX_String = "LikeDream";
		KindofTextDX_String = config->getString("Textures", "DXChars", "OriginalDX");
		std::string KindofTextDC_String = "OriginalDC";
		KindofTextDC_String = config->getString("Textures", "DreamcastChars", "OriginalDC");
		std::string KindofTextGamma_String = "Reworked";
		KindofTextGamma_String = config->getString("Textures", "Gamma", "Reworked");

		if (KindofTextDX_String == "LikeDream") KindofTextDX = LikeDream;
		if (KindofTextDX_String == "DreamcastT") KindofTextDX = DreamcastT;
		if (KindofTextDX_String == "OriginalDX") KindofTextDX = OriginalDX;
		if (KindofTextDC_String == "OriginalDC") KindofTextDC = OriginalDC;
		if (KindofTextDC_String == "LikeDX") KindofTextDC = LikeDX;
		if (KindofTextDC_String == "DXT") KindofTextDC = DXT;
		if (KindofTextGamma_String == "OriginalG") KindofTextGamma = OriginalG;
		if (KindofTextGamma_String == "Reworked") KindofTextGamma = Reworked;

		//Compatiblity with other mods
		HMODULE DCcharacters = GetModuleHandle(L"SA1_Chars");
		HMODULE DCconversion = GetModuleHandle(L"DCMods_Main");
		HMODULE DXcharsR = GetModuleHandle(L"SADXR");

		if (EnableSonic)
		{
			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("SONIC", "SONIC_ldx");
					ReplaceTex("ev_tr1_with_sonic", "stx_kanagu", "Sonic", "LDX", "stx_kanagu", 304702, 32, 32);
					ReplaceTex("ev_tr1_with_sonic", "stx_kutusoko0", "Sonic", "LDX", "stx_kutusoko0", 304703, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "stx_kutusoko1", "Sonic", "LDX", "stx_kutusoko1", 304704, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "stx_shoose4", "Sonic", "LDX", "stx_shoose4", 304705, 32, 32);
					ReplaceTex("ev_tr1_with_sonic", "stx_shoose6", "Sonic", "LDX", "stx_shoose6", 304706, 32, 32);
					ReplaceTex("ev_tr1_with_sonic", "s_soneye", "Sonic", "LDX", "stx_eye2", 304707, 16, 16);
					ReplaceTex("ev_tr1_with_sonic", "s_tr_sonblue", "Sonic", "LDX", "stx_btest1", 304741, 32, 32);
					ReplaceTex("ev_tr1_with_sonic", "s_tr_sonskin", "Sonic", "LDX", "stx_hada", 304743, 8, 8);
					ReplaceTex("ev_tr1_with_sonic", "s_tr_sonwhite", "Sonic", "LDX", "alltx_dwhite", 304744, 8, 8);
					ReplaceTex("ev_tr2before_with_sonic", "stx_kanagu", "Sonic", "LDX", "stx_kanagu", 304752, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "stx_kutusoko0", "Sonic", "LDX", "stx_kutusoko0", 304753, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_kutusoko1", "Sonic", "LDX", "stx_kutusoko1", 304754, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_shoose4", "Sonic", "LDX", "stx_shoose4", 304755, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "stx_shoose6", "Sonic", "LDX", "stx_shoose6", 304756, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_soneye", "Sonic", "LDX", "stx_eye2", 304758, 16, 16);
					ReplaceTex("ev_tr2before_with_sonic", "s_tr_sonblue", "Sonic", "LDX", "stx_btest1", 304786, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_tr_sonskin", "Sonic", "LDX", "stx_hada", 304788, 8, 8);
					ReplaceTex("ev_tr2before_with_sonic", "s_tr_sonwhite", "Sonic", "LDX", "alltx_dwhite", 304789, 8, 8);
					ReplaceTex("ev_tr2change_with_sonic", "stx_kanagu", "Sonic", "LDX", "stx_kanagu", 304902, 32, 32);
					ReplaceTex("ev_tr2change_with_sonic", "stx_kutusoko0", "Sonic", "LDX", "stx_kutusoko0", 304903, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "stx_kutusoko1", "Sonic", "LDX", "stx_kutusoko1", 304904, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "stx_shoose4", "Sonic", "LDX", "stx_shoose4", 304905, 32, 32);
					ReplaceTex("ev_tr2change_with_sonic", "stx_shoose6", "Sonic", "LDX", "stx_shoose6", 304906, 32, 32);
					ReplaceTex("ev_tr2change_with_sonic", "s_soneye", "Sonic", "LDX", "stx_eye2", 304908, 16, 16);
					ReplaceTex("ev_tr2change_with_sonic", "s_tr_sonblue", "Sonic", "LDX", "stx_btest1", 304935, 32, 32);
					ReplaceTex("ev_tr2change_with_sonic", "s_tr_sonskin", "Sonic", "LDX", "stx_hada", 304937, 8, 8);
					ReplaceTex("ev_tr2change_with_sonic", "s_tr_sonwhite", "Sonic", "LDX", "alltx_dwhite", 304938, 8, 8);
					ReplaceTex("shooting1", "stx_kanagu", "Sonic", "LDX", "stx_kanagu", 304187, 32, 32);
					ReplaceTex("shooting1", "stx_kutusoko0", "Sonic", "LDX", "stx_kutusoko0", 304188, 64, 64);
					ReplaceTex("shooting1", "stx_kutusoko1", "Sonic", "LDX", "stx_kutusoko1", 304189, 64, 64);
					ReplaceTex("shooting1", "stx_shoose4", "Sonic", "LDX", "stx_shoose4", 304190, 32, 32);
					ReplaceTex("shooting1", "stx_shoose6", "Sonic", "LDX", "stx_shoose6", 304191, 32, 32);
					ReplaceTex("shooting1", "s_soneye", "Sonic", "LDX", "stx_eye2", 304216, 16, 16);
					ReplaceTex("shooting1", "s_tr_sonblue", "Sonic", "LDX", "stx_btest1", 304300, 32, 32);
					ReplaceTex("shooting1", "s_tr_sonmimi", "Sonic", "LDX", "s_tr_sonmimi", 304302, 32, 32);
					ReplaceTex("shooting1", "s_tr_sonskin", "Sonic", "LDX", "stx_hada", 304304, 8, 8);
					ReplaceTex("shooting1", "s_tr_sonsoko", "Sonic", "LDX", "s_tr_sonsoko", 304305, 64, 64);
					ReplaceTex("shooting1", "s_tr_sonwhite", "Sonic", "LDX", "alltx_dwhite", 304306, 8, 8);
					ReplaceTex("shooting2", "stx_kanagu", "Sonic", "LDX", "stx_kanagu", 304187, 32, 32);
					ReplaceTex("shooting2", "stx_kutusoko0", "Sonic", "LDX", "stx_kutusoko0", 304188, 64, 64);
					ReplaceTex("shooting2", "stx_kutusoko1", "Sonic", "LDX", "stx_kutusoko1", 304189, 64, 64);
					ReplaceTex("shooting2", "stx_shoose4", "Sonic", "LDX", "stx_shoose4", 304190, 32, 32);
					ReplaceTex("shooting2", "stx_shoose6", "Sonic", "LDX", "stx_shoose6", 304191, 32, 32);
					ReplaceTex("shooting2", "s_soneye", "Sonic", "LDX", "stx_eye2", 304216, 16, 16);
					ReplaceTex("shooting2", "s_tr_sonblue", "Sonic", "LDX", "stx_btest1", 304300, 32, 32);
					ReplaceTex("shooting2", "s_tr_sonmimi", "Sonic", "LDX", "s_tr_sonmimi", 304302, 32, 32);
					ReplaceTex("shooting2", "s_tr_sonskin", "Sonic", "LDX", "stx_hada", 304304, 8, 8);
					ReplaceTex("shooting2", "s_tr_sonsoko", "Sonic", "LDX", "s_tr_sonsoko", 304305, 64, 64);
					ReplaceTex("shooting2", "s_tr_sonwhite", "Sonic", "LDX", "alltx_dwhite", 304306, 8, 8);
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("SONIC", "SONIC_DC");
				}

				if (KindofTextDC == DXT)
				{
					ReplacePVM("SONIC", "SONIC_DCwDX");
					ReplaceTex("ev_tr1_with_sonic", "stx_kanagu", "Sonic", "DCWDX", "stx_kanagu", 304702, 32, 32);
					ReplaceTex("ev_tr1_with_sonic", "stx_kutusoko0", "Sonic", "DCWDX", "stx_kutusoko0", 304703, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "stx_kutusoko1", "Sonic", "DCWDX", "stx_kutusoko1", 304704, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "stx_shoose4", "Sonic", "DCWDX", "stx_shoose4", 304705, 32, 32);
					ReplaceTex("ev_tr1_with_sonic", "stx_shoose6", "Sonic", "DCWDX", "stx_shoose6", 304706, 32, 32);
					ReplaceTex("ev_tr1_with_sonic", "s_soneye", "Sonic", "DCWDX", "stx_eye2", 304707, 16, 16);
					ReplaceTex("ev_tr1_with_sonic", "s_tr_sonblue", "Sonic", "DCWDX", "stx_btest1", 304741, 32, 32);
					ReplaceTex("ev_tr1_with_sonic", "s_tr_sonskin", "Sonic", "DCWDX", "stx_hada", 304743, 8, 8);
					ReplaceTex("ev_tr1_with_sonic", "s_tr_sonwhite", "Sonic", "DCWDX", "alltx_dwhite", 304744, 8, 8);
					ReplaceTex("ev_tr2before_with_sonic", "stx_kanagu", "Sonic", "DCWDX", "stx_kanagu", 304752, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "stx_kutusoko0", "Sonic", "DCWDX", "stx_kutusoko0", 304753, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_kutusoko1", "Sonic", "DCWDX", "stx_kutusoko1", 304754, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_shoose4", "Sonic", "DCWDX", "stx_shoose4", 304755, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "stx_shoose6", "Sonic", "DCWDX", "stx_shoose6", 304756, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_soneye", "Sonic", "DCWDX", "stx_eye2", 304758, 16, 16);
					ReplaceTex("ev_tr2before_with_sonic", "s_tr_sonblue", "Sonic", "DCWDX", "stx_btest1", 304786, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_tr_sonskin", "Sonic", "DCWDX", "stx_hada", 304788, 8, 8);
					ReplaceTex("ev_tr2before_with_sonic", "s_tr_sonwhite", "Sonic", "DCWDX", "alltx_dwhite", 304789, 8, 8);
					ReplaceTex("ev_tr2change_with_sonic", "stx_kanagu", "Sonic", "DCWDX", "stx_kanagu", 304902, 32, 32);
					ReplaceTex("ev_tr2change_with_sonic", "stx_kutusoko0", "Sonic", "DCWDX", "stx_kutusoko0", 304903, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "stx_kutusoko1", "Sonic", "DCWDX", "stx_kutusoko1", 304904, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "stx_shoose4", "Sonic", "DCWDX", "stx_shoose4", 304905, 32, 32);
					ReplaceTex("ev_tr2change_with_sonic", "stx_shoose6", "Sonic", "DCWDX", "stx_shoose6", 304906, 32, 32);
					ReplaceTex("ev_tr2change_with_sonic", "s_soneye", "Sonic", "DCWDX", "stx_eye2", 304908, 16, 16);
					ReplaceTex("ev_tr2change_with_sonic", "s_tr_sonblue", "Sonic", "DCWDX", "stx_btest1", 304935, 32, 32);
					ReplaceTex("ev_tr2change_with_sonic", "s_tr_sonskin", "Sonic", "DCWDX", "stx_hada", 304937, 8, 8);
					ReplaceTex("ev_tr2change_with_sonic", "s_tr_sonwhite", "Sonic", "DCWDX", "alltx_dwhite", 304938, 8, 8);
					ReplaceTex("shooting1", "stx_kanagu", "Sonic", "DCWDX", "stx_kanagu", 304187, 32, 32);
					ReplaceTex("shooting1", "stx_kutusoko0", "Sonic", "DCWDX", "stx_kutusoko0", 304188, 64, 64);
					ReplaceTex("shooting1", "stx_kutusoko1", "Sonic", "DCWDX", "stx_kutusoko1", 304189, 64, 64);
					ReplaceTex("shooting1", "stx_shoose4", "Sonic", "DCWDX", "stx_shoose4", 304190, 32, 32);
					ReplaceTex("shooting1", "stx_shoose6", "Sonic", "DCWDX", "stx_shoose6", 304191, 32, 32);
					ReplaceTex("shooting1", "s_soneye", "Sonic", "DCWDX", "stx_eye2", 304216, 16, 16);
					ReplaceTex("shooting1", "s_tr_sonblue", "Sonic", "DCWDX", "stx_btest1", 304300, 32, 32);
					ReplaceTex("shooting1", "s_tr_sonmimi", "Sonic", "DCWDX", "s_tr_sonmimi", 304302, 32, 32);
					ReplaceTex("shooting1", "s_tr_sonskin", "Sonic", "DCWDX", "stx_hada", 304304, 8, 8);
					ReplaceTex("shooting1", "s_tr_sonsoko", "Sonic", "DCWDX", "s_tr_sonsoko", 304305, 64, 64);
					ReplaceTex("shooting1", "s_tr_sonwhite", "Sonic", "DCWDX", "alltx_dwhite", 304306, 8, 8);
					ReplaceTex("shooting2", "stx_kanagu", "Sonic", "DCWDX", "stx_kanagu", 304187, 32, 32);
					ReplaceTex("shooting2", "stx_kutusoko0", "Sonic", "DCWDX", "stx_kutusoko0", 304188, 64, 64);
					ReplaceTex("shooting2", "stx_kutusoko1", "Sonic", "DCWDX", "stx_kutusoko1", 304189, 64, 64);
					ReplaceTex("shooting2", "stx_shoose4", "Sonic", "DCWDX", "stx_shoose4", 304190, 32, 32);
					ReplaceTex("shooting2", "stx_shoose6", "Sonic", "DCWDX", "stx_shoose6", 304191, 32, 32);
					ReplaceTex("shooting2", "s_soneye", "Sonic", "DCWDX", "stx_eye2", 304216, 16, 16);
					ReplaceTex("shooting2", "s_tr_sonblue", "Sonic", "DCWDX", "stx_btest1", 304300, 32, 32);
					ReplaceTex("shooting2", "s_tr_sonmimi", "Sonic", "DCWDX", "s_tr_sonmimi", 304302, 32, 32);
					ReplaceTex("shooting2", "s_tr_sonskin", "Sonic", "DCWDX", "stx_hada", 304304, 8, 8);
					ReplaceTex("shooting2", "s_tr_sonsoko", "Sonic", "DCWDX", "s_tr_sonsoko", 304305, 64, 64);
					ReplaceTex("shooting2", "s_tr_sonwhite", "Sonic", "DCWDX", "alltx_dwhite", 304306, 8, 8);
				}
			}
			else
			{
				___SONIC_OBJECTS[63]->basicdxmodel->mats[1].attrflags |= NJD_FLAG_USE_ENV | NJD_FLAG_IGNORE_LIGHT;

				if (KindofTextDX == LikeDream)
				{
					ReplacePVM("sonic", "sonic_ld");
					ReplaceTex("ev_tr1_with_sonic", "s_anakage1", "Sonic", "LD", "s_anakage1", 304705, 32, 32);
					ReplaceTex("ev_tr1_with_sonic", "s_hando2", "Sonic", "LD", "s_hando2", 304706, 32, 32);
					ReplaceTex("ev_tr1_with_sonic", "s_hando3", "Sonic", "LD", "s_hando3", 304707, 32, 32);
					ReplaceTex("ev_tr1_with_sonic", "s_testhand", "Sonic", "LD", "s_testhand", 304739, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "stx_btest1", "Sonic", "LD", "stx_btest1", 304742, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "stx_eye2", "Sonic", "LD", "stx_eye2", 304743, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "stx_hara", "Sonic", "LD", "stx_hara", 304744, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "stx_hoho", "Sonic", "LD", "stx_hoho", 304745, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "stx_kanagu", "Sonic", "LD", "stx_kanagu", 304746, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "ym_sjppse", "Sonic", "LD", "ym_sjppse", 304747, 128, 128);
					ReplaceTex("ev_tr2before_with_sonic", "s_anakage1", "Sonic", "LD", "s_anakage1", 304755, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_hando2", "Sonic", "LD", "s_hando2", 304757, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_hando3", "Sonic", "LD", "s_hando3", 304758, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_testhand", "Sonic", "LD", "s_testhand", 304784, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_btest1", "Sonic", "LD", "stx_btest1", 304787, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_eye2", "Sonic", "LD", "stx_eye2", 304788, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_hara", "Sonic", "LD", "stx_hara", 304789, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_hoho", "Sonic", "LD", "stx_hoho", 304790, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_kanagu", "Sonic", "LD", "stx_kanagu", 304791, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "ym_sjppse", "Sonic", "LD", "ym_sjppse", 304792, 128, 128);
					ReplaceTex("ev_tr2change_with_sonic", "s_anakage1", "Sonic", "LD", "s_anakage1", 5, 32, 32);
					ReplaceTex("ev_tr2change_with_sonic", "s_hando2", "Sonic", "LD", "s_hando2", 7, 32, 32);
					ReplaceTex("ev_tr2change_with_sonic", "s_hando3", "Sonic", "LD", "s_hando3", 8, 32, 32);
					ReplaceTex("ev_tr2change_with_sonic", "s_testhand", "Sonic", "LD", "s_testhand", 33, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "stx_btest1", "Sonic", "LD", "stx_btest1", 36, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "stx_eye2", "Sonic", "LD", "stx_eye2", 37, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "stx_hara", "Sonic", "LD", "stx_hara", 38, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "stx_hoho", "Sonic", "LD", "stx_hoho", 39, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "stx_kanagu", "Sonic", "LD", "stx_kanagu", 40, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "ym_sjppse", "Sonic", "LD", "ym_sjppse", 41, 128, 128);					
					ReplaceTex("ev_tr2before_with_sonic", "s_anakage1", "Sonic", "LD", "s_anakage1", 304755, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_hando2", "Sonic", "LD", "s_hando2", 304756, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_hando3", "Sonic", "LD", "s_hando3", 304757, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_testhand", "Sonic", "LD", "s_testhand", 304784, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_btest1", "Sonic", "LD", "stx_btest1", 304186, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_eye2", "Sonic", "LD", "stx_eye2", 304787, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_hara", "Sonic", "LD", "stx_hara", 304788, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_hoho", "Sonic", "LD", "stx_hoho", 304789, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "ym_sjppse", "Sonic", "LD", "ym_sjppse", 304791, 128, 128);

					if (DCconversion)
					{
						return;
					}

					else
					{
						ReplaceTex("shooting1", "stx_kanagu", "Sonic", "LD", "stx_kanagu", 304187, 32, 32);
						ReplaceTex("shooting1", "s_anakage1", "Sonic", "LD", "s_anakage1", 304705, 32, 32);
						ReplaceTex("shooting1", "s_hando2", "Sonic", "LD", "s_hando2", 304706, 32, 32);
						ReplaceTex("shooting1", "s_hando3", "Sonic", "LD", "s_hando3", 304707, 32, 32);
						ReplaceTex("shooting1", "s_testhand", "Sonic", "LD", "s_testhand", 304739, 64, 64);
						ReplaceTex("shooting1", "stx_btest1", "Sonic", "LD", "stx_btest1", 304742, 64, 64);
						ReplaceTex("shooting1", "stx_eye2", "Sonic", "LD", "stx_eye2", 304743, 64, 64);
						ReplaceTex("shooting1", "stx_hara", "Sonic", "LD", "stx_hara", 304744, 64, 64);
						ReplaceTex("shooting1", "stx_hoho", "Sonic", "LD", "stx_hoho", 304745, 64, 64);
						ReplaceTex("shooting1", "ym_sjppse", "Sonic", "LD", "ym_sjppse", 304747, 128, 128);
						ReplaceTex("shooting2", "stx_kanagu", "Sonic", "LD", "stx_kanagu", 304187, 32, 32);
						ReplaceTex("shooting2", "s_anakage1", "Sonic", "LD", "s_anakage1", 304755, 32, 32);
						ReplaceTex("shooting2", "s_hando2", "Sonic", "LD", "s_hando2", 304756, 32, 32);
						ReplaceTex("shooting2", "s_hando3", "Sonic", "LD", "s_hando3", 304757, 32, 32);
						ReplaceTex("shooting2", "s_testhand", "Sonic", "LD", "s_testhand", 304784, 64, 64);
						ReplaceTex("shooting2", "stx_btest1", "Sonic", "LD", "stx_btest1", 304186, 64, 64);
						ReplaceTex("shooting2", "stx_eye2", "Sonic", "LD", "stx_eye2", 304787, 64, 64);
						ReplaceTex("shooting2", "stx_hara", "Sonic", "LD", "stx_hara", 304788, 64, 64);
						ReplaceTex("shooting2", "stx_hoho", "Sonic", "LD", "stx_hoho", 304789, 64, 64);
						ReplaceTex("shooting2", "ym_sjppse", "Sonic", "LD", "ym_sjppse", 304791, 128, 128);
					}
				}

				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("SONIC", "SONIC_dxd");
					ReplaceTex("ev_tr1_with_sonic", "s_anakage1", "Sonic", "DXD", "s_anakage1", 304705, 32, 32);
					ReplaceTex("ev_tr1_with_sonic", "s_hando2", "Sonic", "DXD", "s_hando2", 304706, 32, 32);
					ReplaceTex("ev_tr1_with_sonic", "s_hando3", "Sonic", "DXD", "s_hando3", 304707, 32, 32);
					ReplaceTex("ev_tr1_with_sonic", "s_testhand", "Sonic", "DXD", "s_testhand", 304739, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "stx_btest1", "Sonic", "DXD", "stx_btest1", 304742, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "stx_eye2", "Sonic", "DXD", "stx_eye2", 304743, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "stx_hara", "Sonic", "DXD", "stx_hara", 304744, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "stx_hoho", "Sonic", "DXD", "stx_hoho", 304745, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "stx_kanagu", "Sonic", "DXD", "stx_kanagu", 304746, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "ym_sjppse", "Sonic", "DXD", "ym_sjppse", 304747, 128, 128);
					ReplaceTex("ev_tr2before_with_sonic", "s_anakage1", "Sonic", "DXD", "s_anakage1", 304755, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_hando2", "Sonic", "DXD", "s_hando2", 304757, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_hando3", "Sonic", "DXD", "s_hando3", 304758, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_testhand", "Sonic", "DXD", "s_testhand", 304784, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_btest1", "Sonic", "DXD", "stx_btest1", 304787, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_eye2", "Sonic", "DXD", "stx_eye2", 304788, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_hara", "Sonic", "DXD", "stx_hara", 304789, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_hoho", "Sonic", "DXD", "stx_hoho", 304790, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_kanagu", "Sonic", "DXD", "stx_kanagu", 304791, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "ym_sjppse", "Sonic", "DXD", "ym_sjppse", 304792, 128, 128);
					ReplaceTex("ev_tr2change_with_sonic", "s_anakage1", "Sonic", "DXD", "s_anakage1", 5, 32, 32);
					ReplaceTex("ev_tr2change_with_sonic", "s_hando2", "Sonic", "DXD", "s_hando2", 7, 32, 32);
					ReplaceTex("ev_tr2change_with_sonic", "s_hando3", "Sonic", "DXD", "s_hando3", 8, 32, 32);
					ReplaceTex("ev_tr2change_with_sonic", "s_testhand", "Sonic", "DXD", "s_testhand", 33, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "stx_btest1", "Sonic", "DXD", "stx_btest1", 36, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "stx_eye2", "Sonic", "DXD", "stx_eye2", 37, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "stx_hara", "Sonic", "DXD", "stx_hara", 38, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "stx_hoho", "Sonic", "DXD", "stx_hoho", 39, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "stx_kanagu", "Sonic", "DXD", "stx_kanagu", 40, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "ym_sjppse", "Sonic", "DXD", "ym_sjppse", 41, 128, 128);					
					ReplaceTex("ev_tr2before_with_sonic", "s_anakage1", "Sonic", "DXD", "s_anakage1", 304755, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_hando2", "Sonic", "DXD", "s_hando2", 304756, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_hando3", "Sonic", "DXD", "s_hando3", 304757, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_testhand", "Sonic", "DXD", "s_testhand", 304784, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_btest1", "Sonic", "DXD", "stx_btest1", 304186, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_eye2", "Sonic", "DXD", "stx_eye2", 304787, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_hara", "Sonic", "DXD", "stx_hara", 304788, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "stx_hoho", "Sonic", "DXD", "stx_hoho", 304789, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "ym_sjppse", "Sonic", "DXD", "ym_sjppse", 304791, 128, 128);

					if (DCconversion)
					{
						return;
					}

					else
					{
						ReplaceTex("shooting1", "stx_kanagu", "Sonic", "DXD", "stx_kanagu", 304187, 32, 32);
						ReplaceTex("shooting1", "s_anakage1", "Sonic", "DXD", "s_anakage1", 304705, 32, 32);
						ReplaceTex("shooting1", "s_hando2", "Sonic", "DXD", "s_hando2", 304706, 32, 32);
						ReplaceTex("shooting1", "s_hando3", "Sonic", "DXD", "s_hando3", 304707, 32, 32);
						ReplaceTex("shooting1", "s_testhand", "Sonic", "DXD", "s_testhand", 304739, 64, 64);
						ReplaceTex("shooting1", "stx_btest1", "Sonic", "DXD", "stx_btest1", 304742, 64, 64);
						ReplaceTex("shooting1", "stx_eye2", "Sonic", "DXD", "stx_eye2", 304743, 64, 64);
						ReplaceTex("shooting1", "stx_hara", "Sonic", "DXD", "stx_hara", 304744, 64, 64);
						ReplaceTex("shooting1", "stx_hoho", "Sonic", "DXD", "stx_hoho", 304745, 64, 64);
						ReplaceTex("shooting1", "ym_sjppse", "Sonic", "DXD", "ym_sjppse", 304747, 128, 128);						
						ReplaceTex("shooting2", "stx_kanagu", "Sonic", "DXD", "stx_kanagu", 304187, 32, 32);
						ReplaceTex("shooting2", "s_anakage1", "Sonic", "DXD", "s_anakage1", 304755, 32, 32);
						ReplaceTex("shooting2", "s_hando2", "Sonic", "DXD", "s_hando2", 304756, 32, 32);
						ReplaceTex("shooting2", "s_hando3", "Sonic", "DXD", "s_hando3", 304757, 32, 32);
						ReplaceTex("shooting2", "s_testhand", "Sonic", "DXD", "s_testhand", 304784, 64, 64);
						ReplaceTex("shooting2", "stx_btest1", "Sonic", "DXD", "stx_btest1", 304186, 64, 64);
						ReplaceTex("shooting2", "stx_eye2", "Sonic", "DXD", "stx_eye2", 304787, 64, 64);
						ReplaceTex("shooting2", "stx_hara", "Sonic", "DXD", "stx_hara", 304788, 64, 64);
						ReplaceTex("shooting2", "stx_hoho", "Sonic", "DXD", "stx_hoho", 304789, 64, 64);
						ReplaceTex("shooting2", "ym_sjppse", "Sonic", "DXD", "ym_sjppse", 304791, 128, 128);
					}
				}

				if (KindofTextDX == OriginalDX)
				{
					ReplacePVM("sonic", "sonic_dx");

					if (DCconversion)
					{
						ReplaceTex("shooting1", "stx_kanagu", "Sonic", "DCWDX", "stx_kanagu", 304187, 32, 32);
						ReplaceTex("shooting1", "stx_kutusoko0", "Sonic", "DCWDX", "stx_kutusoko0", 304188, 64, 64);
						ReplaceTex("shooting1", "stx_kutusoko1", "Sonic", "DCWDX", "stx_kutusoko1", 304189, 64, 64);
						ReplaceTex("shooting1", "stx_shoose4", "Sonic", "DCWDX", "stx_shoose4", 304190, 32, 32);
						ReplaceTex("shooting1", "stx_shoose6", "Sonic", "DCWDX", "stx_shoose6", 304191, 32, 32);
						ReplaceTex("shooting1", "s_soneye", "Sonic", "DCWDX", "stx_eye2", 304216, 16, 16);
						ReplaceTex("shooting1", "s_tr_sonblue", "Sonic", "DCWDX", "stx_btest1", 304300, 32, 32);
						ReplaceTex("shooting1", "s_tr_sonmimi", "Sonic", "DCWDX", "s_tr_sonmimi", 304302, 32, 32);
						ReplaceTex("shooting1", "s_tr_sonskin", "Sonic", "DCWDX", "stx_hada", 304304, 8, 8);
						ReplaceTex("shooting1", "s_tr_sonsoko", "Sonic", "DCWDX", "s_tr_sonsoko", 304305, 64, 64);
						ReplaceTex("shooting1", "s_tr_sonwhite", "Sonic", "DCWDX", "alltx_dwhite", 304306, 8, 8);
						ReplaceTex("shooting2", "stx_kanagu", "Sonic", "DCWDX", "stx_kanagu", 304187, 32, 32);
						ReplaceTex("shooting2", "stx_kutusoko0", "Sonic", "DCWDX", "stx_kutusoko0", 304188, 64, 64);
						ReplaceTex("shooting2", "stx_kutusoko1", "Sonic", "DCWDX", "stx_kutusoko1", 304189, 64, 64);
						ReplaceTex("shooting2", "stx_shoose4", "Sonic", "DCWDX", "stx_shoose4", 304190, 32, 32);
						ReplaceTex("shooting2", "stx_shoose6", "Sonic", "DCWDX", "stx_shoose6", 304191, 32, 32);
						ReplaceTex("shooting2", "s_soneye", "Sonic", "DCWDX", "stx_eye2", 304216, 16, 16);
						ReplaceTex("shooting2", "s_tr_sonblue", "Sonic", "DCWDX", "stx_btest1", 304300, 32, 32);
						ReplaceTex("shooting2", "s_tr_sonmimi", "Sonic", "DCWDX", "s_tr_sonmimi", 304302, 32, 32);
						ReplaceTex("shooting2", "s_tr_sonskin", "Sonic", "DCWDX", "stx_hada", 304304, 8, 8);
						ReplaceTex("shooting2", "s_tr_sonsoko", "Sonic", "DCWDX", "s_tr_sonsoko", 304305, 64, 64);
						ReplaceTex("shooting2", "s_tr_sonwhite", "Sonic", "DCWDX", "alltx_dwhite", 304306, 8, 8);
					}

					else
					{
						return;
					}
				}
			}
		}

		if (EnableSSonic)
		{
			WriteData((NJS_TEXLIST**)0x55E65C, SSAura01);
			WriteData((NJS_TEXLIST**)0x55E751, SSAura01);
			WriteData((NJS_TEXLIST**)0x55E712, SSAura02);
			WriteData((NJS_TEXLIST**)0x55E7CD, SSWaterThing);
			WriteData((NJS_TEXLIST**)0x55F2B3, SSHomingTex1);
			WriteData((NJS_TEXLIST**)0x55F1D1, SSHomingTex1);
			WriteData((NJS_TEXLIST**)0x55F1DC, SSHomingTex2);
			WriteData((NJS_TEXLIST**)0x55F2BE, SSHomingTex2);
			WriteData((NJS_TEXLIST**)0x55F677, SSHomingTex2);
			WriteData((NJS_TEXLIST**)0x55F669, SSHomingTex3);
			SUPERSONIC_TEXLIST = SS_PVM;

			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("SUPERSONIC", "supersonic_ldx");
					ReplacePVM("supersonic_dc_a", "supersonic_ldx");
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("SUPERSONIC", "supersonic_dc");
					ReplacePVM("supersonic_dc_a", "supersonic_dc");
				}

				if (KindofTextDC == DXT)
				{
					ReplacePVM("SUPERSONIC", "supersonic_dcwdx");
					ReplacePVM("supersonic_dc_a", "supersonic_dcwdx");
				}
			}
			else
			{
				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("supersonic", "supersonic_dxd");
				}

				if (KindofTextDX == LikeDream)
				{
					ReplacePVM("supersonic", "supersonic_ld");
				}

				if (KindofTextDX == OriginalDX)
				{
					ReplacePVM("supersonic", "supersonic_dx");
				}
			}
		}

		if (EnableTails)
		{
			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("Miles", "Miles_ldx");
					ReplaceTex("ev_tr1_with_sonic", "s_tileye", "Tails", "LDX", "mtx_eye3", 304740, 16, 16);
					ReplaceTex("ev_tr1_with_sonic", "s_tr_tailorge", "Tails", "LDX", "mtx_yellow0", 304745, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_tileye", "Tails", "LDX", "mtx_eye3", 304785, 16, 16);
					ReplaceTex("ev_tr2before_with_sonic", "s_tr_tailorge", "Tails", "LDX", "mtx_yellow0", 304790, 32, 32);
					ReplaceTex("ev_tr2change_with_sonic", "s_tileye", "Tails", "LDX", "mtx_eye3", 304934, 16, 16);
					ReplaceTex("ev_tr2change_with_sonic", "s_tr_tailorge", "Tails", "LDX", "mtx_yellow0", 304939, 32, 32);
					ReplaceTex("m_head_1", "mtx_white", "Tails", "LDX", "mtx_white", 600414, 8, 8);
					ReplaceTex("m_head_1", "mtx_yellow0", "Tails", "LDX", "mtx_yellow0", 600415, 64, 64);
					ReplaceTex("m_tr_p_", "mtx_eye3", "Tails", "LDX", "mtx_eye3", 600411, 16, 16);
					ReplaceTex("m_tr_p_", "mtx_ring", "Tails", "LDX", "mtx_ring", 600412, 32, 32);
					ReplaceTex("m_tr_p_", "mtx_shitahara", "Tails", "LDX", "mtx_shitahara", 600413, 32, 32);
					ReplaceTex("m_tr_p_", "mtx_white", "Tails", "LDX", "mtx_white", 600414, 8, 8);
					ReplaceTex("m_tr_p_", "mtx_yellow0", "Tails", "LDX", "mtx_yellow0", 600415, 64, 64);
					ReplaceTex("m_tr_p_", "s_anakage", "Tails", "LDX", "s_anakage", 600416, 32, 32);
					ReplaceTex("m_tr_p_", "s_hando2", "Tails", "LDX", "s_hando2", 600417, 32, 32);
					ReplaceTex("m_tr_p_", "s_testhand", "Tails", "LDX", "s_testhand", 600445, 64, 64);					
					ReplaceTex("shooting1", "s_t1_m_eye", "Tails", "LDX", "s_t1_m_eye", 304244, 64, 64);
					ReplaceTex("shooting1", "s_t1_m_mune", "Tails", "LDX", "s_t1_m_mune", 304245, 64, 64);
					ReplaceTex("shooting1", "s_tileye", "Tails", "LDX", "mtx_eye3", 304299, 16, 16);
					ReplaceTex("shooting1", "s_tr_tailmimi", "Tails", "LDX", "s_tr_tailmimi", 304307, 32, 32);
					ReplaceTex("shooting1", "s_tr_tailorge", "Tails", "LDX", "mtx_yellow0", 304308, 32, 32);
					ReplaceTex("shooting2", "s_t1_m_eye", "Tails", "LDX", "s_t1_m_eye", 304244, 64, 64);
					ReplaceTex("shooting2", "s_t1_m_mune", "Tails", "LDX", "s_t1_m_mune", 304245, 64, 64);
					ReplaceTex("shooting2", "s_tileye", "Tails", "LDX", "mtx_eye3", 304299, 16, 16);
					ReplaceTex("shooting2", "s_tr_tailmimi", "Tails", "LDX", "s_tr_tailmimi", 304307, 32, 32);
					ReplaceTex("shooting2", "s_tr_tailorge", "Tails", "LDX", "mtx_yellow0", 304308, 32, 32);
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("Miles", "Miles_DC");
				}

				if (KindofTextDC == DXT)
				{
					ReplacePVM("Miles", "Miles_DCWDX");
					ReplaceTex("ev_tr1_with_sonic", "s_tileye", "Tails", "DCWDX", "mtx_eye3", 304740, 16, 16);
					ReplaceTex("ev_tr1_with_sonic", "s_tr_tailorge", "Tails", "DCWDX", "mtx_yellow0", 304745, 32, 32);
					ReplaceTex("ev_tr2before_with_sonic", "s_tileye", "Tails", "DCWDX", "mtx_eye3", 304785, 16, 16);
					ReplaceTex("ev_tr2before_with_sonic", "s_tr_tailorge", "Tails", "DCWDX", "mtx_yellow0", 304790, 32, 32);
					ReplaceTex("ev_tr2change_with_sonic", "s_tileye", "Tails", "DCWDX", "mtx_eye3", 304934, 16, 16);
					ReplaceTex("ev_tr2change_with_sonic", "s_tr_tailorge", "Tails", "DCWDX", "mtx_yellow0", 304939, 32, 32);
					ReplaceTex("m_head_1", "mtx_white", "Tails", "DCWDX", "mtx_white", 600414, 8, 8);
					ReplaceTex("m_head_1", "mtx_yellow0", "Tails", "DCWDX", "mtx_yellow0", 600415, 64, 64);
					ReplaceTex("m_tr_p_", "mtx_eye3", "Tails", "DCWDX", "mtx_eye3", 600411, 16, 16);
					ReplaceTex("m_tr_p_", "mtx_ring", "Tails", "DCWDX", "mtx_ring", 600412, 32, 32);
					ReplaceTex("m_tr_p_", "mtx_shitahara", "Tails", "DCWDX", "mtx_shitahara", 600413, 32, 32);
					ReplaceTex("m_tr_p_", "mtx_white", "Tails", "DCWDX", "mtx_white", 600414, 8, 8);
					ReplaceTex("m_tr_p_", "mtx_yellow0", "Tails", "DCWDX", "mtx_yellow0", 600415, 64, 64);
					ReplaceTex("m_tr_p_", "s_anakage", "Tails", "DCWDX", "s_anakage", 600416, 32, 32);
					ReplaceTex("m_tr_p_", "s_hando2", "Tails", "DCWDX", "s_hando2", 600417, 32, 32);
					ReplaceTex("m_tr_p_", "s_testhand", "Tails", "DCWDX", "s_testhand", 600445, 64, 64);
					ReplaceTex("shooting1", "s_t1_m_eye", "Tails", "DCWDX", "s_t1_m_eye", 304244, 64, 64);
					ReplaceTex("shooting1", "s_t1_m_mune", "Tails", "DCWDX", "s_t1_m_mune", 304245, 64, 64);
					ReplaceTex("shooting1", "s_tileye", "Tails", "DCWDX", "mtx_eye3", 304299, 16, 16);
					ReplaceTex("shooting1", "s_tr_tailmimi", "Tails", "DCWDX", "s_tr_tailmimi", 304307, 32, 32);
					ReplaceTex("shooting1", "s_tr_tailorge", "Tails", "DCWDX", "mtx_yellow0", 304308, 32, 32);
					ReplaceTex("shooting2", "s_t1_m_eye", "Tails", "DCWDX", "s_t1_m_eye", 304244, 64, 64);
					ReplaceTex("shooting2", "s_t1_m_mune", "Tails", "DCWDX", "s_t1_m_mune", 304245, 64, 64);
					ReplaceTex("shooting2", "s_tileye", "Tails", "DCWDX", "mtx_eye3", 304299, 16, 16);
					ReplaceTex("shooting2", "s_tr_tailmimi", "Tails", "DCWDX", "s_tr_tailmimi", 304307, 32, 32);
					ReplaceTex("shooting2", "s_tr_tailorge", "Tails", "DCWDX", "mtx_yellow0", 304308, 32, 32);
				}
			}
			else
			{
				if (KindofTextDX == LikeDream)
				{
					ReplacePVM("Miles", "Miles_ld");
					ReplaceTex("ev_tr1_with_sonic", "mtx_body01", "Tails", "LD", "mtx_body01", 304700, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "mtx_eye", "Tails", "LD", "mtx_eye", 304701, 16, 16);
					ReplaceTex("ev_tr1_with_sonic", "mtx_hand01", "Tails", "LD", "mtx_hand01", 304702, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "mtx_head01", "Tails", "LD", "mtx_head01", 304703, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "mtx_white", "Tails", "LD", "mtx_white", 304704, 8, 8);
					ReplaceTex("ev_tr2before_with_sonic", "mtx_body01", "Tails", "LD", "mtx_body01", 304750, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "mtx_eye", "Tails", "LD", "mtx_eye", 304751, 16, 16);
					ReplaceTex("ev_tr2before_with_sonic", "mtx_hand01", "Tails", "LD", "mtx_hand01", 304752, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "mtx_head01", "Tails", "LD", "mtx_head01", 304753, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "mtx_white", "Tails", "LD", "mtx_white", 304754, 8, 8);
					ReplaceTex("ev_tr2change_with_sonic", "mtx_body01", "Tails", "LD", "mtx_body01", 0, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "mtx_eye", "Tails", "LD", "mtx_eye", 1, 16, 16);
					ReplaceTex("ev_tr2change_with_sonic", "mtx_hand01", "Tails", "LD", "mtx_hand01", 2, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "mtx_head01", "Tails", "LD", "mtx_head01", 3, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "mtx_white", "Tails", "LD", "mtx_white", 4, 8, 8);
					ReplaceTex("m_head_1", "mtx_hand01", "Tails", "LD", "mtx_hand01", 9050100, 64, 64);
					ReplaceTex("m_head_1", "mtx_head01", "Tails", "LD", "mtx_head01", 9050101, 64, 64);
					ReplaceTex("m_head_1", "mtx_white", "Tails", "LD", "mtx_white", 9050104, 8, 8);
					ReplaceTex("m_tr_p", "mtx_body01", "Tails", "LD", "mtx_body01", 9050000, 64, 64);
					ReplaceTex("m_tr_p", "mtx_eye", "Tails", "LD", "mtx_eye", 9050001, 16, 16);
					ReplaceTex("m_tr_p", "mtx_hand01", "Tails", "LD", "mtx_hand01", 9050002, 64, 64);
					ReplaceTex("shooting1", "mtx_body01", "Tails", "LD", "mtx_body01", 304700, 64, 64);
					ReplaceTex("shooting1", "mtx_eye", "Tails", "LD", "mtx_eye", 304701, 16, 16);
					ReplaceTex("shooting1", "mtx_hand01", "Tails", "LD", "mtx_hand01", 304702, 64, 64);
					ReplaceTex("shooting1", "mtx_head01", "Tails", "LD", "mtx_head01", 304703, 64, 64);
					ReplaceTex("shooting1", "mtx_white", "Tails", "LD", "mtx_white", 304704, 8, 8);
					ReplaceTex("shooting2", "mtx_body01", "Tails", "LD", "mtx_body01", 304750, 64, 64);
					ReplaceTex("shooting2", "mtx_eye", "Tails", "LD", "mtx_eye", 304751, 16, 16);
					ReplaceTex("shooting2", "mtx_hand01", "Tails", "LD", "mtx_hand01", 304752, 64, 64);
					ReplaceTex("shooting2", "mtx_head01", "Tails", "LD", "mtx_head01", 304753, 64, 64);
					ReplaceTex("shooting2", "mtx_white", "Tails", "LD", "mtx_white", 304754, 8, 8);
				}

				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("Miles", "Miles_dxd");
					ReplaceTex("ev_tr1_with_sonic", "mtx_body01", "Tails", "DXD", "mtx_body01", 304700, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "mtx_eye", "Tails", "DXD", "mtx_eye", 304701, 16, 16);
					ReplaceTex("ev_tr1_with_sonic", "mtx_hand01", "Tails", "DXD", "mtx_hand01", 304702, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "mtx_head01", "Tails", "DXD", "mtx_head01", 304703, 64, 64);
					ReplaceTex("ev_tr1_with_sonic", "mtx_white", "Tails", "DXD", "mtx_white", 304704, 8, 8);
					ReplaceTex("ev_tr2before_with_sonic", "mtx_body01", "Tails", "DXD", "mtx_body01", 304750, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "mtx_eye", "Tails", "DXD", "mtx_eye", 304751, 16, 16);
					ReplaceTex("ev_tr2before_with_sonic", "mtx_hand01", "Tails", "DXD", "mtx_hand01", 304752, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "mtx_head01", "Tails", "DXD", "mtx_head01", 304753, 64, 64);
					ReplaceTex("ev_tr2before_with_sonic", "mtx_white", "Tails", "DXD", "mtx_white", 304754, 8, 8);
					ReplaceTex("ev_tr2change_with_sonic", "mtx_body01", "Tails", "DXD", "mtx_body01", 0, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "mtx_eye", "Tails", "DXD", "mtx_eye", 1, 16, 16);
					ReplaceTex("ev_tr2change_with_sonic", "mtx_hand01", "Tails", "DXD", "mtx_hand01", 2, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "mtx_head01", "Tails", "DXD", "mtx_head01", 3, 64, 64);
					ReplaceTex("ev_tr2change_with_sonic", "mtx_white", "Tails", "DXD", "mtx_white", 4, 8, 8);
					ReplaceTex("m_head_1", "mtx_hand01", "Tails", "DXD", "mtx_hand01", 9050100, 64, 64);
					ReplaceTex("m_head_1", "mtx_head01", "Tails", "DXD", "mtx_head01", 9050101, 64, 64);
					ReplaceTex("m_head_1", "mtx_white", "Tails", "DXD", "mtx_white", 9050104, 8, 8);
					ReplaceTex("m_tr_p", "mtx_body01", "Tails", "DXD", "mtx_body01", 9050000, 64, 64);
					ReplaceTex("m_tr_p", "mtx_eye", "Tails", "DXD", "mtx_eye", 9050001, 16, 16);
					ReplaceTex("m_tr_p", "mtx_hand01", "Tails", "DXD", "mtx_hand01", 9050002, 64, 64);
					ReplaceTex("shooting1", "mtx_body01", "Tails", "DXD", "mtx_body01", 304700, 64, 64);
					ReplaceTex("shooting1", "mtx_eye", "Tails", "DXD", "mtx_eye", 304701, 16, 16);
					ReplaceTex("shooting1", "mtx_hand01", "Tails", "DXD", "mtx_hand01", 304702, 64, 64);
					ReplaceTex("shooting1", "mtx_head01", "Tails", "DXD", "mtx_head01", 304703, 64, 64);
					ReplaceTex("shooting1", "mtx_white", "Tails", "DXD", "mtx_white", 304704, 8, 8);
					ReplaceTex("shooting2", "mtx_body01", "Tails", "DXD", "mtx_body01", 304750, 64, 64);
					ReplaceTex("shooting2", "mtx_eye", "Tails", "DXD", "mtx_eye", 304751, 16, 16);
					ReplaceTex("shooting2", "mtx_hand01", "Tails", "DXD", "mtx_hand01", 304752, 64, 64);
					ReplaceTex("shooting2", "mtx_head01", "Tails", "DXD", "mtx_head01", 304753, 64, 64);
					ReplaceTex("shooting2", "mtx_white", "Tails", "DXD", "mtx_white", 304754, 8, 8);
				}

				if (KindofTextDX == OriginalDX)
				{
					ReplacePVM("Miles", "Miles_dx");
				}
			}
		}

		if (EnableKnuckles)
		{
			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("Knuckles", "Knuckles_ldx");
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("Knuckles", "Knuckles_DC");
				}

				if (KindofTextDC == DXT)
				{
					ReplacePVM("Knuckles", "Knuckles_DCWDX");
				}
			}
			else
			{
				if (KindofTextDX == LikeDream)
				{
					ReplacePVM("Knuckles", "Knuckles_ld");
				}

				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("Knuckles", "Knuckles_dxd");
				}

				if (KindofTextDX == OriginalDX)
				{
					ReplacePVM("Knuckles", "Knuckles_dx");
				}
			}
		}

		if (EnableAmy)
		{
			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("Amy", "Amy_ldx");
					ReplaceTex("amy_eggrobo", "atx_hada", "Amy", "LDX", "atx_hada", 600719, 8, 8);
					ReplaceTex("amy_eggrobo", "alltx_dwhite", "Amy", "LDX", "alltx_dwhite", 600720, 8, 8);
					ReplaceTex("amy_eggrobo", "atx_eri", "Amy", "LDX", "atx_eri", 600721, 8, 8);
					ReplaceTex("amy_eggrobo", "atx_eye00", "Amy", "LDX", "atx_eye00", 600722, 16, 16);
					ReplaceTex("amy_eggrobo", "atx_fuku0", "Amy", "LDX", "atx_fuku0", 600723, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_fuku1", "Amy", "LDX", "atx_fuku1", 600724, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_fuku2", "Amy", "LDX", "atx_fuku2", 600725, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_fuku3", "Amy", "LDX", "atx_fuku3", 600725, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_fuku4", "Amy", "LDX", "atx_fuku4", 600727, 32, 32);
					ReplaceTex("amy_eggrobo", "a_weye", "Amy", "LDX", "a_weye", 600728, 8, 8);
					ReplaceTex("amy_eggrobo", "atx_inner0", "Amy", "LDX", "atx_inner0", 600729, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_kazari", "Amy", "LDX", "atx_kazari", 600730, 16, 16);
					ReplaceTex("amy_eggrobo", "atx_kutu0", "Amy", "LDX", "atx_kutu0", 600731, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_kutu1", "Amy", "LDX", "atx_kutu1", 600732, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_kutu2", "Amy", "LDX", "atx_kutu2", 600733, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_kutu3", "Amy", "LDX", "atx_kutu3", 600734, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_kutu4", "Amy", "LDX", "atx_kutu4", 600735, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_pink0", "Amy", "LDX", "atx_pink0", 600738, 64, 64);
					ReplaceTex("amy_eggrobo", "atx_ring", "Amy", "LDX", "atx_ring", 600739, 16, 16);
					ReplaceTex("amy_eggrobo", "s_hando2", "Amy", "LDX", "s_hando2", 600740, 32, 32);
					ReplaceTex("amy_eggrobo", "s_testhand", "Amy", "LDX", "s_testhand", 600741, 64, 64);
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("Amy", "Amy_DC");
				}

				if (KindofTextDC == DXT)
				{
					ReplacePVM("Amy", "Amy_DCWDX");
					ReplaceTex("amy_eggrobo", "atx_hada", "Amy", "DCWDX", "atx_hada", 600719, 8, 8);
					ReplaceTex("amy_eggrobo", "alltx_dwhite", "Amy", "DCWDX", "alltx_dwhite", 600720, 8, 8);
					ReplaceTex("amy_eggrobo", "atx_eri", "Amy", "DCWDX", "atx_eri", 600721, 8, 8);
					ReplaceTex("amy_eggrobo", "atx_eye00", "Amy", "DCWDX", "atx_eye00", 600722, 16, 16);
					ReplaceTex("amy_eggrobo", "atx_fuku0", "Amy", "DCWDX", "atx_fuku0", 600723, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_fuku1", "Amy", "DCWDX", "atx_fuku1", 600724, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_fuku2", "Amy", "DCWDX", "atx_fuku2", 600725, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_fuku3", "Amy", "DCWDX", "atx_fuku3", 600725, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_fuku4", "Amy", "DCWDX", "atx_fuku4", 600727, 32, 32);
					ReplaceTex("amy_eggrobo", "a_weye", "Amy", "DCWDX", "a_weye", 600728, 8, 8);
					ReplaceTex("amy_eggrobo", "atx_inner0", "Amy", "DCWDX", "atx_inner0", 600729, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_kazari", "Amy", "DCWDX", "atx_kazari", 600730, 16, 16);
					ReplaceTex("amy_eggrobo", "atx_kutu0", "Amy", "DCWDX", "atx_kutu0", 600731, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_kutu1", "Amy", "DCWDX", "atx_kutu1", 600732, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_kutu2", "Amy", "DCWDX", "atx_kutu2", 600733, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_kutu3", "Amy", "DCWDX", "atx_kutu3", 600734, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_kutu4", "Amy", "DCWDX", "atx_kutu4", 600735, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_pink0", "Amy", "DCWDX", "atx_pink0", 600738, 64, 64);
					ReplaceTex("amy_eggrobo", "atx_ring", "Amy", "DCWDX", "atx_ring", 600739, 16, 16);
					ReplaceTex("amy_eggrobo", "s_hando2", "Amy", "DCWDX", "s_hando2", 600740, 32, 32);
					ReplaceTex("amy_eggrobo", "s_testhand", "Amy", "DCWDX", "s_testhand", 600741, 64, 64);
				}
			}
			else
			{
				if (KindofTextDX == LikeDream)
				{
					ReplacePVM("Amy", "Amy_ld");
				}

				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("Amy", "Amy_dxd");
				}

				if (KindofTextDX == OriginalDX)
				{
					ReplacePVM("Amy", "Amy_dx");
					ReplaceTex("amy_eggrobo", "atx_hada", "Amy", "DCWDX", "atx_hada", 600719, 8, 8);
					ReplaceTex("amy_eggrobo", "alltx_dwhite", "Amy", "DCWDX", "alltx_dwhite", 600720, 8, 8);
					ReplaceTex("amy_eggrobo", "atx_eri", "Amy", "DCWDX", "atx_eri", 600721, 8, 8);
					ReplaceTex("amy_eggrobo", "atx_eye00", "Amy", "DCWDX", "atx_eye00", 600722, 16, 16);
					ReplaceTex("amy_eggrobo", "atx_fuku0", "Amy", "DCWDX", "atx_fuku0", 600723, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_fuku1", "Amy", "DCWDX", "atx_fuku1", 600724, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_fuku2", "Amy", "DCWDX", "atx_fuku2", 600725, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_fuku3", "Amy", "DCWDX", "atx_fuku3", 600725, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_fuku4", "Amy", "DCWDX", "atx_fuku4", 600727, 32, 32);
					ReplaceTex("amy_eggrobo", "a_weye", "Amy", "DCWDX", "a_weye", 600728, 8, 8);
					ReplaceTex("amy_eggrobo", "atx_inner0", "Amy", "DCWDX", "atx_inner0", 600729, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_kazari", "Amy", "DCWDX", "atx_kazari", 600730, 16, 16);
					ReplaceTex("amy_eggrobo", "atx_kutu0", "Amy", "DCWDX", "atx_kutu0", 600731, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_kutu1", "Amy", "DCWDX", "atx_kutu1", 600732, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_kutu2", "Amy", "DCWDX", "atx_kutu2", 600733, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_kutu3", "Amy", "DCWDX", "atx_kutu3", 600734, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_kutu4", "Amy", "DCWDX", "atx_kutu4", 600735, 32, 32);
					ReplaceTex("amy_eggrobo", "atx_pink0", "Amy", "DCWDX", "atx_pink0", 600738, 64, 64);
					ReplaceTex("amy_eggrobo", "atx_ring", "Amy", "DCWDX", "atx_ring", 600739, 16, 16);
					ReplaceTex("amy_eggrobo", "s_hando2", "Amy", "DCWDX", "s_hando2", 600740, 32, 32);
					ReplaceTex("amy_eggrobo", "s_testhand", "Amy", "DCWDX", "s_testhand", 600741, 64, 64);
				}
			}
		}

		if (EnableGamma)
		{
			if (KindofTextGamma == OriginalG)
			{
				ReplacePVM("E102", "E102_or");
				ReplacePVM("E102_dc", "E102_or");
			}

			if (KindofTextGamma == Reworked)
			{
				ReplacePVM("E102", "E102_r");
				ReplacePVM("E102_dc", "E102_r");
			}
		}

		if (EnableBig)
		{
			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("Big", "Big_ldx");
					ReplaceTex("ev_tr2_big", "b_beruto3", "Big", "LDX", "b_beruto3", 600344, 32, 32);
					ReplaceTex("ev_tr2_big", "b_beruto", "Big", "LDX", "b_beruto", 600345, 32, 32);
					ReplaceTex("ev_tr2_big", "b_beruto5", "Big", "LDX", "b_beruto5", 600346, 32, 32);
					ReplaceTex("ev_tr2_big", "b_hand0", "Big", "LDX", "b_hand0", 600348, 16, 16);
					ReplaceTex("ev_tr2_big", "b_hand1", "Big", "LDX", "b_hand1", 600349, 16, 16);
					ReplaceTex("ev_tr2_big", "b_hand2", "Big", "LDX", "b_hand2", 600350, 8, 8);
					ReplaceTex("ev_tr2_big", "btx_atama", "Big", "LDX", "btx_atama", 600356, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_gara", "Big", "LDX", "btx_gara", 600358, 32, 32);
					ReplaceTex("ev_tr2_big", "btx_hada0", "Big", "LDX", "btx_hada0", 600359, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_hara1", "Big", "LDX", "btx_hara1", 600360, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_kutu0", "Big", "LDX", "btx_kutu0", 600362, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_mimi", "Big", "LDX", "btx_mimi", 600363, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_panda", "Big", "LDX", "btx_panda", 600364, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_senaka", "Big", "LDX", "btx_senaka", 600365, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_sims", "Big", "LDX", "btx_sims", 600366, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_white0", "Big", "LDX", "btx_white0", 600368, 8, 8);
					ReplaceTex("ev_tr2_big", "btx_white1", "Big", "LDX", "btx_white1", 600369, 8, 8);
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("Big", "Big_DC");
				}

				if (KindofTextDC == DXT)
				{
					ReplacePVM("Big", "Big_DCWDX");
					ReplaceTex("ev_tr2_big", "b_beruto3", "Big", "DCWDX", "b_beruto3", 600344, 32, 32);
					ReplaceTex("ev_tr2_big", "b_beruto", "Big", "DCWDX", "b_beruto", 600345, 32, 32);
					ReplaceTex("ev_tr2_big", "b_beruto5", "Big", "DCWDX", "b_beruto5", 600346, 32, 32);
					ReplaceTex("ev_tr2_big", "b_hand0", "Big", "DCWDX", "b_hand0", 600348, 16, 16);
					ReplaceTex("ev_tr2_big", "b_hand1", "Big", "DCWDX", "b_hand1", 600349, 16, 16);
					ReplaceTex("ev_tr2_big", "b_hand2", "Big", "DCWDX", "b_hand2", 600350, 8, 8);
					ReplaceTex("ev_tr2_big", "btx_atama", "Big", "DCWDX", "btx_atama", 600356, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_gara", "Big", "DCWDX", "btx_gara", 600358, 32, 32);
					ReplaceTex("ev_tr2_big", "btx_hada0", "Big", "DCWDX", "btx_hada0", 600359, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_hara1", "Big", "DCWDX", "btx_hara1", 600360, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_kutu0", "Big", "DCWDX", "btx_kutu0", 600362, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_mimi", "Big", "DCWDX", "btx_mimi", 600363, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_panda", "Big", "DCWDX", "btx_panda", 600364, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_senaka", "Big", "DCWDX", "btx_senaka", 600365, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_sims", "Big", "DCWDX", "btx_sims", 600366, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_white0", "Big", "DCWDX", "btx_white0", 600368, 8, 8);
					ReplaceTex("ev_tr2_big", "btx_white1", "Big", "DCWDX", "btx_white1", 600369, 8, 8);
				}
			}
			else
			{
				if (KindofTextDX == LikeDream)
				{
					ReplacePVM("Big", "Big_ld");
				}

				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("Big", "Big_dxd");
				}

				if (KindofTextDX == OriginalDX)
				{
					ReplacePVM("Big", "Big_dx");
					ReplaceTex("ev_tr2_big", "b_beruto3", "Big", "DCWDX", "b_beruto3", 600344, 32, 32);
					ReplaceTex("ev_tr2_big", "b_beruto", "Big", "DCWDX", "b_beruto", 600345, 32, 32);
					ReplaceTex("ev_tr2_big", "b_beruto5", "Big", "DCWDX", "b_beruto5", 600346, 32, 32);
					ReplaceTex("ev_tr2_big", "b_hand0", "Big", "DCWDX", "b_hand0", 600348, 16, 16);
					ReplaceTex("ev_tr2_big", "b_hand1", "Big", "DCWDX", "b_hand1", 600349, 16, 16);
					ReplaceTex("ev_tr2_big", "b_hand2", "Big", "DCWDX", "b_hand2", 600350, 8, 8);
					ReplaceTex("ev_tr2_big", "btx_atama", "Big", "DCWDX", "btx_atama", 600356, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_gara", "Big", "DCWDX", "btx_gara", 600358, 32, 32);
					ReplaceTex("ev_tr2_big", "btx_hada0", "Big", "DCWDX", "btx_hada0", 600359, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_hara1", "Big", "DCWDX", "btx_hara1", 600360, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_kutu0", "Big", "DCWDX", "btx_kutu0", 600362, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_mimi", "Big", "DCWDX", "btx_mimi", 600363, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_panda", "Big", "DCWDX", "btx_panda", 600364, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_senaka", "Big", "DCWDX", "btx_senaka", 600365, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_sims", "Big", "DCWDX", "btx_sims", 600366, 64, 64);
					ReplaceTex("ev_tr2_big", "btx_white0", "Big", "DCWDX", "btx_white0", 600368, 8, 8);
					ReplaceTex("ev_tr2_big", "btx_white1", "Big", "DCWDX", "btx_white1", 600369, 8, 8);
				}
			}
		}

		if (EnableMetal)
		{
			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("Metalsonic", "Metalsonic_ldx");
					ReplaceTex("ev_s_msbody", "mrd_032s_msana", "Big", "LDX", "mrd_032s_msana", 219002, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_032s_mseye", "Big", "LDX", "mrd_032s_mseye", 219004, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_msblack", "Big", "LDX", "mrd_064s_msblack", 219005, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_msblue", "Big", "LDX", "mrd_064s_msblue", 219006, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_msred", "Big", "LDX", "mrd_064s_msred", 219007, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_msslv", "Big", "LDX", "mrd_064s_msslv", 219008, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_mswhite", "Big", "LDX", "mrd_064s_mswhite", 219009, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_msyelw", "Big", "LDX", "mrd_064s_msyelw", 219010, 32, 32);
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("Metalsonic", "Metalsonic_DC");
				}

				if (KindofTextDC == DXT)
				{
					ReplacePVM("Metalsonic", "Metalsonic_DCWDX");
					ReplaceTex("ev_s_msbody", "mrd_032s_msana", "Big", "DCWDX", "mrd_032s_msana", 219002, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_032s_mseye", "Big", "DCWDX", "mrd_032s_mseye", 219004, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_msblack", "Big", "DCWDX", "mrd_064s_msblack", 219005, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_msblue", "Big", "DCWDX", "mrd_064s_msblue", 219006, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_msred", "Big", "DCWDX", "mrd_064s_msred", 219007, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_msslv", "Big", "DCWDX", "mrd_064s_msslv", 219008, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_mswhite", "Big", "DCWDX", "mrd_064s_mswhite", 219009, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_msyelw", "Big", "DCWDX", "mrd_064s_msyelw", 219010, 32, 32);
				}
			}
			else
			{
				if (KindofTextDX == LikeDream)
				{
					ReplacePVM("Metalsonic", "Metalsonic_ld");
				}

				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("Metalsonic", "Metalsonic_dxd");
				}

				if (KindofTextDX == OriginalDX)
				{
					ReplacePVM("Metalsonic", "Metalsonic_dx");
					ReplaceTex("ev_s_msbody", "mrd_032s_msana", "Big", "DCWDX", "mrd_032s_msana", 219002, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_032s_mseye", "Big", "DCWDX", "mrd_032s_mseye", 219004, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_msblack", "Big", "DCWDX", "mrd_064s_msblack", 219005, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_msblue", "Big", "DCWDX", "mrd_064s_msblue", 219006, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_msred", "Big", "DCWDX", "mrd_064s_msred", 219007, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_msslv", "Big", "DCWDX", "mrd_064s_msslv", 219008, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_mswhite", "Big", "DCWDX", "mrd_064s_mswhite", 219009, 32, 32);
					ReplaceTex("ev_s_msbody", "mrd_064s_msyelw", "Big", "DCWDX", "mrd_064s_msyelw", 219010, 32, 32);
				}
			}
		}

		if (EnableTikal)
		{
			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("Tikal", "Tikal_ldx");
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("Tikal", "Tikal_DC");
				}

				if (KindofTextDC == DXT)
				{
					ReplacePVM("Tikal", "Tikal_DCWDX");
				}
			}
			else
			{
				if (KindofTextDX == LikeDream)
				{
					if (Consistency == true)
					{
						ReplacePVM("Tikal", "tikal_dxldc");
					}

					else
					{
						ReplacePVM("Tikal", "Tikal_ld");
					}
				}

				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("Tikal", "Tikal_dxd");
				}

				if (KindofTextDX == OriginalDX)
				{
					if (Consistency == true)
					{
						ReplacePVM("Tikal", "tikal_dxlsa2");
					}

					else
					{
						ReplacePVM("Tikal", "Tikal_dx");
					}
				}
			}
		}

		if (EnableEggman)
		{
			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("Eggman", "Eggman_ldx");
					ReplaceTex("chaos6_eggman", "e_fuku03", "Eggman", "LDX", "e_fuku03", 420035, 32, 32);
					ReplaceTex("chaos6_eggman", "e_fuku02", "Eggman", "LDX", "e_fuku02", 420036, 64, 64);
					ReplaceTex("chaos6_eggman", "kan_g", "Eggman", "LDX", "kan_g", 420038, 64, 64);
					ReplaceTex("chaos6_eggman", "kan_m", "Eggman", "LDX", "kan_m", 420039, 64, 64);
					ReplaceTex("chaos6_eggman", "e_hige", "Eggman", "LDX", "e_hige", 420040, 64, 64);
					ReplaceTex("chaos6_eggman", "e_fuku04", "Eggman", "LDX", "e_fuku04", 420041, 32, 32);
					ReplaceTex("chaos6_eggman", "e_fuku01", "Eggman", "LDX", "e_fuku01", 420042, 32, 32);
					ReplaceTex("chaos6_eggman", "s_hando2", "Eggman", "LDX", "s_hando2", 420044, 32, 32);
					ReplaceTex("egm1eggman", "e_fuku03", "Eggman", "LDX", "e_fuku03", 420035, 32, 32);
					ReplaceTex("egm1eggman", "e_fuku02", "Eggman", "LDX", "e_fuku02", 420036, 64, 64);					
					ReplaceTex("egm1eggman", "kan_m", "Eggman", "LDX", "kan_m", 420039, 64, 64);
					ReplaceTex("egm1eggman", "e_hige", "Eggman", "LDX", "e_hige", 420040, 64, 64);
					ReplaceTex("egm1eggman", "e_fuku04", "Eggman", "LDX", "e_fuku04", 420041, 32, 32);
					ReplaceTex("egm1eggman", "e_fuku01", "Eggman", "LDX", "e_fuku01", 420042, 32, 32);
					ReplaceTex("egm1eggman", "s_hando2", "Eggman", "LDX", "s_hando2", 420044, 32, 32);
					ReplaceTex("egm1eggman", "s_testhand", "Eggman", "LDX", "s_testhand", 420045, 64, 64);
					ReplaceTex("egm1eggman", "kan_s", "Eggman", "LDX", "kan_s", 500987, 64, 64);
					ReplaceTex("egm1eggman", "eghada", "Eggman", "LDX", "eghada", 500998, 8, 8);
					ReplaceTex("egm1eggman", "eghana", "Eggman", "LDX", "eghana", 500999, 8, 8);
					ReplaceTex("egm2_common", "e_fuku03", "Eggman", "LDX", "e_fuku03", 406042, 32, 32);
					ReplaceTex("egm2_common", "e_fuku02", "Eggman", "LDX", "e_fuku02", 406043, 64, 64);
					ReplaceTex("egm2_common", "kan_g", "Eggman", "LDX", "kan_g", 406045, 64, 64);
					ReplaceTex("egm2_common", "kan_m", "Eggman", "LDX", "kan_m", 406046, 64, 64);
					ReplaceTex("egm2_common", "e_hige", "Eggman", "LDX", "e_hige", 406047, 64, 64);
					ReplaceTex("egm2_common", "e_fuku04", "Eggman", "LDX", "e_fuku04", 406048, 32, 32);
					ReplaceTex("egm2_common", "e_fuku01", "Eggman", "LDX", "e_fuku01", 406049, 32, 32);
					ReplaceTex("egm2_common", "s_hando2", "Eggman", "LDX", "s_hando2", 406051, 32, 32);
					ReplaceTex("egm2_common", "s_testhand", "Eggman", "LDX", "s_testhand", 406052, 64, 64);
					ReplaceTex("egm3mdl", "e_fuku03", "Eggman", "LDX", "e_fuku03", 420035, 32, 32);
					ReplaceTex("egm3mdl", "e_fuku02", "Eggman", "LDX", "e_fuku02", 420036, 64, 64);
					ReplaceTex("egm3mdl", "kan_g", "Eggman", "LDX", "kan_g", 420038, 64, 64);
					ReplaceTex("egm3mdl", "kan_m", "Eggman", "LDX", "kan_m", 420039, 64, 64);
					ReplaceTex("egm3mdl", "e_hige", "Eggman", "LDX", "e_hige", 420040, 64, 64);
					ReplaceTex("egm3mdl", "e_fuku04", "Eggman", "LDX", "e_fuku04", 420041, 32, 32);
					ReplaceTex("egm3mdl", "e_fuku01", "Eggman", "LDX", "e_fuku01", 420042, 32, 32);
					ReplaceTex("egm3mdl", "s_hando2", "Eggman", "LDX", "s_hando2", 420044, 32, 32);
					ReplaceTex("ev_eggman_body", "s_hando2", "Eggman", "LDX", "s_hando2", 600140, 32, 32);
					ReplaceTex("ev_eggman_body", "e_fuku01", "Eggman", "LDX", "e_fuku01", 600142, 32, 32);
					ReplaceTex("ev_eggman_body", "e_fuku02", "Eggman", "LDX", "e_fuku02", 600143, 64, 64);
					ReplaceTex("ev_eggman_body", "e_fuku03", "Eggman", "LDX", "e_fuku03", 600144, 32, 32);
					ReplaceTex("ev_eggman_body", "e_fuku04", "Eggman", "LDX", "e_fuku04", 600145, 32, 32);
					ReplaceTex("ev_eggman_body", "e_hige", "Eggman", "LDX", "e_hige", 600146, 64, 64);
					ReplaceTex("ev_eggman_body", "eghada", "Eggman", "LDX", "eghada", 600158, 8, 8);
					ReplaceTex("ev_eggman_body", "eghana", "Eggman", "LDX", "eghana", 600159, 8, 8);
					ReplaceTex("ev_eggman_body", "kan_g", "Eggman", "LDX", "kan_g", 600164, 64, 64);
					ReplaceTex("ev_eggman_body", "kan_m", "Eggman", "LDX", "kan_m", 600165, 64, 64);
					ReplaceTex("ev_eggman_body", "s_testhand", "Eggman", "LDX", "s_testhand", 600169, 64, 64);
					ReplaceTex("ev_eggman_body", "kan_s", "Eggman", "LDX", "kan_s", 600226, 64, 64);
					ReplaceTex("ev_eggmoble0", "s_hando2", "Eggman", "LDX", "s_hando2", 600140, 32, 32);
					ReplaceTex("ev_eggmoble0", "e_fuku01", "Eggman", "LDX", "e_fuku01", 600142, 32, 32);
					ReplaceTex("ev_eggmoble0", "e_fuku02", "Eggman", "LDX", "e_fuku02", 600143, 64, 64);
					ReplaceTex("ev_eggmoble0", "e_fuku03", "Eggman", "LDX", "e_fuku03", 600144, 32, 32);
					ReplaceTex("ev_eggmoble0", "e_fuku04", "Eggman", "LDX", "e_fuku04", 600145, 32, 32);
					ReplaceTex("ev_eggmoble0", "e_hige", "Eggman", "LDX", "e_hige", 600146, 64, 64);
					ReplaceTex("ev_eggmoble0", "eghada", "Eggman", "LDX", "eghada", 600158, 8, 8);
					ReplaceTex("ev_eggmoble0", "eghana", "Eggman", "LDX", "eghana", 600159, 8, 8);
					ReplaceTex("ev_eggmoble0", "kan_g", "Eggman", "LDX", "kan_g", 600164, 64, 64);
					ReplaceTex("ev_eggmoble0", "kan_m", "Eggman", "LDX", "kan_m", 600165, 64, 64);
					ReplaceTex("ev_eggmoble0", "kan_y", "Eggman", "LDX", "kan_y", 600166, 64, 64);
					ReplaceTex("ev_eggmoble0", "s_testhand", "Eggman", "LDX", "s_testhand", 600169, 64, 64);
					ReplaceTex("mrace_eggmoble", "e_fuku03", "Eggman", "LDX", "e_fuku03", 420035, 32, 32);
					ReplaceTex("mrace_eggmoble", "e_fuku02", "Eggman", "LDX", "e_fuku02", 420036, 64, 64);
					ReplaceTex("mrace_eggmoble", "kan_g", "Eggman", "LDX", "kan_g", 420038, 64, 64);
					ReplaceTex("mrace_eggmoble", "kan_m", "Eggman", "LDX", "kan_m", 420039, 64, 64);
					ReplaceTex("mrace_eggmoble", "e_hige", "Eggman", "LDX", "e_hige", 420040, 64, 64);
					ReplaceTex("mrace_eggmoble", "e_fuku04", "Eggman", "LDX", "e_fuku04", 420041, 32, 32);
					ReplaceTex("mrace_eggmoble", "e_fuku01", "Eggman", "LDX", "e_fuku01", 420042, 32, 32);
					ReplaceTex("mrace_eggmoble", "s_hando2", "Eggman", "LDX", "s_hando2", 420044, 32, 32);
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("Eggman", "Eggman_DC");
				}

				if (KindofTextDC == DXT)
				{
					ReplacePVM("Eggman", "Eggman_DCWDX");
					ReplaceTex("chaos6_eggman", "e_fuku03", "Eggman", "DCWDX", "e_fuku03", 420035, 32, 32);
					ReplaceTex("chaos6_eggman", "e_fuku02", "Eggman", "DCWDX", "e_fuku02", 420036, 64, 64);
					ReplaceTex("chaos6_eggman", "kan_g", "Eggman", "DCWDX", "kan_g", 420038, 64, 64);
					ReplaceTex("chaos6_eggman", "kan_m", "Eggman", "DCWDX", "kan_m", 420039, 64, 64);
					ReplaceTex("chaos6_eggman", "e_hige", "Eggman", "DCWDX", "e_hige", 420040, 64, 64);
					ReplaceTex("chaos6_eggman", "e_fuku04", "Eggman", "DCWDX", "e_fuku04", 420041, 32, 32);
					ReplaceTex("chaos6_eggman", "e_fuku01", "Eggman", "DCWDX", "e_fuku01", 420042, 32, 32);
					ReplaceTex("chaos6_eggman", "s_hando2", "Eggman", "DCWDX", "s_hando2", 420044, 32, 32);
					ReplaceTex("egm1eggman", "e_fuku03", "Eggman", "DCWDX", "e_fuku03", 420035, 32, 32);
					ReplaceTex("egm1eggman", "e_fuku02", "Eggman", "DCWDX", "e_fuku02", 420036, 64, 64);
					ReplaceTex("egm1eggman", "kan_m", "Eggman", "DCWDX", "kan_m", 420039, 64, 64);
					ReplaceTex("egm1eggman", "e_hige", "Eggman", "DCWDX", "e_hige", 420040, 64, 64);
					ReplaceTex("egm1eggman", "e_fuku04", "Eggman", "DCWDX", "e_fuku04", 420041, 32, 32);
					ReplaceTex("egm1eggman", "e_fuku01", "Eggman", "DCWDX", "e_fuku01", 420042, 32, 32);
					ReplaceTex("egm1eggman", "s_hando2", "Eggman", "DCWDX", "s_hando2", 420044, 32, 32);
					ReplaceTex("egm1eggman", "s_testhand", "Eggman", "DCWDX", "s_testhand", 420045, 64, 64);
					ReplaceTex("egm1eggman", "kan_s", "Eggman", "DCWDX", "kan_s", 500987, 64, 64);
					ReplaceTex("egm1eggman", "eghada", "Eggman", "DCWDX", "eghada", 500998, 8, 8);
					ReplaceTex("egm1eggman", "eghana", "Eggman", "DCWDX", "eghana", 500999, 8, 8);
					ReplaceTex("egm2_common", "e_fuku03", "Eggman", "DCWDX", "e_fuku03", 406042, 32, 32);
					ReplaceTex("egm2_common", "e_fuku02", "Eggman", "DCWDX", "e_fuku02", 406043, 64, 64);
					ReplaceTex("egm2_common", "kan_g", "Eggman", "DCWDX", "kan_g", 406045, 64, 64);
					ReplaceTex("egm2_common", "kan_m", "Eggman", "DCWDX", "kan_m", 406046, 64, 64);
					ReplaceTex("egm2_common", "e_hige", "Eggman", "DCWDX", "e_hige", 406047, 64, 64);
					ReplaceTex("egm2_common", "e_fuku04", "Eggman", "DCWDX", "e_fuku04", 406048, 32, 32);
					ReplaceTex("egm2_common", "e_fuku01", "Eggman", "DCWDX", "e_fuku01", 406049, 32, 32);
					ReplaceTex("egm2_common", "s_hando2", "Eggman", "DCWDX", "s_hando2", 406051, 32, 32);
					ReplaceTex("egm2_common", "s_testhand", "Eggman", "DCWDX", "s_testhand", 406052, 64, 64);
					ReplaceTex("egm3mdl", "e_fuku03", "Eggman", "DCWDX", "e_fuku03", 420035, 32, 32);
					ReplaceTex("egm3mdl", "e_fuku02", "Eggman", "DCWDX", "e_fuku02", 420036, 64, 64);
					ReplaceTex("egm3mdl", "kan_g", "Eggman", "DCWDX", "kan_g", 420038, 64, 64);
					ReplaceTex("egm3mdl", "kan_m", "Eggman", "DCWDX", "kan_m", 420039, 64, 64);
					ReplaceTex("egm3mdl", "e_hige", "Eggman", "DCWDX", "e_hige", 420040, 64, 64);
					ReplaceTex("egm3mdl", "e_fuku04", "Eggman", "DCWDX", "e_fuku04", 420041, 32, 32);
					ReplaceTex("egm3mdl", "e_fuku01", "Eggman", "DCWDX", "e_fuku01", 420042, 32, 32);
					ReplaceTex("egm3mdl", "s_hando2", "Eggman", "DCWDX", "s_hando2", 420044, 32, 32);
					ReplaceTex("ev_eggman_body", "s_hando2", "Eggman", "DCWDX", "s_hando2", 600140, 32, 32);
					ReplaceTex("ev_eggman_body", "e_fuku01", "Eggman", "DCWDX", "e_fuku01", 600142, 32, 32);
					ReplaceTex("ev_eggman_body", "e_fuku02", "Eggman", "DCWDX", "e_fuku02", 600143, 64, 64);
					ReplaceTex("ev_eggman_body", "e_fuku03", "Eggman", "DCWDX", "e_fuku03", 600144, 32, 32);
					ReplaceTex("ev_eggman_body", "e_fuku04", "Eggman", "DCWDX", "e_fuku04", 600145, 32, 32);
					ReplaceTex("ev_eggman_body", "e_hige", "Eggman", "DCWDX", "e_hige", 600146, 64, 64);
					ReplaceTex("ev_eggman_body", "eghada", "Eggman", "DCWDX", "eghada", 600158, 8, 8);
					ReplaceTex("ev_eggman_body", "eghana", "Eggman", "DCWDX", "eghana", 600159, 8, 8);
					ReplaceTex("ev_eggman_body", "kan_g", "Eggman", "DCWDX", "kan_g", 600164, 64, 64);
					ReplaceTex("ev_eggman_body", "kan_m", "Eggman", "DCWDX", "kan_m", 600165, 64, 64);
					ReplaceTex("ev_eggman_body", "s_testhand", "Eggman", "DCWDX", "s_testhand", 600169, 64, 64);
					ReplaceTex("ev_eggman_body", "kan_s", "Eggman", "DCWDX", "kan_s", 600226, 64, 64);
					ReplaceTex("ev_eggmoble0", "s_hando2", "Eggman", "DCWDX", "s_hando2", 600140, 32, 32);
					ReplaceTex("ev_eggmoble0", "e_fuku01", "Eggman", "DCWDX", "e_fuku01", 600142, 32, 32);
					ReplaceTex("ev_eggmoble0", "e_fuku02", "Eggman", "DCWDX", "e_fuku02", 600143, 64, 64);
					ReplaceTex("ev_eggmoble0", "e_fuku03", "Eggman", "DCWDX", "e_fuku03", 600144, 32, 32);
					ReplaceTex("ev_eggmoble0", "e_fuku04", "Eggman", "DCWDX", "e_fuku04", 600145, 32, 32);
					ReplaceTex("ev_eggmoble0", "e_hige", "Eggman", "DCWDX", "e_hige", 600146, 64, 64);
					ReplaceTex("ev_eggmoble0", "eghada", "Eggman", "DCWDX", "eghada", 600158, 8, 8);
					ReplaceTex("ev_eggmoble0", "eghana", "Eggman", "DCWDX", "eghana", 600159, 8, 8);
					ReplaceTex("ev_eggmoble0", "kan_g", "Eggman", "DCWDX", "kan_g", 600164, 64, 64);
					ReplaceTex("ev_eggmoble0", "kan_m", "Eggman", "DCWDX", "kan_m", 600165, 64, 64);
					ReplaceTex("ev_eggmoble0", "kan_y", "Eggman", "DCWDX", "kan_y", 600166, 64, 64);
					ReplaceTex("ev_eggmoble0", "s_testhand", "Eggman", "DCWDX", "s_testhand", 600169, 64, 64);
					ReplaceTex("mrace_eggmoble", "e_fuku03", "Eggman", "DCWDX", "e_fuku03", 420035, 32, 32);
					ReplaceTex("mrace_eggmoble", "e_fuku02", "Eggman", "DCWDX", "e_fuku02", 420036, 64, 64);
					ReplaceTex("mrace_eggmoble", "kan_g", "Eggman", "DCWDX", "kan_g", 420038, 64, 64);
					ReplaceTex("mrace_eggmoble", "kan_m", "Eggman", "DCWDX", "kan_m", 420039, 64, 64);
					ReplaceTex("mrace_eggmoble", "e_hige", "Eggman", "DCWDX", "e_hige", 420040, 64, 64);
					ReplaceTex("mrace_eggmoble", "e_fuku04", "Eggman", "DCWDX", "e_fuku04", 420041, 32, 32);
					ReplaceTex("mrace_eggmoble", "e_fuku01", "Eggman", "DCWDX", "e_fuku01", 420042, 32, 32);
					ReplaceTex("mrace_eggmoble", "s_hando2", "Eggman", "DCWDX", "s_hando2", 420044, 32, 32);
				}
			}
			else
			{
				if (KindofTextDX == LikeDream)
				{
					if (Consistency == true)
					{
						ReplacePVM("Eggman", "Eggman_dxldc");
						ReplaceTex("chaos6_eggman", "e_fuku03", "Eggman", "DXLDC", "e_fuku03", 420035, 32, 32);
						ReplaceTex("chaos6_eggman", "e_fuku02", "Eggman", "DXLDC", "e_fuku02", 420036, 64, 64);
						ReplaceTex("chaos6_eggman", "kan_g", "Eggman", "DXLDC", "kan_g", 420038, 64, 64);
						ReplaceTex("chaos6_eggman", "kan_m", "Eggman", "DXLDC", "kan_m", 420039, 64, 64);
						ReplaceTex("chaos6_eggman", "e_hige", "Eggman", "DXLDC", "e_hige", 420040, 64, 64);
						ReplaceTex("chaos6_eggman", "e_fuku04", "Eggman", "DXLDC", "e_fuku04", 420041, 32, 32);
						ReplaceTex("chaos6_eggman", "e_fuku01", "Eggman", "DXLDC", "e_fuku01", 420042, 32, 32);
						ReplaceTex("chaos6_eggman", "s_hando2", "Eggman", "DXLDC", "s_hando2", 420044, 32, 32);
						ReplaceTex("egm1eggman", "e_fuku03", "Eggman", "DXLDC", "e_fuku03", 420035, 32, 32);
						ReplaceTex("egm1eggman", "e_fuku02", "Eggman", "DXLDC", "e_fuku02", 420036, 64, 64);
						ReplaceTex("egm1eggman", "kan_m", "Eggman", "DXLDC", "kan_m", 420039, 64, 64);
						ReplaceTex("egm1eggman", "e_hige", "Eggman", "DXLDC", "e_hige", 420040, 64, 64);
						ReplaceTex("egm1eggman", "e_fuku04", "Eggman", "DXLDC", "e_fuku04", 420041, 32, 32);
						ReplaceTex("egm1eggman", "e_fuku01", "Eggman", "DXLDC", "e_fuku01", 420042, 32, 32);
						ReplaceTex("egm1eggman", "s_hando2", "Eggman", "DXLDC", "s_hando2", 420044, 32, 32);
						ReplaceTex("egm1eggman", "s_testhand", "Eggman", "DXLDC", "s_testhand", 420045, 64, 64);
						ReplaceTex("egm1eggman", "kan_s", "Eggman", "DXLDC", "kan_s", 500987, 64, 64);
						ReplaceTex("egm1eggman", "eghada", "Eggman", "DXLDC", "eghada", 500998, 8, 8);
						ReplaceTex("egm1eggman", "eghana", "Eggman", "DXLDC", "eghana", 500999, 8, 8);
						ReplaceTex("egm2_common", "e_fuku03", "Eggman", "DXLDC", "e_fuku03", 406042, 32, 32);
						ReplaceTex("egm2_common", "e_fuku02", "Eggman", "DXLDC", "e_fuku02", 406043, 64, 64);
						ReplaceTex("egm2_common", "kan_g", "Eggman", "DXLDC", "kan_g", 406045, 64, 64);
						ReplaceTex("egm2_common", "kan_m", "Eggman", "DXLDC", "kan_m", 406046, 64, 64);
						ReplaceTex("egm2_common", "e_hige", "Eggman", "DXLDC", "e_hige", 406047, 64, 64);
						ReplaceTex("egm2_common", "e_fuku04", "Eggman", "DXLDC", "e_fuku04", 406048, 32, 32);
						ReplaceTex("egm2_common", "e_fuku01", "Eggman", "DXLDC", "e_fuku01", 406049, 32, 32);
						ReplaceTex("egm2_common", "s_hando2", "Eggman", "DXLDC", "s_hando2", 406051, 32, 32);
						ReplaceTex("egm2_common", "s_testhand", "Eggman", "DXLDC", "s_testhand", 406052, 64, 64);
						ReplaceTex("egm3mdl", "e_fuku03", "Eggman", "DXLDC", "e_fuku03", 420035, 32, 32);
						ReplaceTex("egm3mdl", "e_fuku02", "Eggman", "DXLDC", "e_fuku02", 420036, 64, 64);
						ReplaceTex("egm3mdl", "kan_g", "Eggman", "DXLDC", "kan_g", 420038, 64, 64);
						ReplaceTex("egm3mdl", "kan_m", "Eggman", "DXLDC", "kan_m", 420039, 64, 64);
						ReplaceTex("egm3mdl", "e_hige", "Eggman", "DXLDC", "e_hige", 420040, 64, 64);
						ReplaceTex("egm3mdl", "e_fuku04", "Eggman", "DXLDC", "e_fuku04", 420041, 32, 32);
						ReplaceTex("egm3mdl", "e_fuku01", "Eggman", "DXLDC", "e_fuku01", 420042, 32, 32);
						ReplaceTex("egm3mdl", "s_hando2", "Eggman", "DXLDC", "s_hando2", 420044, 32, 32);
						ReplaceTex("ev_eggman_body", "s_hando2", "Eggman", "DXLDC", "s_hando2", 600140, 32, 32);
						ReplaceTex("ev_eggman_body", "e_fuku01", "Eggman", "DXLDC", "e_fuku01", 600142, 32, 32);
						ReplaceTex("ev_eggman_body", "e_fuku02", "Eggman", "DXLDC", "e_fuku02", 600143, 64, 64);
						ReplaceTex("ev_eggman_body", "e_fuku03", "Eggman", "DXLDC", "e_fuku03", 600144, 32, 32);
						ReplaceTex("ev_eggman_body", "e_fuku04", "Eggman", "DXLDC", "e_fuku04", 600145, 32, 32);
						ReplaceTex("ev_eggman_body", "e_hige", "Eggman", "DXLDC", "e_hige", 600146, 64, 64);
						ReplaceTex("ev_eggman_body", "eghada", "Eggman", "DXLDC", "eghada", 600158, 8, 8);
						ReplaceTex("ev_eggman_body", "eghana", "Eggman", "DXLDC", "eghana", 600159, 8, 8);
						ReplaceTex("ev_eggman_body", "kan_g", "Eggman", "DXLDC", "kan_g", 600164, 64, 64);
						ReplaceTex("ev_eggman_body", "kan_m", "Eggman", "DXLDC", "kan_m", 600165, 64, 64);
						ReplaceTex("ev_eggman_body", "s_testhand", "Eggman", "DXLDC", "s_testhand", 600169, 64, 64);
						ReplaceTex("ev_eggman_body", "kan_s", "Eggman", "DXLDC", "kan_s", 600226, 64, 64);
						ReplaceTex("ev_eggmoble0", "s_hando2", "Eggman", "DXLDC", "s_hando2", 710359, 32, 32);
						ReplaceTex("ev_eggmoble0", "e_fuku01", "Eggman", "DXLDC", "e_fuku01", 710332, 32, 32);
						ReplaceTex("ev_eggmoble0", "e_fuku02", "Eggman", "DXLDC", "e_fuku02", 710333, 64, 64);
						ReplaceTex("ev_eggmoble0", "e_fuku03", "Eggman", "DXLDC", "e_fuku03", 710334, 32, 32);
						ReplaceTex("ev_eggmoble0", "e_fuku04", "Eggman", "DXLDC", "e_fuku04", 710335, 32, 32);
						ReplaceTex("ev_eggmoble0", "e_hige", "Eggman", "DXLDC", "e_hige", 710336, 64, 64);
						ReplaceTex("ev_eggmoble0", "eghada", "Eggman", "DXLDC", "eghada", 710348, 8, 8);
						ReplaceTex("ev_eggmoble0", "eghana", "Eggman", "DXLDC", "eghana", 710349, 8, 8);
						ReplaceTex("ev_eggmoble0", "kan_g", "Eggman", "DXLDC", "kan_g", 710354, 64, 64);
						ReplaceTex("ev_eggmoble0", "kan_m", "Eggman", "DXLDC", "kan_m", 710355, 64, 64);
						ReplaceTex("ev_eggmoble0", "kan_s", "Eggman", "DXLDC", "kan_s", 710356, 64, 64);
						ReplaceTex("ev_eggmoble0", "kan_y", "Eggman", "DXLDC", "kan_y", 710357, 64, 64);
						ReplaceTex("ev_eggmoble0", "s_testhand", "Eggman", "DXLDC", "s_testhand", 710360, 64, 64);
						ReplaceTex("mrace_eggmoble", "e_fuku03", "Eggman", "DXLDC", "e_fuku03", 420035, 32, 32);
						ReplaceTex("mrace_eggmoble", "e_fuku02", "Eggman", "DXLDC", "e_fuku02", 420036, 64, 64);
						ReplaceTex("mrace_eggmoble", "kan_g", "Eggman", "DXLDC", "kan_g", 420038, 64, 64);
						ReplaceTex("mrace_eggmoble", "kan_m", "Eggman", "DXLDC", "kan_m", 420039, 64, 64);
						ReplaceTex("mrace_eggmoble", "e_hige", "Eggman", "DXLDC", "e_hige", 420040, 64, 64);
						ReplaceTex("mrace_eggmoble", "e_fuku04", "Eggman", "DXLDC", "e_fuku04", 420041, 32, 32);
						ReplaceTex("mrace_eggmoble", "e_fuku01", "Eggman", "DXLDC", "e_fuku01", 420042, 32, 32);
						ReplaceTex("mrace_eggmoble", "s_hando2", "Eggman", "DXLDC", "s_hando2", 420044, 32, 32);
					}

					else
					{
						ReplacePVM("Eggman", "Eggman_ld");
						ReplaceTex("chaos6_eggman", "e_fuku03", "Eggman", "LD", "e_fuku03", 420035, 32, 32);
						ReplaceTex("chaos6_eggman", "e_fuku02", "Eggman", "LD", "e_fuku02", 420036, 64, 64);
						ReplaceTex("chaos6_eggman", "kan_g", "Eggman", "LD", "kan_g", 420038, 64, 64);
						ReplaceTex("chaos6_eggman", "kan_m", "Eggman", "LD", "kan_m", 420039, 64, 64);
						ReplaceTex("chaos6_eggman", "e_hige", "Eggman", "LD", "e_hige", 420040, 64, 64);
						ReplaceTex("chaos6_eggman", "e_fuku04", "Eggman", "LD", "e_fuku04", 420041, 32, 32);
						ReplaceTex("chaos6_eggman", "e_fuku01", "Eggman", "LD", "e_fuku01", 420042, 32, 32);
						ReplaceTex("chaos6_eggman", "s_hando2", "Eggman", "LD", "s_hando2", 420044, 32, 32);
						ReplaceTex("egm1eggman", "e_fuku03", "Eggman", "LD", "e_fuku03", 420035, 32, 32);
						ReplaceTex("egm1eggman", "e_fuku02", "Eggman", "LD", "e_fuku02", 420036, 64, 64);
						ReplaceTex("egm1eggman", "kan_m", "Eggman", "LD", "kan_m", 420039, 64, 64);
						ReplaceTex("egm1eggman", "e_hige", "Eggman", "LD", "e_hige", 420040, 64, 64);
						ReplaceTex("egm1eggman", "e_fuku04", "Eggman", "LD", "e_fuku04", 420041, 32, 32);
						ReplaceTex("egm1eggman", "e_fuku01", "Eggman", "LD", "e_fuku01", 420042, 32, 32);
						ReplaceTex("egm1eggman", "s_hando2", "Eggman", "LD", "s_hando2", 420044, 32, 32);
						ReplaceTex("egm1eggman", "s_testhand", "Eggman", "LD", "s_testhand", 420045, 64, 64);
						ReplaceTex("egm1eggman", "kan_s", "Eggman", "LD", "kan_s", 500987, 64, 64);
						ReplaceTex("egm1eggman", "eghada", "Eggman", "LD", "eghada", 500998, 8, 8);
						ReplaceTex("egm1eggman", "eghana", "Eggman", "LD", "eghana", 500999, 8, 8);
						ReplaceTex("egm2_common", "e_fuku03", "Eggman", "LD", "e_fuku03", 406042, 32, 32);
						ReplaceTex("egm2_common", "e_fuku02", "Eggman", "LD", "e_fuku02", 406043, 64, 64);
						ReplaceTex("egm2_common", "kan_g", "Eggman", "LD", "kan_g", 406045, 64, 64);
						ReplaceTex("egm2_common", "kan_m", "Eggman", "LD", "kan_m", 406046, 64, 64);
						ReplaceTex("egm2_common", "e_hige", "Eggman", "LD", "e_hige", 406047, 64, 64);
						ReplaceTex("egm2_common", "e_fuku04", "Eggman", "LD", "e_fuku04", 406048, 32, 32);
						ReplaceTex("egm2_common", "e_fuku01", "Eggman", "LD", "e_fuku01", 406049, 32, 32);
						ReplaceTex("egm2_common", "s_hando2", "Eggman", "LD", "s_hando2", 406051, 32, 32);
						ReplaceTex("egm2_common", "s_testhand", "Eggman", "LD", "s_testhand", 406052, 64, 64);
						ReplaceTex("egm3mdl", "e_fuku03", "Eggman", "LD", "e_fuku03", 420035, 32, 32);
						ReplaceTex("egm3mdl", "e_fuku02", "Eggman", "LD", "e_fuku02", 420036, 64, 64);
						ReplaceTex("egm3mdl", "kan_g", "Eggman", "LD", "kan_g", 420038, 64, 64);
						ReplaceTex("egm3mdl", "kan_m", "Eggman", "LD", "kan_m", 420039, 64, 64);
						ReplaceTex("egm3mdl", "e_hige", "Eggman", "LD", "e_hige", 420040, 64, 64);
						ReplaceTex("egm3mdl", "e_fuku04", "Eggman", "LD", "e_fuku04", 420041, 32, 32);
						ReplaceTex("egm3mdl", "e_fuku01", "Eggman", "LD", "e_fuku01", 420042, 32, 32);
						ReplaceTex("egm3mdl", "s_hando2", "Eggman", "LD", "s_hando2", 420044, 32, 32);
						ReplaceTex("ev_eggman_body", "s_hando2", "Eggman", "LD", "s_hando2", 600140, 32, 32);
						ReplaceTex("ev_eggman_body", "e_fuku01", "Eggman", "LD", "e_fuku01", 600142, 32, 32);
						ReplaceTex("ev_eggman_body", "e_fuku02", "Eggman", "LD", "e_fuku02", 600143, 64, 64);
						ReplaceTex("ev_eggman_body", "e_fuku03", "Eggman", "LD", "e_fuku03", 600144, 32, 32);
						ReplaceTex("ev_eggman_body", "e_fuku04", "Eggman", "LD", "e_fuku04", 600145, 32, 32);
						ReplaceTex("ev_eggman_body", "e_hige", "Eggman", "LD", "e_hige", 600146, 64, 64);
						ReplaceTex("ev_eggman_body", "eghada", "Eggman", "LD", "eghada", 600158, 8, 8);
						ReplaceTex("ev_eggman_body", "eghana", "Eggman", "LD", "eghana", 600159, 8, 8);
						ReplaceTex("ev_eggman_body", "kan_g", "Eggman", "LD", "kan_g", 600164, 64, 64);
						ReplaceTex("ev_eggman_body", "kan_m", "Eggman", "LD", "kan_m", 600165, 64, 64);
						ReplaceTex("ev_eggman_body", "s_testhand", "Eggman", "LD", "s_testhand", 600169, 64, 64);
						ReplaceTex("ev_eggman_body", "kan_s", "Eggman", "LD", "kan_s", 600226, 64, 64);
						ReplaceTex("ev_eggmoble0", "s_hando2", "Eggman", "LD", "s_hando2", 710359, 32, 32);
						ReplaceTex("ev_eggmoble0", "e_fuku01", "Eggman", "LD", "e_fuku01", 710332, 32, 32);
						ReplaceTex("ev_eggmoble0", "e_fuku02", "Eggman", "LD", "e_fuku02", 710333, 64, 64);
						ReplaceTex("ev_eggmoble0", "e_fuku03", "Eggman", "LD", "e_fuku03", 710334, 32, 32);
						ReplaceTex("ev_eggmoble0", "e_fuku04", "Eggman", "LD", "e_fuku04", 710335, 32, 32);
						ReplaceTex("ev_eggmoble0", "e_hige", "Eggman", "LD", "e_hige", 710336, 64, 64);
						ReplaceTex("ev_eggmoble0", "eghada", "Eggman", "LD", "eghada", 710348, 8, 8);
						ReplaceTex("ev_eggmoble0", "eghana", "Eggman", "LD", "eghana", 710349, 8, 8);
						ReplaceTex("ev_eggmoble0", "kan_g", "Eggman", "LD", "kan_g", 710354, 64, 64);
						ReplaceTex("ev_eggmoble0", "kan_m", "Eggman", "LD", "kan_m", 710355, 64, 64);
						ReplaceTex("ev_eggmoble0", "kan_s", "Eggman", "LD", "kan_s", 710356, 64, 64);
						ReplaceTex("ev_eggmoble0", "kan_y", "Eggman", "LD", "kan_y", 710357, 64, 64);
						ReplaceTex("ev_eggmoble0", "s_testhand", "Eggman", "LD", "s_testhand", 710360, 64, 64);
						ReplaceTex("mrace_eggmoble", "e_fuku03", "Eggman", "LD", "e_fuku03", 420035, 32, 32);
						ReplaceTex("mrace_eggmoble", "e_fuku02", "Eggman", "LD", "e_fuku02", 420036, 64, 64);
						ReplaceTex("mrace_eggmoble", "kan_g", "Eggman", "LD", "kan_g", 420038, 64, 64);
						ReplaceTex("mrace_eggmoble", "kan_m", "Eggman", "LD", "kan_m", 420039, 64, 64);
						ReplaceTex("mrace_eggmoble", "e_hige", "Eggman", "LD", "e_hige", 420040, 64, 64);
						ReplaceTex("mrace_eggmoble", "e_fuku04", "Eggman", "LD", "e_fuku04", 420041, 32, 32);
						ReplaceTex("mrace_eggmoble", "e_fuku01", "Eggman", "LD", "e_fuku01", 420042, 32, 32);
						ReplaceTex("mrace_eggmoble", "s_hando2", "Eggman", "LD", "s_hando2", 420044, 32, 32);
					}
				}

				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("Eggman", "Eggman_dxd");
					ReplaceTex("chaos6_eggman", "e_fuku03", "Eggman", "DXD", "e_fuku03", 420035, 32, 32);
					ReplaceTex("chaos6_eggman", "e_fuku02", "Eggman", "DXD", "e_fuku02", 420036, 64, 64);
					ReplaceTex("chaos6_eggman", "kan_g", "Eggman", "DXD", "kan_g", 420038, 64, 64);
					ReplaceTex("chaos6_eggman", "kan_m", "Eggman", "DXD", "kan_m", 420039, 64, 64);
					ReplaceTex("chaos6_eggman", "e_hige", "Eggman", "DXD", "e_hige", 420040, 64, 64);
					ReplaceTex("chaos6_eggman", "e_fuku04", "Eggman", "DXD", "e_fuku04", 420041, 32, 32);
					ReplaceTex("chaos6_eggman", "e_fuku01", "Eggman", "DXD", "e_fuku01", 420042, 32, 32);
					ReplaceTex("chaos6_eggman", "s_hando2", "Eggman", "DXD", "s_hando2", 420044, 32, 32);
					ReplaceTex("egm1eggman", "e_fuku03", "Eggman", "DXD", "e_fuku03", 420035, 32, 32);
					ReplaceTex("egm1eggman", "e_fuku02", "Eggman", "DXD", "e_fuku02", 420036, 64, 64);
					ReplaceTex("egm1eggman", "kan_m", "Eggman", "DXD", "kan_m", 420039, 64, 64);
					ReplaceTex("egm1eggman", "e_hige", "Eggman", "DXD", "e_hige", 420040, 64, 64);
					ReplaceTex("egm1eggman", "e_fuku04", "Eggman", "DXD", "e_fuku04", 420041, 32, 32);
					ReplaceTex("egm1eggman", "e_fuku01", "Eggman", "DXD", "e_fuku01", 420042, 32, 32);
					ReplaceTex("egm1eggman", "s_hando2", "Eggman", "DXD", "s_hando2", 420044, 32, 32);
					ReplaceTex("egm1eggman", "s_testhand", "Eggman", "DXD", "s_testhand", 420045, 64, 64);
					ReplaceTex("egm1eggman", "kan_s", "Eggman", "DXD", "kan_s", 500987, 64, 64);
					ReplaceTex("egm1eggman", "eghada", "Eggman", "DXD", "eghada", 500998, 8, 8);
					ReplaceTex("egm1eggman", "eghana", "Eggman", "DXD", "eghana", 500999, 8, 8);
					ReplaceTex("egm2_common", "e_fuku03", "Eggman", "DXD", "e_fuku03", 406042, 32, 32);
					ReplaceTex("egm2_common", "e_fuku02", "Eggman", "DXD", "e_fuku02", 406043, 64, 64);
					ReplaceTex("egm2_common", "kan_g", "Eggman", "DXD", "kan_g", 406045, 64, 64);
					ReplaceTex("egm2_common", "kan_m", "Eggman", "DXD", "kan_m", 406046, 64, 64);
					ReplaceTex("egm2_common", "e_hige", "Eggman", "DXD", "e_hige", 406047, 64, 64);
					ReplaceTex("egm2_common", "e_fuku04", "Eggman", "DXD", "e_fuku04", 406048, 32, 32);
					ReplaceTex("egm2_common", "e_fuku01", "Eggman", "DXD", "e_fuku01", 406049, 32, 32);
					ReplaceTex("egm2_common", "s_hando2", "Eggman", "DXD", "s_hando2", 406051, 32, 32);
					ReplaceTex("egm2_common", "s_testhand", "Eggman", "DXD", "s_testhand", 406052, 64, 64);
					ReplaceTex("egm3mdl", "e_fuku03", "Eggman", "DXD", "e_fuku03", 420035, 32, 32);
					ReplaceTex("egm3mdl", "e_fuku02", "Eggman", "DXD", "e_fuku02", 420036, 64, 64);
					ReplaceTex("egm3mdl", "kan_g", "Eggman", "DXD", "kan_g", 420038, 64, 64);
					ReplaceTex("egm3mdl", "kan_m", "Eggman", "DXD", "kan_m", 420039, 64, 64);
					ReplaceTex("egm3mdl", "e_hige", "Eggman", "DXD", "e_hige", 420040, 64, 64);
					ReplaceTex("egm3mdl", "e_fuku04", "Eggman", "DXD", "e_fuku04", 420041, 32, 32);
					ReplaceTex("egm3mdl", "e_fuku01", "Eggman", "DXD", "e_fuku01", 420042, 32, 32);
					ReplaceTex("egm3mdl", "s_hando2", "Eggman", "DXD", "s_hando2", 420044, 32, 32);
					ReplaceTex("ev_eggman_body", "s_hando2", "Eggman", "DXD", "s_hando2", 600140, 32, 32);
					ReplaceTex("ev_eggman_body", "e_fuku01", "Eggman", "DXD", "e_fuku01", 600142, 32, 32);
					ReplaceTex("ev_eggman_body", "e_fuku02", "Eggman", "DXD", "e_fuku02", 600143, 64, 64);
					ReplaceTex("ev_eggman_body", "e_fuku03", "Eggman", "DXD", "e_fuku03", 600144, 32, 32);
					ReplaceTex("ev_eggman_body", "e_fuku04", "Eggman", "DXD", "e_fuku04", 600145, 32, 32);
					ReplaceTex("ev_eggman_body", "e_hige", "Eggman", "DXD", "e_hige", 600146, 64, 64);
					ReplaceTex("ev_eggman_body", "eghada", "Eggman", "DXD", "eghada", 600158, 8, 8);
					ReplaceTex("ev_eggman_body", "eghana", "Eggman", "DXD", "eghana", 600159, 8, 8);
					ReplaceTex("ev_eggman_body", "kan_g", "Eggman", "DXD", "kan_g", 600164, 64, 64);
					ReplaceTex("ev_eggman_body", "kan_m", "Eggman", "DXD", "kan_m", 600165, 64, 64);
					ReplaceTex("ev_eggman_body", "s_testhand", "Eggman", "DXD", "s_testhand", 600169, 64, 64);
					ReplaceTex("ev_eggman_body", "kan_s", "Eggman", "DXD", "kan_s", 600226, 64, 64);
					ReplaceTex("ev_eggmoble0", "s_hando2", "Eggman", "DXD", "s_hando2", 710359, 32, 32);
					ReplaceTex("ev_eggmoble0", "e_fuku01", "Eggman", "DXD", "e_fuku01", 710332, 32, 32);
					ReplaceTex("ev_eggmoble0", "e_fuku02", "Eggman", "DXD", "e_fuku02", 710333, 64, 64);
					ReplaceTex("ev_eggmoble0", "e_fuku03", "Eggman", "DXD", "e_fuku03", 710334, 32, 32);
					ReplaceTex("ev_eggmoble0", "e_fuku04", "Eggman", "DXD", "e_fuku04", 710335, 32, 32);
					ReplaceTex("ev_eggmoble0", "e_hige", "Eggman", "DXD", "e_hige", 710336, 64, 64);
					ReplaceTex("ev_eggmoble0", "eghada", "Eggman", "DXD", "eghada", 710348, 8, 8);
					ReplaceTex("ev_eggmoble0", "eghana", "Eggman", "DXD", "eghana", 710349, 8, 8);
					ReplaceTex("ev_eggmoble0", "kan_g", "Eggman", "DXD", "kan_g", 710354, 64, 64);
					ReplaceTex("ev_eggmoble0", "kan_m", "Eggman", "DXD", "kan_m", 710355, 64, 64);
					ReplaceTex("ev_eggmoble0", "kan_s", "Eggman", "DXD", "kan_s", 710356, 64, 64);
					ReplaceTex("ev_eggmoble0", "kan_y", "Eggman", "DXD", "kan_y", 710357, 64, 64);
					ReplaceTex("ev_eggmoble0", "s_testhand", "Eggman", "DXD", "s_testhand", 710360, 64, 64);
					ReplaceTex("mrace_eggmoble", "e_fuku03", "Eggman", "DXD", "e_fuku03", 420035, 32, 32);
					ReplaceTex("mrace_eggmoble", "e_fuku02", "Eggman", "DXD", "e_fuku02", 420036, 64, 64);
					ReplaceTex("mrace_eggmoble", "kan_g", "Eggman", "DXD", "kan_g", 420038, 64, 64);
					ReplaceTex("mrace_eggmoble", "kan_m", "Eggman", "DXD", "kan_m", 420039, 64, 64);
					ReplaceTex("mrace_eggmoble", "e_hige", "Eggman", "DXD", "e_hige", 420040, 64, 64);
					ReplaceTex("mrace_eggmoble", "e_fuku04", "Eggman", "DXD", "e_fuku04", 420041, 32, 32);
					ReplaceTex("mrace_eggmoble", "e_fuku01", "Eggman", "DXD", "e_fuku01", 420042, 32, 32);
					ReplaceTex("mrace_eggmoble", "s_hando2", "Eggman", "DXD", "s_hando2", 420044, 32, 32);
				}

				if (KindofTextDX == OriginalDX)
				{
					if (Consistency == true)
					{
						ReplacePVM("Eggman", "Eggman_dxlsa2");
						ReplaceTex("chaos6_eggman", "e_fuku03", "Eggman", "DXLSA2", "e_fuku03", 420035, 32, 32);
						ReplaceTex("chaos6_eggman", "e_fuku02", "Eggman", "DXLSA2", "e_fuku02", 420036, 64, 64);
						ReplaceTex("chaos6_eggman", "kan_g", "Eggman", "DXLSA2", "kan_g", 420038, 64, 64);
						ReplaceTex("chaos6_eggman", "kan_m", "Eggman", "DXLSA2", "kan_m", 420039, 64, 64);
						ReplaceTex("chaos6_eggman", "e_hige", "Eggman", "DXLSA2", "e_hige", 420040, 64, 64);
						ReplaceTex("chaos6_eggman", "e_fuku04", "Eggman", "DXLSA2", "e_fuku04", 420041, 32, 32);
						ReplaceTex("chaos6_eggman", "e_fuku01", "Eggman", "DXLSA2", "e_fuku01", 420042, 32, 32);
						ReplaceTex("chaos6_eggman", "s_hando2", "Eggman", "DXLSA2", "s_hando2", 420044, 32, 32);
						ReplaceTex("egm1eggman", "e_fuku03", "Eggman", "DXLSA2", "e_fuku03", 420035, 32, 32);
						ReplaceTex("egm1eggman", "e_fuku02", "Eggman", "DXLSA2", "e_fuku02", 420036, 64, 64);
						ReplaceTex("egm1eggman", "kan_m", "Eggman", "DXLSA2", "kan_m", 420039, 64, 64);
						ReplaceTex("egm1eggman", "e_hige", "Eggman", "DXLSA2", "e_hige", 420040, 64, 64);
						ReplaceTex("egm1eggman", "e_fuku04", "Eggman", "DXLSA2", "e_fuku04", 420041, 32, 32);
						ReplaceTex("egm1eggman", "e_fuku01", "Eggman", "DXLSA2", "e_fuku01", 420042, 32, 32);
						ReplaceTex("egm1eggman", "s_hando2", "Eggman", "DXLSA2", "s_hando2", 420044, 32, 32);
						ReplaceTex("egm1eggman", "s_testhand", "Eggman", "DXLSA2", "s_testhand", 420045, 64, 64);
						ReplaceTex("egm1eggman", "kan_s", "Eggman", "DXLSA2", "kan_s", 500987, 64, 64);
						ReplaceTex("egm1eggman", "eghada", "Eggman", "DXLSA2", "eghada", 500998, 8, 8);
						ReplaceTex("egm1eggman", "eghana", "Eggman", "DXLSA2", "eghana", 500999, 8, 8);
						ReplaceTex("egm2_common", "e_fuku03", "Eggman", "DXLSA2", "e_fuku03", 406042, 32, 32);
						ReplaceTex("egm2_common", "e_fuku02", "Eggman", "DXLSA2", "e_fuku02", 406043, 64, 64);
						ReplaceTex("egm2_common", "kan_g", "Eggman", "DXLSA2", "kan_g", 406045, 64, 64);
						ReplaceTex("egm2_common", "kan_m", "Eggman", "DXLSA2", "kan_m", 406046, 64, 64);
						ReplaceTex("egm2_common", "e_hige", "Eggman", "DXLSA2", "e_hige", 406047, 64, 64);
						ReplaceTex("egm2_common", "e_fuku04", "Eggman", "DXLSA2", "e_fuku04", 406048, 32, 32);
						ReplaceTex("egm2_common", "e_fuku01", "Eggman", "DXLSA2", "e_fuku01", 406049, 32, 32);
						ReplaceTex("egm2_common", "s_hando2", "Eggman", "DXLSA2", "s_hando2", 406051, 32, 32);
						ReplaceTex("egm2_common", "s_testhand", "Eggman", "DXLSA2", "s_testhand", 406052, 64, 64);
						ReplaceTex("egm3mdl", "e_fuku03", "Eggman", "DXLSA2", "e_fuku03", 420035, 32, 32);
						ReplaceTex("egm3mdl", "e_fuku02", "Eggman", "DXLSA2", "e_fuku02", 420036, 64, 64);
						ReplaceTex("egm3mdl", "kan_g", "Eggman", "DXLSA2", "kan_g", 420038, 64, 64);
						ReplaceTex("egm3mdl", "kan_m", "Eggman", "DXLSA2", "kan_m", 420039, 64, 64);
						ReplaceTex("egm3mdl", "e_hige", "Eggman", "DXLSA2", "e_hige", 420040, 64, 64);
						ReplaceTex("egm3mdl", "e_fuku04", "Eggman", "DXLSA2", "e_fuku04", 420041, 32, 32);
						ReplaceTex("egm3mdl", "e_fuku01", "Eggman", "DXLSA2", "e_fuku01", 420042, 32, 32);
						ReplaceTex("egm3mdl", "s_hando2", "Eggman", "DXLSA2", "s_hando2", 420044, 32, 32);
						ReplaceTex("ev_eggman_body", "s_hando2", "Eggman", "DXLSA2", "s_hando2", 600140, 32, 32);
						ReplaceTex("ev_eggman_body", "e_fuku01", "Eggman", "DXLSA2", "e_fuku01", 600142, 32, 32);
						ReplaceTex("ev_eggman_body", "e_fuku02", "Eggman", "DXLSA2", "e_fuku02", 600143, 64, 64);
						ReplaceTex("ev_eggman_body", "e_fuku03", "Eggman", "DXLSA2", "e_fuku03", 600144, 32, 32);
						ReplaceTex("ev_eggman_body", "e_fuku04", "Eggman", "DXLSA2", "e_fuku04", 600145, 32, 32);
						ReplaceTex("ev_eggman_body", "e_hige", "Eggman", "DXLSA2", "e_hige", 600146, 64, 64);
						ReplaceTex("ev_eggman_body", "eghada", "Eggman", "DXLSA2", "eghada", 600158, 8, 8);
						ReplaceTex("ev_eggman_body", "eghana", "Eggman", "DXLSA2", "eghana", 600159, 8, 8);
						ReplaceTex("ev_eggman_body", "kan_g", "Eggman", "DXLSA2", "kan_g", 600164, 64, 64);
						ReplaceTex("ev_eggman_body", "kan_m", "Eggman", "DXLSA2", "kan_m", 600165, 64, 64);
						ReplaceTex("ev_eggman_body", "s_testhand", "Eggman", "DXLSA2", "s_testhand", 600169, 64, 64);
						ReplaceTex("ev_eggman_body", "kan_s", "Eggman", "DXLSA2", "kan_s", 600226, 64, 64);
						ReplaceTex("ev_eggmoble0", "s_hando2", "Eggman", "DXLSA2", "s_hando2", 710359, 32, 32);
						ReplaceTex("ev_eggmoble0", "e_fuku01", "Eggman", "DXLSA2", "e_fuku01", 710332, 32, 32);
						ReplaceTex("ev_eggmoble0", "e_fuku02", "Eggman", "DXLSA2", "e_fuku02", 710333, 64, 64);
						ReplaceTex("ev_eggmoble0", "e_fuku03", "Eggman", "DXLSA2", "e_fuku03", 710334, 32, 32);
						ReplaceTex("ev_eggmoble0", "e_fuku04", "Eggman", "DXLSA2", "e_fuku04", 710335, 32, 32);
						ReplaceTex("ev_eggmoble0", "e_hige", "Eggman", "DXLSA2", "e_hige", 710336, 64, 64);
						ReplaceTex("ev_eggmoble0", "eghada", "Eggman", "DXLSA2", "eghada", 710348, 8, 8);
						ReplaceTex("ev_eggmoble0", "eghana", "Eggman", "DXLSA2", "eghana", 710349, 8, 8);
						ReplaceTex("ev_eggmoble0", "kan_g", "Eggman", "DXLSA2", "kan_g", 710354, 64, 64);
						ReplaceTex("ev_eggmoble0", "kan_m", "Eggman", "DXLSA2", "kan_m", 710355, 64, 64);
						ReplaceTex("ev_eggmoble0", "kan_s", "Eggman", "DXLSA2", "kan_s", 710356, 64, 64);
						ReplaceTex("ev_eggmoble0", "kan_y", "Eggman", "DXLSA2", "kan_y", 710357, 64, 64);
						ReplaceTex("ev_eggmoble0", "s_testhand", "Eggman", "DXLSA2", "s_testhand", 710360, 64, 64);
						ReplaceTex("mrace_eggmoble", "e_fuku03", "Eggman", "DXLSA2", "e_fuku03", 420035, 32, 32);
						ReplaceTex("mrace_eggmoble", "e_fuku02", "Eggman", "DXLSA2", "e_fuku02", 420036, 64, 64);
						ReplaceTex("mrace_eggmoble", "kan_g", "Eggman", "DXLSA2", "kan_g", 420038, 64, 64);
						ReplaceTex("mrace_eggmoble", "kan_m", "Eggman", "DXLSA2", "kan_m", 420039, 64, 64);
						ReplaceTex("mrace_eggmoble", "e_hige", "Eggman", "DXLSA2", "e_hige", 420040, 64, 64);
						ReplaceTex("mrace_eggmoble", "e_fuku04", "Eggman", "DXLSA2", "e_fuku04", 420041, 32, 32);
						ReplaceTex("mrace_eggmoble", "e_fuku01", "Eggman", "DXLSA2", "e_fuku01", 420042, 32, 32);
						ReplaceTex("mrace_eggmoble", "s_hando2", "Eggman", "DXLSA2", "s_hando2", 420044, 32, 32);
					}

					else
					{
						ReplacePVM("Eggman", "Eggman_dx");
					}
				}
			}
		}
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}