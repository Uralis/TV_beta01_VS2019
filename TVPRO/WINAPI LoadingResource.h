//Цикл загрузки изображений (LOGO CANNEL)
void LoadingImgUrl(void* pParams)
{

	GUID guidBmp = {};
	GUID guidJpeg = {};
	GUID guidGif = {};
	GUID guidTiff = {};
	GUID guidPng = {};
	GetGdiplusEncoderClsid(L"image/bmp", &guidBmp);
	GetGdiplusEncoderClsid(L"image/jpeg", &guidJpeg);
	GetGdiplusEncoderClsid(L"image/gif", &guidGif);
	GetGdiplusEncoderClsid(L"image/tiff", &guidTiff);
	GetGdiplusEncoderClsid(L"image/png", &guidPng);


	//скачиваем img из парсинга 
	{
		//скачиваем информацию
		{
			static string colorimport___;
			for (size_t i = 1; i <= basedataid1_status_kolvo_EXTINF; i++)
			{
				int sttusssf8 = 0;
				string blackchaneellilst__[100] =
				{ "", "", "", "", "", "", "", "", "",
				};

				colorimport___ = ____grey;
				for (size_t iss = 0; iss < 100; iss++)
				{
					if (blackchaneellilst__[iss].c_str() != 0 || blackchaneellilst__[iss].c_str() != "")
					{
						CA2W pszWide____d_(blackchaneellilst__[iss].c_str());
						int index = nom_wstring_basedataid1_EXTINF_name_[i].find(pszWide____d_);
						if (index > 0) {
							colorimport___ = ____black;
						}
					}
				}

				imgpapkaurlput[i] = namelocalfile__logo[i];//local
				string png____ = namelocalfile__logo_png[i];//local
				string jpg____ = namelocalfile__logo_jpg[i];//local
				string bmp____ = namelocalfile__logo_bmp[i];//local

				string url0____5 = basedataid1_tvg_logo_name_[i];//url - ссылка

				/*
				if (url0____5.find(".png") != string::npos) {
					sttusssf8 = 1;
				}
				if (url0____5.find(".jpg") != string::npos) {
					sttusssf8 = 1;
				}
				*/
				sttusssf8 = 1;
				if (sttusssf8 == 0 || url0____5 == "" || url0____5 == "0")
				{
					activmass_levcon_img_info[4][i] = 0;
				}
				else
				{
					string url0____ = url0____5;//url - ссылка
					string file0____ = imgpapkaurlput[i];//file - путь файла с названием,
					int fileok0____ = 1;//(1/0) если имеется файл то не скачивать - 1 
					DownoladfileURLPRO_string(url0____, file0____, fileok0____);
					if (reshimpokaza == 1)
					{
						CA2W image(imgpapkaurlput[i].c_str());
						CA2W imagePNG(png____.c_str());
						CA2W imageJPG(jpg____.c_str());
						CA2W imageBMP(bmp____.c_str());
						if (bmp_pngstid1 == 0)
						{
							const char* d = png____.c_str();
							struct stat s = { 0 };
							if (!stat(d, &s)) {
							}
							else {
								CA2W imagesss(colorimport___.c_str());
								Image* bs = new Image(imagesss);
								GetGdiplusEncoderClsid(L"image/png", &guidPng);
								Image* b = new Image(image);
								static INT widthss________ = 32, heightss________ = 32;
								Gdiplus::Bitmap* newBitmap = new Gdiplus::Bitmap(widthss________, heightss________, b->GetPixelFormat());
								Gdiplus::Graphics graphics(newBitmap);
								graphics.DrawImage(bs, 0, 0, widthss________, heightss________);
								graphics.DrawImage(b, 0, 0, widthss________, heightss________);
								newBitmap->Save(imagePNG, &guidPng, NULL);
								IPTVLOGOPNGTOBMP[i] = mLoadImg(imagePNG);//NOLOGO tv
								activmass_levcon_img_info[4][i] = 1;
							}
						}
						if (bmp_pngstid1 == 1)
						{
							const char* d = bmp____.c_str();
							struct stat s = { 0 };
							if (!stat(d, &s)) {
							}
							else {
								CA2W imagesss(colorimport___.c_str());
								GetGdiplusEncoderClsid(L"image/bmp", &guidBmp);
								Image* bs = new Image(imagesss);
								Image* b = new Image(image);
								static INT widthss________ = 32, heightss________ = 32;
								Gdiplus::Bitmap* newBitmap = new Gdiplus::Bitmap(widthss________, heightss________, b->GetPixelFormat());
								Gdiplus::Graphics graphics(newBitmap);
								graphics.DrawImage(bs, 0, 0, widthss________, heightss________);
								graphics.DrawImage(b, 0, 0, widthss________, heightss________);
								newBitmap->Save(imageBMP, &guidBmp, NULL);
								IPTVLOGOPNGTOBMP[i] = LoadImage(NULL, imageBMP, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
								activmass_levcon_img_info[4][i] = 1;
							}
						}
					}
				}
			}
		}
	}
}
//Загрзка при запуске
void LoadingProc(void* pParams)
{
	//setlocale(LC_ALL, "Russian");
	//////////////////////////////////////////////
	//проверка наличия файлов (локальные) (и папок)
	{
		if (infoint == 1)//ru
		{
			tekstloading_ = "Проверка файлов";//статус загрузки
		}
		if (infoint == 2)//eng
		{
			tekstloading_ = "Checking files";//статус загрузки
		}
		int int1, int2 = 0;
		string st_name_data_papka[20] = { datapapkas, datapapkasproject, "ver", "img", "img\\color", "img\\logotv", "img\\logotv\\original", "img\\logotv\\bmp", "img\\logotv\\png", "img\\logotv\\jpg" };
		int int_name_data_papka = 0;
		for (int_name_data_papka = 0; int_name_data_papka < 12; int_name_data_papka++)
		{
			if (st_name_data_papka[int_name_data_papka] == "0") {}
			else {
				static string name_papka;
				if (int_name_data_papka == 0) {
					name_papka = "\\" + st_name_data_papka[0];
				}
				if (int_name_data_papka == 1) {
					name_papka = "\\" + st_name_data_papka[0] + "\\" + st_name_data_papka[1];
				}
				if (int_name_data_papka > 1) {
					name_papka = "\\" + st_name_data_papka[0] + "\\" + st_name_data_papka[1] + "\\" + st_name_data_papka[int_name_data_papka];
				}

				string data_appdata = data_appdata0 + name_papka;
				const char* d = data_appdata.c_str();
				struct stat s = { 0 };

				if (!stat(d, &s)) { int1 = 1; }
				else
				{
					wstring name_papka_2 = path_appdata + wstring(name_papka.begin(), name_papka.end());
					const wchar_t* name_papka_ok = name_papka_2.c_str();
					CreateDirectoryW(name_papka_ok, NULL);
				}
			}

		}
		string st_name_data_file[5] = { "ver\\ver1.proural", "ver\\ver2.proural" };
		int int_name_data_file = 0;
		for (int_name_data_file = 0; int_name_data_file < 5; int_name_data_file++)
		{
			if (st_name_data_file[int_name_data_file] == "0") {}
			else {
				string name_file = "\\" + st_name_data_papka[0] + "\\" + st_name_data_papka[1] + "\\" + st_name_data_file[int_name_data_file];

				string data_appdata = data_appdata0 + name_file;
				const char* d = data_appdata.c_str();
				struct stat s = { 0 };

				if (!stat(d, &s)) { int2 = 1; }
				else
				{
					wstring name_file_2 = path_appdata + wstring(name_file.begin(), name_file.end());
					const wchar_t* name_file_ok = name_file_2.c_str();
					CreateFile(name_file_ok, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0);
				}
			}
		}

		if (int1 == 1 && int2 == 1)
		{
			internet_file = 1;
		}
		else
		{
			internet_file = 0;
		}
	}

	//Создаём цвета
	{

		if (infoint == 1)//ru
		{
			tekstloading_ = "Создаем цвета";//статус загрузки
		}
		if (infoint == 2)//eng
		{
			tekstloading_ = "eng Создаем цвета";//статус загрузки
		}
		GUID guidPng = {};
		GetGdiplusEncoderClsid(L"image/png", &guidPng);

		____red = dataproj + "img\\color\\$" + "red.png";
		____black = dataproj + "img\\color\\$" + "black.png";
		____white = dataproj + "img\\color\\$" + "white.png";
		____grey = dataproj + "img\\color\\$" + "grey.png";


		//Красный
		{
			Gdiplus::Bitmap* newBitmap = new Gdiplus::Bitmap(32, 32, PixelFormat32bppARGB);
			Gdiplus::Graphics graphics(newBitmap);
			Gdiplus::Color color(192, 255, 0, 0);
			Gdiplus::Rect rectangle(0, 0, 32, 32);
			Gdiplus::SolidBrush solidBrush(color);
			graphics.FillRectangle(&solidBrush, rectangle);
			CA2W imagDDesss(____red.c_str());
			newBitmap->Save(imagDDesss, &guidPng, NULL);
		}
		//Чёрный
		{
			Gdiplus::Bitmap* newBitmap = new Gdiplus::Bitmap(32, 32, PixelFormat32bppARGB);
			Gdiplus::Graphics graphics(newBitmap);
			Gdiplus::Color color(0, 0, 0, 0);
			Gdiplus::Rect rectangle(0, 0, 32, 32);
			Gdiplus::SolidBrush solidBrush(color);
			graphics.FillRectangle(&solidBrush, rectangle);
			CA2W imagDDesss(____black.c_str());
			newBitmap->Save(imagDDesss, &guidPng, NULL);
		}
		//Белый
		{
			Gdiplus::Bitmap* newBitmap = new Gdiplus::Bitmap(32, 32, PixelFormat32bppARGB);
			Gdiplus::Graphics graphics(newBitmap);
			Gdiplus::Color color(255, 255, 255, 255);
			Gdiplus::Rect rectangle(0, 0, 32, 32);
			Gdiplus::SolidBrush solidBrush(color);
			graphics.FillRectangle(&solidBrush, rectangle);
			CA2W imagDDesss(____white.c_str());
			newBitmap->Save(imagDDesss, &guidPng, NULL);
		}
		//Серый
		{
			Gdiplus::Bitmap* newBitmap = new Gdiplus::Bitmap(32, 32, PixelFormat32bppARGB);
			Gdiplus::Graphics graphics(newBitmap);
			Gdiplus::Color color(255, 186, 186, 186);
			Gdiplus::Rect rectangle(0, 0, 32, 32);
			Gdiplus::SolidBrush solidBrush(color);
			graphics.FillRectangle(&solidBrush, rectangle);
			CA2W imagDDesss(____grey.c_str());
			newBitmap->Save(imagDDesss, &guidPng, NULL);
		}
	}

	//скачиваем информацию о новой версий
	{
		if (infoint == 1)//ru
		{
			tekstloading_ = "Проверка на наличие обновлений";//статус загрузки
		}
		if (infoint == 2)//eng
		{
			tekstloading_ = "Check for updates";//статус загрузки
		}
		//скачиваем информацию
		{
			string url0____ = "http://sntr.clan.su/launcher/ver.txt";//url - ссылка
			string file0____ = dataproj + "ver\\ver_dow.proural";//file - путь файла с названием,
			int fileok0____ = 0;//(1/0) если имеется файл то не скачивать - 1 
			DownoladfileURLPRO_string(url0____, file0____, fileok0____);
		}
	}

	//парсинг #EXTINF И url (cписок каналов)
	{
		if (infoint == 1)//ru
		{
			tekstloading_ = "Парсинг данных из плейлиста";//статус загрузки
		}
		if (infoint == 2)//eng
		{
			tekstloading_ = "(eng)Парсинг данных из плейлиста";//статус загрузки
		}
		string basedataid1_file = "1.m3u";//файл для загрузки
		std::ifstream basedataid1_file_ifstream(basedataid1_file, std::ios::out | std::ios::app | std::ios::binary);
		if (basedataid1_file_ifstream.is_open())
		{
			erorfile = 0;

			static string _basedataid1_poiskid0 = "#EXTM3U";
			static string _basedataid1_poiskid1 = "#EXTINF";
			static string _basedataid1_poiskid2 = "://";

			static string _basedataid1_massiv_pro[10000];
			static string _basedataid1_epg_pro[10000];
			static string _basedataid1_id_pro[10000];
			static string _basedataid1_id_URL_pro[10000];
			static string _basedataid1_id_KJ_name[10000];
			//static string _basedataid1_namedata_text_EXTM3U[10000];//массив epg
			//static string _basedataid1_namedata_text_EXTINF[10000];//массив каналов (общее)
			//static string _basedataid1_namedata_text_URL[10000];// массив url
			static string _basedataid1_name_text_krat[10000];// массив названий канала
			static int razdelen, urlacif;

			for (size_t i = 0; i < 9000; i++)
			{
				//поочереди считываем строки
				getline(basedataid1_file_ifstream, _basedataid1_massiv_pro[i]);
				//если нейдено epg
				if (_basedataid1_massiv_pro[i].find(_basedataid1_poiskid0) != string::npos)
				{
					_basedataid1_epg_pro[i] = _basedataid1_massiv_pro[i];
				}
				else //продолжаем
				{
					//меняем razdelen если был найден канал
					if (razdelen == 2)
					{
						razdelen = 3;
					}
					//записываем массив с каналами basedataid1_id_pro
					if (_basedataid1_massiv_pro[i].find(_basedataid1_poiskid1) != string::npos)
					{
						razdelen = 1;
						string resdatapro = _basedataid1_massiv_pro[i];
						//удаляем кавычки
						resdatapro = std::regex_replace(resdatapro, std::regex("[\"]"), "");
						//добавляем пробел к ,
						resdatapro = std::regex_replace(resdatapro, std::regex("[,]"), " , ");
						//удаляем лишние пробелы
						resdatapro = std::regex_replace(resdatapro, std::regex("[ ]+"), " ");
						//запись 
						_basedataid1_id_pro[i] = resdatapro;
						razdelen = 2;
					}
					//если найдена ссылка на поток записываем в массив  
					if (razdelen == 3)
					{
						if (_basedataid1_massiv_pro[i].find(_basedataid1_poiskid2) != string::npos)
						{
							_basedataid1_id_URL_pro[i] = _basedataid1_massiv_pro[i];
						}
					}
				}

				//ЕСЛИ НАЙДЕН EPG
				if (_basedataid1_epg_pro[i] == "") {}
				else
				{
					//счёт EPG
					epgok++;
					basedataid1_namedata_text_EXTM3U[epgok] = _basedataid1_epg_pro[i];
				}
				if (_basedataid1_id_pro[i] == "") {}
				else
				{

					//если найдена , (получаем массив без названий канала)	
					string data = _basedataid1_id_pro[i];
					string data_namechan = _basedataid1_id_pro[i];
					string resul1, resul2;
					string poisk1(",");
					size_t found = data.find(poisk1);
					if (found != std::string::npos)
					{	//счёт каналов
						//получаем полную информацию (строка с тегами) ЗАПИСЫВАЕМ
						basedataid1_status_kolvo_EXTINF++;
						basedataid1_namedata_text_EXTINF[basedataid1_status_kolvo_EXTINF] = _basedataid1_id_pro[i];
						//получаем результат без названия
						resul1 = data.erase(found, data.length());//без названия
						urlacif = 1;
						//записываем в массив без названия
						basedataid1_EXTINF_name_razelen[basedataid1_status_kolvo_EXTINF] = resul1;
						//получаем название после запятой resul1.length(), data_namechan.length()
						resul2 = data_namechan.erase(0, resul1.length() + 1);//название
						wstring_basedataid1_EXTINF_name_[basedataid1_status_kolvo_EXTINF] = ConvertEncoding(resul2);
						basedataid1_EXTINF_name_[basedataid1_status_kolvo_EXTINF] = ConvertEncodingBack(wstring_basedataid1_EXTINF_name_[basedataid1_status_kolvo_EXTINF]);
						resul2 = to_string(basedataid1_status_kolvo_EXTINF) + ". " + resul2;//название
						//удаляем лишние пробелы
						resul2 = std::regex_replace(resul2, std::regex("[ ]+"), " ");
						nom_wstring_basedataid1_EXTINF_name_[basedataid1_status_kolvo_EXTINF] = ConvertEncoding(resul2);
						nom_basedataid1_EXTINF_name_[basedataid1_status_kolvo_EXTINF] = ConvertEncodingBack(wstring_basedataid1_EXTINF_name_[basedataid1_status_kolvo_EXTINF]);
						/////////////////
						/////////////////
						{
							string parampropars[30] = { "tvg-id=", "channel-id=", "tvg-name=", "group-title=", "tvg-logo=", "aspect-ratio=", "radio=", "audio-track=", "catchup-days=", "catchup-source=", "catchup=" };
							for (size_t is = 0; is < 20; is++)
							{
								if (parampropars[is] == "")
								{
								}
								else {
									string data__ = resul1;
									size_t found__ = data__.find(parampropars[is]);
									if (found__ != std::string::npos)
									{
										string probel = " ";
										string ravno = "=";
										string resul___;
										string data_group___ = resul1;
										size_t int_group_title = data_group___.find(parampropars[is]);
										resul___ = data_group___.erase(0, int_group_title);
										size_t int_group_title_probel = resul___.find(probel);
										resul___ = data_group___.erase(int_group_title_probel, resul___.length());
										size_t int_group_title_ravno = resul___.find(ravno);
										resul___ = data_group___.erase(0, int_group_title_ravno + 1);
										//
										std::wstring wide = ConvertEncoding(resul___);
										if (parampropars[is] == "tvg-id=")
										{
											basedataid1_tvg_id_name_[basedataid1_status_kolvo_EXTINF] = ConvertEncodingBack(wide);
										}
										if (parampropars[is] == "channel-id=")
										{
											basedataid1_channel_id_name_[basedataid1_status_kolvo_EXTINF] = ConvertEncodingBack(wide);
										}
										if (parampropars[is] == "tvg-name=")
										{
											basedataid1_tvg_name_name_[basedataid1_status_kolvo_EXTINF] = ConvertEncodingBack(wide);
										}
										if (parampropars[is] == "group-title=")
										{
											basedataid1_group_title_name_[basedataid1_status_kolvo_EXTINF] = ConvertEncodingBack(wide);
										}
										if (parampropars[is] == "tvg-logo=")
										{
											wstring_basedataid1_tvg_logo_name_[basedataid1_status_kolvo_EXTINF] = ConvertEncoding(resul___);
											basedataid1_tvg_logo_name_[basedataid1_status_kolvo_EXTINF] = ConvertEncodingBack(wstring_basedataid1_tvg_logo_name_[basedataid1_status_kolvo_EXTINF]);
										}
										if (parampropars[is] == "aspect-ratio=")
										{
											basedataid1_aspect_ratio_name_[basedataid1_status_kolvo_EXTINF] = ConvertEncodingBack(wide);
										}
										if (parampropars[is] == "radio=")
										{
											basedataid1_radio_name_[basedataid1_status_kolvo_EXTINF] = ConvertEncodingBack(wide);
										}
										if (parampropars[is] == "audio-track=")
										{
											basedataid1_audio_track_name_[basedataid1_status_kolvo_EXTINF] = ConvertEncodingBack(wide);
										}
										if (parampropars[is] == "catchup-days=")
										{
											basedataid1_catchup_days_name_[basedataid1_status_kolvo_EXTINF] = ConvertEncodingBack(wide);
										}
										if (parampropars[is] == "catchup-source=")
										{
											basedataid1_catchup_source_name_[basedataid1_status_kolvo_EXTINF] = ConvertEncodingBack(wide);
										}
										if (parampropars[is] == "catchup=")
										{
											basedataid1_catchup_name_[basedataid1_status_kolvo_EXTINF] = ConvertEncodingBack(wide);
										}

									}
								}
							}

						}

					}
					else//если нету 
					{
						urlacif = 0;
					}
				}
				//если есть ссылка на канал и , 
				if (_basedataid1_id_URL_pro[i] == "" && urlacif == 1) {}
				else
				{
					basedataid1_namedata_text_URL[basedataid1_status_kolvo_EXTINF] = _basedataid1_id_URL_pro[i];
				}
			}
		}
		else { erorfile = 1; }
		basedataid1_file_ifstream.close();// закрываем файл
	}

	//Формирование запроса к кешу
	for (size_t i = 1; i <= basedataid1_status_kolvo_EXTINF; i++)
	{
		if (infoint == 1)//ru
		{
			tekstloading_ = "Формирование запроса к кешу";
		}
		if (infoint == 2)//eng
		{
			tekstloading_ = "(eng)Формирование запроса к кешу";
		}

		string url_0__8 = basedataid1_tvg_logo_name_[i];
		//удаление недопустимых сиволов
		url_0__8 = std::regex_replace(url_0__8, std::regex("[ ]"), "");//Пробел
		url_0__8 = std::regex_replace(url_0__8, std::regex("[\]"), "");//
		url_0__8 = std::regex_replace(url_0__8, std::regex("[/]"), "");//
		url_0__8 = std::regex_replace(url_0__8, std::regex("[:]"), "");//
		url_0__8 = std::regex_replace(url_0__8, std::regex("[*]"), "");//
		url_0__8 = std::regex_replace(url_0__8, std::regex("[?]"), "");//
		url_0__8 = std::regex_replace(url_0__8, std::regex("[<]"), "");//
		url_0__8 = std::regex_replace(url_0__8, std::regex("[>]"), "");//
		url_0__8 = std::regex_replace(url_0__8, std::regex("[|]"), "");//
		url_0__8 = std::regex_replace(url_0__8, std::regex("[+]"), "");//
		url_0__8 = std::regex_replace(url_0__8, std::regex("[.]"), "");//
		url_0__8 = std::regex_replace(url_0__8, std::regex("[%]"), "");//
		url_0__8 = std::regex_replace(url_0__8, std::regex("[!]"), "");//
		url_0__8 = std::regex_replace(url_0__8, std::regex("[@]"), "");//
		url_0__8 = std::regex_replace(url_0__8, std::regex("[-]"), "");//

		namelocalfile__logo[i] = dataproj + "img\\logotv\\original\\$" + url_0__8;//local
		namelocalfile__logo_png[i] = dataproj + "img\\logotv\\png\\$" + url_0__8 + ".png";//local
		namelocalfile__logo_jpg[i] = dataproj + "img\\logotv\\jpg\\$" + url_0__8 + ".jpg";//local
		namelocalfile__logo_bmp[i] = dataproj + "img\\logotv\\bmp\\$" + url_0__8 + ".bmp";//local
	}

	//Загрузка логотипов из кеша
	for (size_t i = 1; i <= basedataid1_status_kolvo_EXTINF; i++)
	{
		if (infoint == 1)//ru
		{
			tekstloading_ = "Загрузка логотипов из кеша";
		}
		if (infoint == 2)//eng
		{
			tekstloading_ = "(eng)Загрузка логотипов из кеша";
		}
		if (reshimpokaza == 1)
		{
			if (bmp_pngstid1 == 0)
			{
				const char* d = namelocalfile__logo_png[i].c_str();
				struct stat s = { 0 };
				if (!stat(d, &s)) {

					CA2W imagePNG(namelocalfile__logo_png[i].c_str());
					IPTVLOGOPNGTOBMP[i] = mLoadImg(imagePNG);//NOLOGO tv
					activmass_levcon_img_info[4][i] = 1;
				}
			}
			if (bmp_pngstid1 == 1)
			{
				const char* d = namelocalfile__logo_bmp[i].c_str();
				struct stat s = { 0 };
				if (!stat(d, &s)) {

					CA2W imageBMP(namelocalfile__logo_bmp[i].c_str());
					IPTVLOGOPNGTOBMP[i] = LoadImage(NULL, imageBMP, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
					activmass_levcon_img_info[4][i] = 1;
				}
			}
		}
	}

	//скачиваем img из парсинга 
	_beginthread(LoadingImgUrl, 0, NULL);

	//завершаем загрузку
	stmenuloading = 2;
	//////////////////////////////////////////////
}