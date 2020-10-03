//Библиотеки
#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
#include <windows.h>
#include <windowsx.h>
#include <string>
#include <locale.h>
#include <Uxtheme.h>
#include <cstdlib>
#include <Dwmapi.h>
#include <wingdi.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <strsafe.h>
#include <fstream>
#include <iostream>
#include <Commctrl.h>
#include <winuser.h>
#include <shellapi.h>
#include <cassert> 
#include <Winerror.h> 
#include <ShlObj_core.h>
#include <commdlg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <objidl.h>
#include <Wininet.h> 
#include <eh.h>
#include <comdef.h>
#include <objidl.h>
#include <gdiplus.h>
#include "resource.h"
#include <process.h>
#include <regex>
#include <cstdio>
#include <string>
#include <iostream>
#include <atlbase.h>
#include <atlconv.h>
#include <atlstr.h>
#include <locale>
#include <codecvt>
#include <string>
using namespace std;
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")
#pragma comment(lib, "wininet.lib")
#pragma comment(lib,"Msimg32.lib")
#pragma comment(lib, "dwmapi")
#pragma comment( lib, "Version.lib" )
#include "bibl/lodepng_picoPNG.h"
#include "bibl/GetGdiplusEncoderClsid.h"
#include "bibl/WSTRINGTOSTRING.h"
#include "bibl/Loading_Curl_File_Pro.h"

#define IDT_TIMER_loadingSTART 15000