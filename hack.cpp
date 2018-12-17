#include "SDK.h"

cl_enginefunc_t *pEnginefuncs = NULL;
cl_enginefunc_t gEngfuncs;

void Thread(void)
{
    DWORD dwHWDLL = (DWORD)GetModuleHandle("hw.dll");

	if(!dwHWDLL) {
		MessageBox(NULL, "Cant find hw.dll", "Cant find hw.dll", MB_OK);
	}

	/*
https://www.unknowncheats.me/forum/counterstrike-1-5-1-6-and-mods/125661-cs1-6-finding-offsets.html

0494833F | 6A 07                    | push 0x7                                                   |
04948341 | 68 986AA904              | push hw.4A96A98                                            |
04948346 | FF15 20E3B205            | call dword ptr ds:[<&Initialize>]                          |

		0x00166A98 (offset of engine) = 0x4A96A98 - hw.dll base (0x04930000)
	*/
    pEnginefuncs = (cl_enginefunc_t*)(dwHWDLL + 0x00166A98); // first argument of dllexport Initialize in client.dll
	memcpy(&gEngfuncs, pEnginefuncs, sizeof(cl_enginefunc_t));

	gEngfuncs.Con_Printf("Hack loaded\n");

	while(true)
	{
        //cl_entity_t *player = gEngfuncs.GetLocalPlayer();
		//gEngfuncs.Con_Printf("x: %f y: %f z: %f\n", player->origin[0], player->origin[1], player->origin[2]);


		// No flash
		screenfade_t fade;
		gEngfuncs.pfnGetScreenFade(&fade);

		if(fade.fadealpha > 0) {
			fade.fadealpha = 30; // set to 30 but for some reason it gets rid of the flash entirely.. i'm not complaining
			gEngfuncs.pfnSetScreenFade(&fade);
		}
    }
}


BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch(fdwReason)
	{
	case DLL_PROCESS_ATTACH:

		CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)Thread,NULL,NULL,NULL);
		//MessageBox(NULL, "Hack.dll: injected", "Injection", MB_OK);

		break;
	}

	return true;
}