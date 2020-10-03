void void_WM_PAINT(HWND hWnd, HDC hdcMem, HGDIOBJ oldbr, HGDIOBJ oldbr1, HGDIOBJ oldbr2)
{
	Graphics g(hdcMem);	g.SetPageUnit(UnitPixel);

	//обработка левого меню с миниатюрами
	{
		//fon для миниатюр (общий)
		{
			BLENDFUNCTION blend;
			blend.BlendOp = AC_SRC_OVER;
			blend.BlendFlags = 0;
			blend.AlphaFormat = 0;
			blend.SourceConstantAlpha = 180;
			hOldBitmapBackground = SelectObject(hCompatibleDCBackground, BLACK_PNG);//img
			AlphaBlend(hdcMem, 0, 0, shirinamenuid1, r.bottom, hCompatibleDCBackground, 0, 0, 2, 2, blend);
			//Image bg(imgresload_id8);
			//RectF bounds(0, 0, shirinamenuid1 + 50, r.bottom);
			//g.DrawImage(&bg, bounds, 0, 0, 5, 5, UnitPixel);
		}
		//цикл обработки миниатюр
		static int umnoshitelid1;
		for (size_t i = 1; i <= basedataid1_status_kolvo_EXTINF; i++)
		{
			umnoshitelid1 = i - 1;
			//Рисуем блоки через один разными цветами 
			{
				//Цвет при нажатий
				if (idloadchan == umnoshitelid1 && i > umnoshitelid1)
				{
					BLENDFUNCTION blend;
					blend.BlendOp = AC_SRC_OVER;
					blend.BlendFlags = 0;
					blend.AlphaFormat = 0;
					blend.SourceConstantAlpha = 200;

					hOldBitmapBackground = SelectObject(hCompatibleDCBackground, WHITE_PNG);//img
					AlphaBlend(hdcMem, 0, (OTSTUPmenuid1 * umnoshitelid1) + ((visotablokamenuid1 * umnoshitelid1) + colesiko_ot), shirinamenuid1, visotablokamenuid1, hCompatibleDCBackground, 0, 0, 2, 2, blend);
				}
				else//Рисование через один если не выбрано
				{
					BLENDFUNCTION blend;
					blend.BlendOp = AC_SRC_OVER;
					blend.BlendFlags = 0;
					blend.AlphaFormat = 0;

					if (umnoshitelid1 % 2 == 0)
					{
						blend.SourceConstantAlpha = 200;
					}
					else
					{
						blend.SourceConstantAlpha = 150;
					}
					hOldBitmapBackground = SelectObject(hCompatibleDCBackground, BLACK_PNG);//img
					AlphaBlend(hdcMem, 0, (OTSTUPmenuid1 * umnoshitelid1) + ((visotablokamenuid1 * umnoshitelid1) + colesiko_ot), shirinamenuid1, visotablokamenuid1, hCompatibleDCBackground, 0, 0, 2, 2, blend);
				}
			}
			//Рисуем img logo (миниатюры)
			{
				//проверка наличия img в папке если нету то img_ICO_er

				const char* d = imgpapkaurlput[i].c_str();
				struct stat s = { 0 };
				if (!stat(d, &s)) {
					activmass_levcon_img_info[0][i] = 0;
				}
				else
				{
					activmass_levcon_img_info[0][i] = 1;
				}
				//if (masssivloadingproid1[i] == 1)

				//работа с логотипами (рисование)
				BLENDFUNCTION blend;
				BLENDFUNCTION blend_;
				blend_.BlendOp = AC_SRC_OVER;
				blend_.BlendFlags = 0;
				blend_.AlphaFormat = 0;
				blend_.SourceConstantAlpha = 255;
				if (prozrachnosti__ == 0)
				{
					blend.BlendOp = AC_SRC_OVER;
					blend.BlendFlags = 0;
					blend.AlphaFormat = 0;
					blend.SourceConstantAlpha = 255;
				}
				else
				{
					blend.BlendOp = AC_SRC_OVER;
					blend.BlendFlags = 0;
					blend.SourceConstantAlpha = 0xff;
					blend.AlphaFormat = AC_SRC_ALPHA;
				}
				BITMAP bm;
				if (activmass_levcon_img_info[0][i] == 0 && activmass_levcon_img_info[4][i] == 1)
				{
					if (reshimpokaza == 0)//gdi+
					{
						TCHAR img__[300];
						string img_ICO____ = imgpapkaurlput[i];
						StringCchPrintf(img__, 300, TEXT("%hs"), (img_ICO____));
						Image bg(img__);
						g.DrawImage(&bg,
							OTSTUPmenuid_1,
							(OTSTUPmenuid1 * umnoshitelid1) + (OTSTUPmenuid_1)+((visotablokamenuid1 * umnoshitelid1) + colesiko_ot),
							shirinablock__,
							vitotablock__);
					}
					else { //gdi+ to bmp
						GetObject(BMPLOADINGIMG_NOLOGOTV, sizeof(bm), &bm);
						hOldBitmapBackground = SelectObject(hCompatibleDCBackground, BMPLOADINGIMG_NOLOGOTV);//img
						AlphaBlend(hdcMem, OTSTUPmenuid_1,
							(OTSTUPmenuid1 * umnoshitelid1) + (OTSTUPmenuid_1)+((visotablokamenuid1 * umnoshitelid1) + colesiko_ot),
							shirinablock__,
							vitotablock__, hCompatibleDCBackground, 0, 0, bm.bmWidth, bm.bmHeight, blend);

						GetObject(IPTVLOGOPNGTOBMP[i], sizeof(bm), &bm);
						hOldBitmapBackground = SelectObject(hCompatibleDCBackground, IPTVLOGOPNGTOBMP[i]);//img
						AlphaBlend(hdcMem, 1 + OTSTUPmenuid_1,
							1 + (OTSTUPmenuid1 * umnoshitelid1) + (OTSTUPmenuid_1)+((visotablokamenuid1 * umnoshitelid1) + colesiko_ot),
							shirinablock__ - 2,
							vitotablock__ - 2, hCompatibleDCBackground, 0, 0, bm.bmWidth, bm.bmHeight, blend);
					}
				}
				else
				{
					GetObject(BMPLOADINGIMG_NOLOGOTV, sizeof(bm), &bm);
					hOldBitmapBackground = SelectObject(hCompatibleDCBackground, BMPLOADINGIMG_NOLOGOTV);//img

					AlphaBlend(hdcMem, OTSTUPmenuid_1,
						(OTSTUPmenuid1 * umnoshitelid1) + (OTSTUPmenuid_1)+((visotablokamenuid1 * umnoshitelid1) + colesiko_ot),
						shirinablock__,
						vitotablock__, hCompatibleDCBackground, 0, 0, bm.bmWidth, bm.bmHeight, blend);
				}
			}
			//Рисуем текст 
			{
				//Название каналов
				{
					SetBkMode(hdcMem, TRANSPARENT);
					SetTextColor(hdcMem, RGB(255, 255, 255));
					oldbr1 = CreateFont(18, 8, 0, 0, 1000, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
						DEFAULT_PITCH | FF_DONTCARE, (L"Arial"));
					oldbr2 = (HFONT)SelectObject(hdcMem, oldbr1);
					TextOut(hdcMem, OTSTUPmenuid_1 + shirinablock__, (OTSTUPmenuid1 * umnoshitelid1) + (OTSTUPmenuid_1)+((visotablokamenuid1 * umnoshitelid1) + colesiko_ot), nom_wstring_basedataid1_EXTINF_name_[i].c_str(), nom_wstring_basedataid1_EXTINF_name_[i].length());
					DeleteObject(oldbr1);
					DeleteObject(oldbr2);
				}
			}

		}
	}
	//обработка компонентов в области показа


	//Рисование панели 
	{
		BLENDFUNCTION blend;
		blend.BlendOp = AC_SRC_OVER;
		blend.BlendFlags = 0;
		blend.AlphaFormat = 0;
		blend.SourceConstantAlpha = 200;

		hOldBitmapBackground = SelectObject(hCompatibleDCBackground, BLACK_PNG);//img
		AlphaBlend(hdcMem, shirinamenuid1, 0,
			(r.right - shirinamenuid1),
			100, hCompatibleDCBackground, 0, 0, 2, 2, blend);
	}

	/*
	static int umnoshitelids1;
	for (size_t i = 1; i <= basedataid1_status_kolvo_EXTINF; i++)
	{
		umnoshitelids1 = i - 1;
		//Рисуем информацию

		{
			if (activmass_levcon_img_info[0][i] == 0 && activmass_levcon_img_info[4][i] == 1)
			{
				if (idloadchan == umnoshitelids1 && i > umnoshitelids1)
				{
					TCHAR img__[300];
					string img_ICO____ = imgpapkaurlput[i];
					StringCchPrintf(img__, 300, TEXT("%hs"), (img_ICO____));
					Image bg(img__);
					g.DrawImage(&bg,
						shirinamenuid1 + 5,
						5,
						90,
						90);
				}
			}
		}
	}

	*/

}