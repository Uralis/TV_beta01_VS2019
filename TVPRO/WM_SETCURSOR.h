void void_WM_SETCURSOR_TO_WM_LBUTTONDOWN(HWND hWnd)
{
	if (stmenu == 1)
	{
		if (pt.x >= shirinamenuid1 && r.right>= pt.x)
		{
			//счЄт кликов (дл€ раскрыти€ на весь экран при двойном нажатий)
			if (click_count == 0)
			{
				//GetDoubleClickTime() - 500
				SetTimer(hWnd, TIMER_CLICKDOUBLE_FULLSCREEN, 200, NULL);
			}
			click_count++;
		}
	}
	//
	if (::GetCursorPos(&pt))
	{
		ScreenToClient(hWnd, &pt);//работа с рабочей областью курсор
	}
	if (internet == 1)
	{
		if (stmenu == 1)
		{
			//Ћева€ часть с PNG Ћќ√ќ“»ѕјћ»
			{
				
				if (pt.x >= 0 && shirinamenuid1 >= pt.x)
				{
					static int umnoshitelid1;
					int dataimagedata = 1;
					for (dataimagedata = 1; dataimagedata <= basedataid1_status_kolvo_EXTINF; dataimagedata++)
					{
						if (dataimagedata == 1)
						{
							umnoshitelid1 = 0;
						}
						else
						{
							umnoshitelid1++;
						}
						//g.DrawImage(&color_bel, 0, ((70 * i) + colesiko_ot), shirinamenuid1, 70);
						CHAR Usloviid = { 
							pt.x >=	0 && shirinamenuid1 + 0 >= pt.x
							&& pt.y > (OTSTUPmenuid1 * umnoshitelid1) + ((visotablokamenuid1 * umnoshitelid1) + colesiko_ot)
							&& visotablokamenuid1 + (OTSTUPmenuid1 * umnoshitelid1) + ((visotablokamenuid1 * umnoshitelid1) + colesiko_ot) >= pt.y };
						if (Usloviid)
						{
							idloadchan = umnoshitelid1;
							InvalidateRect(hWnd, NULL, FALSE);
						}
						else {
						}
					}
				}
			}
		}
	}
	else
	{
		InvalidateRect(hWnd, NULL, FALSE);
	}
}

