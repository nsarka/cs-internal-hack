#pragma once

#include <windows.h>
#include <vector>
#include <tlhelp32.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>
//#include <gl\GL.h>

using namespace std;

//#pragma comment(lib, "OpenGL32.lib")

#include "HLSDK/engine/wrect.h"
#include "HLSDK/engine/cl_dll.h"
#include "HLSDK/engine/cdll_int.h"
#include "HLSDK/engine/const.h"
#include "HLSDK/engine/progdefs.h"
#include "HLSDK/engine/eiface.h"
#include "HLSDK/engine/edict.h"
#include "HLSDK/engine/studio_event.h"
#include "HLSDK/engine/entity_types.h"
#include "HLSDK/engine/r_efx.h"
#include "HLSDK/engine/pmtrace.h"
#include "HLSDK/engine/studio.h"
#include "HLSDK/common/ref_params.h"
#include "HLSDK/common/screenfade.h"
#include "HLSDK/common/event_api.h"
#include "HLSDK/common/com_model.h"
#include "HLSDK/common/net_api.h"
#include "HLSDK/common/ivoicetweak.h"
#include "HLSDK/misc/parsemsg.h"
#include "HLSDK/misc/sprites.h"
#include "HLSDK/misc/r_studioint.h"
#include "HLSDK/engine/triangleapi.h"
#include "HLSDK/engine/pm_defs.h"