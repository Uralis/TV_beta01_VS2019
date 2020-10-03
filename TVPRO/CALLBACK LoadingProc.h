LRESULT CALLBACK LoadingProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	setlocale(LC_ALL, "Russian");
	//////////////////////������ � ������������ �� ��. ����
	static BOOL fInWindow = false;
	TRACKMOUSEEVENT tme;
	tme.cbSize = sizeof(TRACKMOUSEEVENT);
	tme.hwndTrack = hWnd;//hanlde of window you want the mouse over message for.
	tme.dwHoverTime = HOVER_DEFAULT;
	//////////////////////
	HDC hdcMem, hdc;
	PAINTSTRUCT psd;
	HBITMAP hbmMem, hbmMem1;
	static  HGDIOBJ oldbr, oldbr1, oldbr2;
	HBRUSH brush; //���������� brush - ��� �����, ��� ����� �������������� ��� ������������	
	switch (uMsg) {
	case WM_CREATE:
	{
		string img_ICO_hknopka21_er = data_appdata0 + datapapkasok + "0.png";
		StringCchPrintf(img_ICO_er, 300, TEXT("%hs"), (img_ICO_hknopka21_er));
		string img_ICO_hknopka21_er1 = data_appdata0 + datapapkasok + "E.png";
		StringCchPrintf(imgresload_id6, 300, TEXT("%hs"), (img_ICO_hknopka21_er1));
		string img_ICO_hknopka21_er2 = data_appdata0 + datapapkasok + "R.png";
		StringCchPrintf(imgresload_id7, 300, TEXT("%hs"), (img_ICO_hknopka21_er2));
		string img_ICO_hknopka21_er23 = data_appdata0 + datapapkasok + "S.png";
		StringCchPrintf(imgresload_id8, 300, TEXT("%hs"), (img_ICO_hknopka21_er23));


		//�������� ��������� ��� ������� (�������� ���� ��������)
		{
			if (!InternetCheckConnectionW(L"http://google.com", FLAG_ICC_FORCE_CONNECTION, 0))
			{//���� ����
				internet = 0;
			}
			else
			{//���� ����
				internet = 1;
			}
			SetTimer(hWnd, TIMER_INTERNETPROVERKA, 3500, (TIMERPROC)NULL); //������ ��� �������� ��������� ����� ��������
			SetTimer(hWnd, TIMER_OBNOVLENIE, 8, (TIMERPROC)NULL); //������ ��� ���������� ��������� �������
		}
		// ������ ���� ����������
		{
			string lang_namedd1[1000] = { "Interface_language = " };
			ifstream lang_UrlFileCoder1(language);
			string lang_txtcdat1[1000];
			int lang_datanom1 = -1;
			while (lang_datanom1 < 100)
			{
				lang_datanom1 += 1;
				while (getline(lang_UrlFileCoder1, lang_txtcdat1[lang_datanom1])) {
					if (lang_txtcdat1[lang_datanom1].find(lang_namedd1[lang_datanom1]) != string::npos)
					{
						break;
					}
				}
			}
			infoint = atoi(lang_txtcdat1[0].erase(0, lang_namedd1[0].length()).c_str());
			if (infoint == 0)//���� �����
			{
				if (launSYS == 1049 || launSYS == 1058 || launSYS == 1059)//��� RU
				{
					infoint = 1;
				}
				else {
					infoint = 2;
				}
			}

			if (infoint == 1)
			{
				infola = "RU";
				infoint_ru0 = 255;
				infoint_eng0 = 150;
				//dataimagebase[10][7] = "255";
				//dataimagebase[11][7] = "150";
				SetWindowText(hWnd, DATANAMEIN_text_wchar_RU);
			}
			if (infoint == 2)
			{
				infola = "ENG";
				infoint_eng0 = 255;
				infoint_ru0 = 150;
				//dataimagebase[11][7] = "255";
				//dataimagebase[10][7] = "150";
				SetWindowText(hWnd, DATANAMEIN_text_wchar_ENG);
			}
		}
		//���� ��� ��������� ��� �������
		{
			if (internet == 0)
			{
				if (infoint == 1)//RU
				{
					MessageBoxA(NULL, "��� ������� ��������� �������� ����������!", "����������", MB_OK);
					exit_ = 1;
				}
				else {//ENG
					MessageBoxA(NULL, "Internet connection required to run!", "Information", MB_OK);
					exit_ = 1;
				}
			}
		}
		//����������� �������� �������� �� ��������� (�������������� �����)
		if (internet == 1)//���� ���� ��������
		{
			_beginthread(LoadingProc, 0, NULL);
		}
		stmenu = 0;
	}
	return 0;
	case WM_PAINT:
	{
		if (exit_ == 1) { DestroyWindow(hWnd); }//���� ��� ��������� ��������� ���������
		else
		{
			GetClientRect(hWnd, &r);
			hdc = BeginPaint(hWnd, &psd);
			hdcMem = CreateCompatibleDC(hdc);
			hbmMem1 = CreateCompatibleBitmap(hdc, r.right + 1, r.bottom + 1);
			hbmMem = (HBITMAP)SelectObject(hdcMem, hbmMem1);
			PatBlt(hdcMem, 0, 0, r.right + 1, r.bottom + 1, PATCOPY);
			SelectObject(hdcMem, CreatePen(PS_NULL, 0, RGB(0, 0, 0)));//������� �������
			hCompatibleDCBackground = CreateCompatibleDC(hdc);//img
			hCompatibleDCBackground_loading = CreateCompatibleDC(hdc);//img

			//dataimagebase[2][1] = to_string((r.right) - atoi(dataimagebase[2][3].c_str()));//����������� ������� �����
			//dataimagebase[3][3] = to_string((r.right) - (atoi(dataimagebase[2][3].c_str()) + atoi(dataimagebase[1][3].c_str())));//����������� �������� �����
			/////////////////////////////////////////////////////////////////////////////////////////////////
			if (stmenu == 1)
			{
				void_WM_PAINT(hWnd, hdcMem, oldbr, oldbr1, oldbr2);
			}
			//�������������� �������� (no_internet, loading program)
			{
				//AlphaBlend �������� � ������ (�����) (������� ��������)
				{
					string dataimagebaseloading[100][40] = {
					{"1", "0", "20", "250", "71", "0", "0", "0", "0", "*", "0", "0", "0", "250", "71", "BMP", "LoadinPro"}
					};
					BLENDFUNCTION blend;
					blend.BlendOp = AC_SRC_OVER;
					blend.BlendFlags = 0;
					blend.AlphaFormat = 0;
					blend.SourceConstantAlpha = 255;
					int dataimagedata = 0;

					if (dataimagebaseloading[dataimagedata][16] == "LoadinPro")
					{
						if (stmenu == 0 && loadingok_ == 0)
						{
							hOldBitmapBackground = SelectObject(hCompatibleDCBackground, BMPLOADINGIMG_LOADING);//img
							AlphaBlend(hdcMem, atoi(dataimagebaseloading[dataimagedata][1].c_str()), atoi(dataimagebaseloading[dataimagedata][2].c_str()), atoi(dataimagebaseloading[dataimagedata][3].c_str()), atoi(dataimagebaseloading[dataimagedata][4].c_str()), hCompatibleDCBackground, atoi(dataimagebaseloading[dataimagedata][11].c_str()), atoi(dataimagebaseloading[dataimagedata][12].c_str()), atoi(dataimagebaseloading[dataimagedata][3].c_str()), atoi(dataimagebaseloading[dataimagedata][4].c_str()), blend);
						}
					}
				}
				//�������� (���������)
				if (stmenu == 0 && loadingok_ == 0)
				{
					{
						//��� ��� ������
						oldbr = SelectObject(hdcMem, CreateSolidBrush(RGB(12, 29, 155)));
						Rectangle(hdcMem, 0, 0, r.right + 1, 21);
						DeleteObject(SelectObject(hdcMem, oldbr));
						//������ ��������
						oldbr = SelectObject(hdcMem, CreateSolidBrush(RGB(235, 239, 244)));
						Rectangle(hdcMem, 0, 91, r.right + 1, r.bottom + 1);
						DeleteObject(SelectObject(hdcMem, oldbr));
						//���������
						oldbr = SelectObject(hdcMem, CreateSolidBrush(RGB(2, 55, 182)));
						Rectangle(hdcMem, loadinhegs, 91, loadinheg, r.bottom + 1);
						DeleteObject(SelectObject(hdcMem, oldbr));
						{//������ �����
							wstring wstrTo;
							wchar_t* wszTo = new wchar_t[versionInfoOk.length() + 1];
							wszTo[versionInfoOk.size()] = L'\0';
							MultiByteToWideChar(CP_ACP, 0, versionInfoOk.c_str(), -1, wszTo, (int)versionInfoOk.length());
							SetBkMode(hdcMem, TRANSPARENT);
							SetTextColor(hdcMem, RGB(255, 255, 255));
							oldbr1 = CreateFont(14, 10, 0, 0, 1000, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
								DEFAULT_PITCH | FF_DONTCARE, (L"Arial"));
							oldbr2 = (HFONT)SelectObject(hdcMem, oldbr1);
							TextOut(hdcMem, 208, 23, wszTo, versionInfoOk.length());
							DeleteObject(oldbr1);
							DeleteObject(oldbr2);
						}

						{//����� ������ ��������
							wstring wstrTo;
							wchar_t* wszTo = new wchar_t[tekstloading_.length() + 1];
							wszTo[tekstloading_.size()] = L'\0';
							MultiByteToWideChar(CP_ACP, 0, tekstloading_.c_str(), -1, wszTo, (int)tekstloading_.length());
							SetBkMode(hdcMem, TRANSPARENT);
							SetTextColor(hdcMem, RGB(255, 255, 255));
							oldbr1 = CreateFont(14, 6, 0, 0, 1000, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
								DEFAULT_PITCH | FF_DONTCARE, (L"Arial"));
							oldbr2 = (HFONT)SelectObject(hdcMem, oldbr1);
							TextOut(hdcMem, 3, 3, wszTo, tekstloading_.length());
							DeleteObject(oldbr1);
							DeleteObject(oldbr2);
						}
					}
					Sleep(8);

					if (loadinheg == r.right + ots11)
					{
						loadinheg = 0;
						loadinhegs = -ots11;
						InvalidateRect(hWnd, NULL, FALSE);
					}
					else
					{
						loadinheg = loadinheg + 1;
						loadinhegs = loadinhegs + 1;
						InvalidateRect(hWnd, NULL, FALSE);
					}
				}
				//��������� ������� � ��������� ����� �������� 
				if (stmenuloading == 2)
				{
					stmenuloading = 1;
					//SetCursor(LoadCursor(NULL, IDC_HAND));
					loadingok_ = 1;
					ShowWindow(hWnd, SW_HIDE);
					stmenu = 1;
					SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) | WS_OVERLAPPEDWINDOW); //| WS_VISIBLE (��������)
					SetWindowPos(hWnd, 0, (GetSystemMetrics(SM_CXSCREEN) - shirina_data) / 2, (GetSystemMetrics(SM_CYSCREEN) - visota_data) / 2, shirina_data, visota_data, 0);
					InvalidateRect(hWnd, NULL, FALSE);
					Timer1IdEvent_loadingSTART = SetTimer(hWnd, IDT_TIMER_loadingSTART, 1000, (TIMERPROC)TimerProc);
				}
				//���� ������ �������� �� ����� ������
				if (internet == 0 && stmenu == 1)
				{
					static string tekstloading_internet = "";//������ ��������


					if (infoint == 1)//ru
					{
						tekstloading_internet = "��� ��������-����������. ��������� ����������� � ��������� �������";//������ ��������
					}
					if (infoint == 2)//eng
					{
						tekstloading_internet = "no internet connection. check the connection and try again";//������ ��������
					}

					{
						//��� ��� ������
						oldbr = SelectObject(hdcMem, CreateSolidBrush(RGB(190, 29, 55)));
						Rectangle(hdcMem, 0, 0, r.right + 1, 100);
						DeleteObject(SelectObject(hdcMem, oldbr));

						{//����� ������ ��������
							wstring wstrTo;
							wchar_t* wszTo = new wchar_t[tekstloading_internet.length() + 1];
							wszTo[tekstloading_internet.size()] = L'\0';
							MultiByteToWideChar(CP_ACP, 0, tekstloading_internet.c_str(), -1, wszTo, (int)tekstloading_internet.length());
							SetBkMode(hdcMem, TRANSPARENT);
							SetTextColor(hdcMem, RGB(255, 255, 255));
							oldbr1 = CreateFont(40, 6, 0, 0, 1000, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
								DEFAULT_PITCH | FF_DONTCARE, (L"Arial"));
							oldbr2 = (HFONT)SelectObject(hdcMem, oldbr1);
							TextOut(hdcMem, 3, 3, wszTo, tekstloading_internet.length());
							DeleteObject(oldbr1);
							DeleteObject(oldbr2);
						}
					}
				}
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////
			//���������� ���������
			BitBlt(hdc, psd.rcPaint.left, psd.rcPaint.top, psd.rcPaint.right, psd.rcPaint.bottom, hdcMem, psd.rcPaint.left, psd.rcPaint.top, SRCCOPY);
			SelectObject(hCompatibleDCBackground, hOldBitmapBackground);
			DeleteDC(hCompatibleDCBackground);
			SelectObject(hdcMem, hbmMem);
			DeleteObject(hbmMem1);
			DeleteDC(hdcMem);
			EndPaint(hWnd, &psd);
		}
	}
	return 0;
	case WM_LBUTTONDOWN:
	{
		void_WM_SETCURSOR_TO_WM_LBUTTONDOWN(hWnd);
	}
	return 0;

	/*
	case WM_SETCURSOR://������ (���������)
	{


		if ((HWND)wParam == GetDlgItem(hWnd, 4000))
		{
			SetWindowLongPtr(hWnd, DWLP_MSGRESULT, TRUE);
			return TRUE;
		}
		return FALSE;



	//	void_WM_SETCURSOR(hWnd);
	}
	return 0;
	*/
	case WM_GETMINMAXINFO://����������� ������� ����
	{
		LPMINMAXINFO lpMMI = (LPMINMAXINFO)lParam;
		lpMMI->ptMinTrackSize.x = shirina_data;
		lpMMI->ptMinTrackSize.y = visota_data;
	}
	return 0;
	//���� ��� ������ �� �������
	case WM_MOUSELEAVE:
	{
		//SetCursor(LoadCursor(NULL, IDC_ARROW));

		if (fInWindow)
		{
			fInWindow = FALSE;
			tme.dwFlags = TME_HOVER;
			TrackMouseEvent(&tme);
		}
		if (onko_info == 0)
		{
			onko_info = 1;
			InvalidateRect(hWnd, NULL, FALSE);
		}
	}
	return 0;
	//���� ��� ����� � �������
	case WM_MOUSEMOVE:
	{
		if (!fInWindow)
		{
			fInWindow = TRUE;
			tme.dwFlags = TME_LEAVE;
			TrackMouseEvent(&tme);
		}
		if (onko_info == 1)
		{
			onko_info = 0;
			InvalidateRect(hWnd, NULL, FALSE);
		}
	}
	return 0;
	//��������
	case WM_MOUSEWHEEL:
	{
		if (internet == 1 && stmenu == 1)
		{
			int otsbbb_WM_MOUSEWHEEL = (visotablokamenuid1 + OTSTUPmenuid1); //������ 
			int prohodkolid = 19;//���������� �������� �� 1 �� 18
			if (prohodkolid <= 0 || prohodkolid >= 19) { prohodkolid = 4; }

			if (cursoroknoactiv == 1)
			{

			}
			if (GET_WHEEL_DELTA_WPARAM(wParam) > 0)
			{
				for (size_t i = 0; i < prohodkolid; i++)
				{
					if (colesiko_ot < 0)
					{
						colesiko = colesiko + 1;
						colesiko_ot = colesiko_ot + otsbbb_WM_MOUSEWHEEL;
						if (colesiko <= -otsbbb_WM_MOUSEWHEEL)
						{
							dawdwda44gf = colesiko % 10;
						}
						else
						{
							dawdwda44gf = 0;
						}
					}
				}
			}
			else
			{
				for (size_t i = 0; i < prohodkolid; i++)
				{
					//if (colesiko_ot > -((visotablokamenuid1 + OTSTUPmenuid1)* (basedataid1_status_kolvo)) + r.bottom )
					if (colesiko > (-basedataid1_status_kolvo_EXTINF) + ((r.bottom) / (visotablokamenuid1 + OTSTUPmenuid1)))
					{
						colesiko = colesiko - 1;
						colesiko_ot = colesiko_ot - otsbbb_WM_MOUSEWHEEL;
						if (colesiko <= -otsbbb_WM_MOUSEWHEEL)
						{
							dawdwda44gf = colesiko % 10;
						}
						else
						{
							dawdwda44gf = 0;
						}
					}
				}
			}
			InvalidateRect(hWnd, NULL, FALSE);
			UpdateWindow(hWnd);
		}
	}
	break;
	//��������� ������� ������
	case WM_KEYDOWN:
	{
		if (stmenu == 1)
		{
			//������ �����
			if (wParam == VK_UP)
			{
				//MessageBoxA(NULL, "����", "Information", MB_OK);
				if (idloadchan > 0)
				{
					idloadchan = idloadchan - 1;
					InvalidateRect(hWnd, NULL, FALSE);
				}
			}
			//������ ����
			if (wParam == VK_DOWN)
			{
				//MessageBoxA(NULL, "���", "Information", MB_OK);
				if (basedataid1_status_kolvo_EXTINF == 0)
				{

				}
				else
				{
					if (idloadchan < basedataid1_status_kolvo_EXTINF - 1)
					{
						idloadchan = idloadchan + 1;
						InvalidateRect(hWnd, NULL, FALSE);
					}
				}
			}

			//Esc (����� �� �������������� ������)
			if (wParam == VK_ESCAPE)
			{
				if (!FullScreen)//�� �������� �� ���� �����
				{
				}
				else//�� ����� ������ � �������
				{
					SetWindowLong(hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);//������������� ����� ������� ������
					SetWindowLong(hWnd, GWL_EXSTYLE, 0L);
					SetWindowPlacement(hWnd, &wpc);//��������� �������� ����������� �������� ������
					ShowWindow(hWnd, SW_SHOWDEFAULT);//���������� ������� ����
					FullScreen = false;
				}
			}

			//F12 (���� � ����� � ������������� �����)
			if (wParam == VK_F12)
			{
				if (!FullScreen)//�� �������� �� ���� �����
				{
					GetWindowPlacement(hWnd, &wpc);//��������� ��������� �������� ������
					SetWindowLong(hWnd, GWL_STYLE, WS_POPUP);//������������� ����� �����
					SetWindowLong(hWnd, GWL_EXSTYLE, WS_EX_TOPMOST);
					ShowWindow(hWnd, SW_SHOWMAXIMIZED);//���� �� ���� �����
					FullScreen = true;
				}
				else//�� ����� ������ � �������
				{
					SetWindowLong(hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);//������������� ����� ������� ������
					SetWindowLong(hWnd, GWL_EXSTYLE, 0L);
					SetWindowPlacement(hWnd, &wpc);//��������� �������� ����������� �������� ������
					ShowWindow(hWnd, SW_SHOWDEFAULT);//���������� ������� ����
					FullScreen = false;
				}
			}
		}
	}
	break;
	//������������ ������� ��������� ������
	case WM_NCLBUTTONDOWN:
	{
		//�������� ���������
		if (wParam == HTCLOSE)
		{
			SendMessage(hWnd, WM_SYSCOMMAND, SC_CLOSE, 0);
		}
	}
	break;
	/*
	//CS_DBLCLKS ����� ���� ��� �������� �������
	case WM_LBUTTONDBLCLK:
	{

	}
	break;
	*/
	case WM_TIMER:
	{
	//�������� �������� ������� (FULLSCREEN)
	case TIMER_CLICKDOUBLE_FULLSCREEN:
	{
		KillTimer(hWnd, TIMER_CLICKDOUBLE_FULLSCREEN);
		//���� �������
		if (click_count == 1)
		{

		}
		//��� ������� ��� ��� �������
		else if (click_count == 2 || click_count == 3)
		{
			if (!FullScreen)//�� �������� �� ���� �����
			{
				GetWindowPlacement(hWnd, &wpc);//��������� ��������� �������� ������
				SetWindowLong(hWnd, GWL_STYLE, WS_POPUP);//������������� ����� �����
				SetWindowLong(hWnd, GWL_EXSTYLE, WS_EX_TOPMOST);
				ShowWindow(hWnd, SW_SHOWMAXIMIZED);//���� �� ���� �����
				FullScreen = true;
			}
			else//�� ����� ������ � �������
			{
				SetWindowLong(hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);//������������� ����� ������� ������
				SetWindowLong(hWnd, GWL_EXSTYLE, 0L);
				SetWindowPlacement(hWnd, &wpc);//��������� �������� ����������� �������� ������
				ShowWindow(hWnd, SW_SHOWDEFAULT);//���������� ������� ����
				FullScreen = false;
			}
		}
		click_count = 0;
	}
	//�������� ��������� �� �������
	case TIMER_INTERNETPROVERKA:
	{
		{
			if (!InternetCheckConnectionW(L"http://google.com", FLAG_ICC_FORCE_CONNECTION, 0))
			{//���� ����
				internet = 0;
			}
			else
			{//���� ����
				internet = 1;
			}
		}
		return 0;
	}

	case TIMER_OBNOVLENIE:
	{
		{
		//InvalidateRect(hWnd, NULL, FALSE);
		}
		return 0;
	}
	}
	return 0;
	//�� ��������
	case WM_ERASEBKGND:
	{
		return 1;
	}
	return 0;
	case WM_DESTROY:
	{
		KillTimer(hWnd, TIMER_INTERNETPROVERKA);
		PostQuitMessage(0);
	}
	return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}