/*
void void_WM_SETCURSOR(HWND hWnd)
{
	static int scetcursor_int_data;
	if (::GetCursorPos(&pt))
	{
		//ScreenToClient(hWnd, &pt);
		//SetCursorPos(pt.x, pt.y);
		//GetCursorPos(&pt);//работа с рабочей областью курсор
		ScreenToClient(hWnd, &pt);//работа с рабочей областью курсор
	}

	//база курсоров
	if (scetcursor_int_data == 0) { SetCursor(LoadCursor(NULL, IDC_ARROW)); }
	if (scetcursor_int_data == 1) { SetCursor(LoadCursor(NULL, IDC_HAND)); }
	if (scetcursor_int_data == 2) { SetCursor(LoadCursor(NULL, IDC_IBEAM)); }
	if (scetcursor_int_data == 3) { SetCursor(LoadCursor(NULL, IDC_WAIT)); }
	if (scetcursor_int_data == 4) { SetCursor(LoadCursor(NULL, IDC_CROSS)); }
	if (scetcursor_int_data == 5) { SetCursor(LoadCursor(NULL, IDC_UPARROW)); }
	if (scetcursor_int_data == 6) { SetCursor(LoadCursor(NULL, IDC_SIZE)); }
	if (scetcursor_int_data == 7) { SetCursor(LoadCursor(NULL, IDC_ICON)); }
	if (scetcursor_int_data == 8) { SetCursor(LoadCursor(NULL, IDC_SIZENWSE)); }
	if (scetcursor_int_data == 9) { SetCursor(LoadCursor(NULL, IDC_SIZENESW)); }
	if (scetcursor_int_data == 10) { SetCursor(LoadCursor(NULL, IDC_SIZEWE)); }
	if (scetcursor_int_data == 11) { SetCursor(LoadCursor(NULL, IDC_SIZENS)); }
	if (scetcursor_int_data == 12) { SetCursor(LoadCursor(NULL, IDC_SIZEALL)); }
	if (scetcursor_int_data == 13) { SetCursor(LoadCursor(NULL, IDC_NO)); }
	if (scetcursor_int_data == 14) { SetCursor(LoadCursor(NULL, IDC_APPSTARTING)); }
	if (scetcursor_int_data == 15) { SetCursor(LoadCursor(NULL, IDC_HELP)); }
	if (scetcursor_int_data == 16) { SetCursor(LoadCursor(NULL, IDC_PIN)); }
	if (scetcursor_int_data == 17) { SetCursor(LoadCursor(NULL, IDC_PERSON)); }
	if (internet == 1)
	{
		if (stmenu == 0)
		{
			scetcursor_int_data = 0;
		}

		if (stmenu == 1)
		{
			//Ћева€ часть с PNG Ћќ√ќ“»ѕјћ»
			{
				int dataimagedata = 0;
				for (dataimagedata = 0; dataimagedata < basedataid1_status_kolvo; dataimagedata++)
				{
					//g.DrawImage(&color_bel, 0, ((70 * i) + colesiko_ot), shirinamenuid1, 70);
					CHAR Usloviid = { pt.x >=
						0
						&& shirinamenuid1 +
						0 >= pt.x
						&& pt.y >= (OTSTUPmenuid1 * dataimagedata) + ((visotablokamenuid1 * dataimagedata) + colesiko_ot)
						&& visotablokamenuid1 +
						(OTSTUPmenuid1 * dataimagedata) + ((visotablokamenuid1 * dataimagedata) + colesiko_ot) >= pt.y };
					if (Usloviid)
					{
						activmass_levcon[0][dataimagedata] = 1;
						scetcursor_int_data = 1;

						if (activmass_levcon[1][dataimagedata] == 0
							&& activmass_levcon[0][dataimagedata] == 1) {
							InvalidateRect(hWnd, NULL, FALSE);
							activmass_levcon[1][dataimagedata] = 1;
						}
					}
					else {

						activmass_levcon[0][dataimagedata] = 0;
						if (activmass_levcon[1][dataimagedata] == 1
							&& activmass_levcon[0][dataimagedata] == 0) {
							scetcursor_int_data = 0;
							InvalidateRect(hWnd, NULL, FALSE);
							activmass_levcon[1][dataimagedata] = 0;
						}
					}
				}
			}
		}
	}
	else
	{
		InvalidateRect(hWnd, NULL, FALSE);
		scetcursor_int_data = 13;
	}

	if (onko_info == 1)
	{
		//–абота с границами приложени€
		{
			if (pt.x < -(GetSystemMetrics(SM_CXDLGFRAME)) || pt.x > r.right + (GetSystemMetrics(SM_CXDLGFRAME)))//лево и право
			{
				SetCursor(LoadCursor(NULL, IDC_SIZEWE));
			}

			if (pt.y > r.bottom + GetSystemMetrics(SM_CXDLGFRAME) || pt.y < -(GetSystemMetrics(SM_CYDLGFRAME) + GetSystemMetrics(SM_CYCAPTION)))//низ и верх
			{
				SetCursor(LoadCursor(NULL, IDC_SIZENS));
			}

			if (pt.x < -(GetSystemMetrics(SM_CXDLGFRAME)) + 5 and pt.y > r.bottom + GetSystemMetrics(SM_CXDLGFRAME) - 3)//  лево и низ(угол)
			{
				SetCursor(LoadCursor(NULL, IDC_SIZENESW));
			}

			if (pt.y > r.bottom + GetSystemMetrics(SM_CXDLGFRAME) - 3 and pt.x > r.right + (GetSystemMetrics(SM_CXDLGFRAME)))//право и низ(угол)
			{
				SetCursor(LoadCursor(NULL, IDC_SIZENWSE));
			}

			if (pt.x > r.right + (GetSystemMetrics(SM_CXDLGFRAME)) - 5 and pt.y < -(GetSystemMetrics(SM_CYDLGFRAME) + GetSystemMetrics(SM_CYCAPTION)) + 3)//  лево и верх(угол)
			{
				SetCursor(LoadCursor(NULL, IDC_SIZENESW));
			}

			if (pt.x < -(GetSystemMetrics(SM_CXDLGFRAME)) + 5 and pt.y < -(GetSystemMetrics(SM_CYDLGFRAME) + GetSystemMetrics(SM_CYCAPTION)) + 3)//  право и верх(угол)
			{
				SetCursor(LoadCursor(NULL, IDC_SIZENWSE));
			}
		}
	}
}
*/