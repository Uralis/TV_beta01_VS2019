#include "bibl/biblfile.h"
static HANDLE BMPLOADINGIMG_LOADING, BMPLOADINGIMG_NOLOGOTV;
static HANDLE IPTVLOGOPNGTOBMP[10000];
//цвета png
static HANDLE BLACK_PNG, WHITE_PNG, GREY_PNG;
HBITMAP BLACK_PNG_, WHITE_PNG_, GREY_PNG_;
static string ____red;
static string ____black;
static string ____white;
static string ____grey;
static HDC hCompatibleDCBackground, hCompatibleDCBackground_loading;
static HANDLE hOldBitmapBackground, hOldBitmapBackground_loading;
static int shirina_data = 1024, visota_data = 600, launSYS = GetSystemDefaultLangID();
static int shirina_data_loading = 250, visota_data_loading = 120;
string okkkk;
wstring sdsdsd;
////////////////////////////////////////////////////////////////////
//компоненты (активность)
static int colesiko = 0;//для колесика 
static int colesiko_ot = 0;//для колесика 
static int cursoroknoactiv = 0;
static int fgfdgefdrhrcolesico = 0;
static int dawdwda44gf = 0;
static int start_cmd_arh = -1;
////////////////////////////////////////////////////////////////////
TCHAR imgresload_id1[300];
TCHAR imgresload_id6[300];
TCHAR imgresload_id7[300];
TCHAR imgresload_id8[300];
////////////////////////Параметры для левого блока//////////////////
int reshimpokaza = 1; //0 - gdi+ 1 - gdi+ to bmp
int bmp_pngstid1 = 0; //0 - *(gdi+) - 1 - bmp(стандарт)
int prozrachnosti__ = 0; //0 выключено 1 - включено
int shirinablock__ = 32;//shirina img logo
int vitotablock__ = 32; //vitota img logo
////////////////////////////////////////////////////////////////////
string namelocalfile__logo[10000];
string namelocalfile__logo_png[10000];
string namelocalfile__logo_jpg[10000];
string namelocalfile__logo_bmp[10000];
////////////////////////////////////////////////////////////////////
static int imgloadingproc1;
static int activmass_levcon_img_info[10][15000];//массив кнопок
static RECT r = {};//массив размеров окна
#define TIMER_INTERNETPROVERKA 103001 //проверка интернета (время)
#define TIMER_CLICKDOUBLE_FULLSCREEN 103002 //проверка двойного нажатия (время)
#define TIMER_OBNOVLENIE 103003 //обновление экрана
wchar_t DATANAMEIN_text_wchar_ENG[100], DATANAMEIN_text_wchar_RU[100];
string DATANAMEIN_ENG = "Launcher TV",
DATANAMEIN_RU = "Лаунчер TV",
datapapkas = ".APVRU", //главная папка
datapapkasproject = "IPTVPRO",//папка компонентов
datapapkasok = "\\" + datapapkas + "\\" + datapapkasproject + "\\", infola;
static string tekstloading_ = "";//статус загрузки (обновление)
static string versionInfoOk = "";//номер версий (обновление)
static int exit_, internet_file, infoint = 0, internet = -1;
static string language, data_appdata0, dataproj;
static const wchar_t* lp_infocdexe;
WCHAR path_appdata[MAX_PATH]; //(обновление)
TCHAR buffercddata[MAX_PATH];//(обновление)
int dawdawdawd = 0;
static int stmenuloading, stmenuloading__0, stmenuloading__1, stmenuloading__2, stmenu, staticdowtxt1, staticdowtxt0 = 0;//сч. если скачана информация о новой версий
HINSTANCE hInst;
static POINT pt;
static int visualfpl, onko_info, visualswf, visuakok = 0;
static int infoint_ru0, infoint_ru1, infoint_eng0, infoint_eng1;//индекс интерфейса языка (ВИДИМОСТЬ ПЕРЕКЛЮЧАТЕЛЕЙ)
static string urldfilest1_swf, urldfilest2_swf, urldfilest1_name, urldfilest2_name;
int ots11 = 50; static int loadinheg, loadinhegs = -ots11, loadinhegst = 0;
static int click_count, click_count1, click_count2, click_count3 = 0;
WINDOWPLACEMENT wpc; //положение окна fullcreen
bool FullScreen = false;//статус fullcreen
static int idloadchan = 2;//id активного канала
////////////////////parser m3u
///////////////Общие массивы (для обработки)
string basedataid1_namedata_text_EXTM3U[10000];//массив epg
string basedataid1_namedata_text_EXTINF[10000];//массив каналов (общее)
string basedataid1_namedata_text_URL[10000];// массив url
string basedataid1_EXTINF_name_razelen[10000];//массив данных без названия каналов
///////////////Массивы отсортированных данных из общих*
string basedataid1_EXTINF_name_[10000];//массив названий каналов после ,
wstring wstring_basedataid1_EXTINF_name_[10000];//массив group-title (название группы)
string nom_basedataid1_EXTINF_name_[10000];//(с номером)массив названий каналов после ,
wstring nom_wstring_basedataid1_EXTINF_name_[10000];//(с номером)массив group-title (название группы)
string basedataid1_tvg_id_name_[10000];//массив tvg-id (id канала для подхвата EPG.)
string basedataid1_channel_id_name_[10000];//массив channel-id (некоторые программы просмотра могут определить из этого параметра номер канала)
string basedataid1_tvg_name_name_[10000];//массив tvg-name (название канала) - дополнительное
string basedataid1_group_title_name_[10000];//массив group-title (название группы)
string basedataid1_tvg_logo_name_[10000];//массив tvg-logo (png, jpg) сссылка на img
wstring wstring_basedataid1_tvg_logo_name_[10000];//массив tvg-logo (png, jpg) сссылка на img
string basedataid1_aspect_ratio_name_[10000];//массив aspect-ratio (указание формата изображения - Доступные значения: 16:9, 3:2, 4:3, 1,85:1, 2,39:1.)
string basedataid1_radio_name_[10000];//массив radio (флаг, показывающий, что группа каналов или канал относятся к радио. Если tag отсутствует, будет использовано значение текущей группы (если она существует).)
string basedataid1_audio_track_name_[10000];//массив audio-track (определение аудиодорожки в канале, если это поддерживается потоком. Запись языковых кодов осуществляется по стандарту ISO 639-2, можно использовать несколько кодов, разделённых запятыми, т.е. "eng, rus, deu". Первое значение в списке используется как значение по умолчанию.)
string basedataid1_catchup_days_name_[10000];//массив catchup-days (сколько дней имеется архив)
string basedataid1_catchup_source_name_[10000];//массив catchup-source (time для работы с архивом)
string basedataid1_catchup_name_[10000];//массив catchup
//количество каналов, если файл не открыт, если нет epg - 1
static int basedataid1_status_kolvo_EXTINF, erorfile, epgok = 0;
/////////////////////////
string imgpapkaurlput[10000];
static TCHAR img_ICO_er[300];
static int loadingok_;
int shirinamenuid1 = 250, visotablokamenuid1 = 40, OTSTUPmenuid1 = 0, OTSTUPmenuid_1 = 4;
LRESULT CALLBACK LoadingProc(HWND hWnd, UINT uMsg, WPARAM WParam, LPARAM lParam);
HINSTANCE g_hInst; HWND hWndMain1;
LPCTSTR lpszClassNameLoading = TEXT("LoadingPRO");
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR nCmdLine, int nCmdShow) {
	setlocale(LC_ALL, "Russian");
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;

	//Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	//Получение папки с содержимым и номер версий
	{
		//обработка названи¤ окна (преобразование)
		{
			const char* DATANAMEIN_text_char_ENG = DATANAMEIN_ENG.c_str();
			size_t DATANAMEIN_length_ENG = strlen(DATANAMEIN_text_char_ENG);
			const char* DATANAMEIN_text_char_RU = DATANAMEIN_RU.c_str();
			size_t DATANAMEIN_length_RU = strlen(DATANAMEIN_text_char_RU);
			mbstowcs_s(&DATANAMEIN_length_ENG, DATANAMEIN_text_wchar_ENG, DATANAMEIN_text_char_ENG, DATANAMEIN_length_ENG);
			mbstowcs_s(&DATANAMEIN_length_RU, DATANAMEIN_text_wchar_RU, DATANAMEIN_text_char_RU, DATANAMEIN_length_RU);
		}
		//получаем путь к %appdata%
		{
			////////////////////////////////////////////////////////////////////////////
			HRESULT result = SHGetFolderPath(NULL, CSIDL_APPDATA | CSIDL_FLAG_CREATE, NULL, SHGFP_TYPE_CURRENT, path_appdata);		
	
			char ch[2000];
			char DefChar = ' ';
			WideCharToMultiByte(CP_ACP, 0, path_appdata, -1, ch, 2000, &DefChar, NULL);
			string data_appdata1000(ch);
			data_appdata0 = data_appdata1000;
			////////////////////////////////////////////////////////////////////////////
			language = data_appdata0 + datapapkasok + "language.proural";
			dataproj = data_appdata0 + datapapkasok;//полный путь к appdata папке
		}
		//получаем номер версии
		{
			///////////////
			GetModuleFileName(NULL, buffercddata, sizeof(buffercddata) / sizeof(buffercddata[0]));
			char ch1[2000];
			char DefChar1 = ' ';
			WideCharToMultiByte(CP_ACP, 0, buffercddata, -1, ch1, 2000, &DefChar1, NULL);
			///////////////
			std::string data_appdata1001(ch1);
			string datacd = data_appdata1001;
			string infocdexe_0 = datacd.c_str();//адрес к exe 0
			wstring infocdexe_1 = wstring(infocdexe_0.begin(), infocdexe_0.end());
			lp_infocdexe = infocdexe_1.c_str();//адрес к exe (LPCWSTR)
			///////////////
			TCHAR dwLeftMost__[100], dwSecondLeft__[100], dwSecondRight__[100], dwRightMost__[100];
			DWORD dwDummy;
			DWORD dwFVISize = GetFileVersionInfoSize(buffercddata, &dwDummy);
			LPBYTE lpVersionInfo = new BYTE[dwFVISize];
			GetFileVersionInfo(buffercddata, 0, dwFVISize, lpVersionInfo);
			UINT uLen;
			VS_FIXEDFILEINFO * lpFfi;
			VerQueryValue(lpVersionInfo, _T("\\"), (LPVOID*)& lpFfi, &uLen);
			DWORD dwFileVersionMS = lpFfi->dwFileVersionMS;
			DWORD dwFileVersionLS = lpFfi->dwFileVersionLS;
			delete[] lpVersionInfo;
			DWORD dwLeftMost = HIWORD(dwFileVersionMS);
			DWORD dwSecondLeft = LOWORD(dwFileVersionMS);
			DWORD dwSecondRight = HIWORD(dwFileVersionLS);
			DWORD dwRightMost = LOWORD(dwFileVersionLS);
			_stprintf_s(dwLeftMost__, _T("%d"), dwLeftMost);
			_stprintf_s(dwSecondLeft__, _T("%d"), dwSecondLeft);
			_stprintf_s(dwSecondRight__, _T("%d"), dwSecondRight);
			_stprintf_s(dwRightMost__, _T("%d"), dwRightMost);
			char ver1_ch[2000], ver2_ch[2000];
			char ver1_DefChar, ver2_DefChar = ' ';
			WideCharToMultiByte(CP_ACP, 0, dwSecondLeft__, -1, ver2_ch, 2000, &ver2_DefChar, NULL);
			WideCharToMultiByte(CP_ACP, 0, dwLeftMost__, -1, ver1_ch, 2000, &ver1_DefChar, NULL);
			string ver1_data_appdata1000(ver1_ch), ver2_data_appdata1000(ver2_ch);
			versionInfoOk = ver1_data_appdata1000 + "." + ver2_data_appdata1000;
		}
	}
	//загрузка PNG TO BMP


	//string ddsdsd = "0.png";
	//CA2W pszWide(ddsdsd.c_str(), CP_UTF8);

	//BMPLOADINGIMG_NOLOGOTV = mLoadImg(pszWide);//NOLOGO tv

	BMPLOADINGIMG_LOADING = LoadPNG_BMP(hInstance, MAKEINTRESOURCE(PNG_FONLOADING));//img loading pro
	BMPLOADINGIMG_NOLOGOTV = LoadPNG_BMP(hInstance, MAKEINTRESOURCE(PNG_NOLOGO));//NOLOGO tv

	BLACK_PNG = (HBITMAP)LoadPNG_BMP(hInstance, MAKEINTRESOURCE(PNG_black));//Черный
	WHITE_PNG = (HBITMAP)LoadPNG_BMP(hInstance, MAKEINTRESOURCE(PNG_white));//Белый
	GREY_PNG = (HBITMAP)LoadPNG_BMP(hInstance, MAKEINTRESOURCE(PNG_grey));//Серый

	HWND hWnd;
	MSG msg;
	g_hInst = hInstance;
	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;//CS_HREDRAW | CS_VREDRAW - CS_DBLCLKS
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = 0;//(HBRUSH)(COLOR_WINDOW+1)
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = (HICON)LoadImage(hInstance, MAKEINTRESOURCE(IDI_ICON1),
		IMAGE_ICON, 48, 48, LR_DEFAULTCOLOR);
	wc.hIconSm = (HICON)LoadImage(hInstance, MAKEINTRESOURCE(IDI_ICON1),
		IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
	wc.lpfnWndProc = LoadingProc;
	wc.lpszClassName = lpszClassNameLoading;
	wc.lpszMenuName = NULL;
	wc.hInstance = hInstance;
	RegisterClassEx(&wc);

	hWnd = CreateWindow(
		lpszClassNameLoading,
		DATANAMEIN_text_wchar_ENG,
		WS_POPUP,
		(GetSystemMetrics(SM_CXSCREEN) - shirina_data_loading) / 2,
		(GetSystemMetrics(SM_CYSCREEN) - visota_data_loading) / 2,
		shirina_data_loading,
		visota_data_loading,
		NULL,
		NULL,
		hInstance,
		0);

	if (!hWnd) {
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	GdiplusShutdown(gdiplusToken);
	return msg.wParam;
}
UINT_PTR Timer1IdEvent_loadingSTART;
VOID CALLBACK TimerProc(HWND hWnd,
	UINT uMsg,
	UINT idEvent,
	DWORD dwTime)
{
	if (Timer1IdEvent_loadingSTART == idEvent) {
		ShowWindow(hWnd, SW_SHOW);
		KillTimer(hWnd, idEvent);
	}
}
#include "WM_PAINT.h"
#include "WM_SETCURSOR.h"
#include "WINAPI LoadingResource.h"
#include "CALLBACK LoadingProc.h"