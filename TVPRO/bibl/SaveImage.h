bool SaveImage(const std::string & szPathName, const std::vector<char> & lpBits, int w, int h) {
	// Create a new file for writing
	std::ofstream pFile(szPathName, std::ios_base::binary);
	if (!pFile.is_open()) {
		return false;
	}

	BITMAPINFOHEADER bmih;
	bmih.biSize = sizeof(BITMAPINFOHEADER);
	bmih.biWidth = w;
	bmih.biHeight = h;
	bmih.biPlanes = 1;
	bmih.biBitCount = 24;
	bmih.biCompression = BI_RGB;
	bmih.biSizeImage = w * h * 3;

	BITMAPFILEHEADER bmfh;
	int nBitsOffset = sizeof(BITMAPFILEHEADER) + bmih.biSize;
	LONG lImageSize = bmih.biSizeImage;
	LONG lFileSize = nBitsOffset + lImageSize;
	bmfh.bfType = 'B' + ('M' << 8);
	bmfh.bfOffBits = nBitsOffset;
	bmfh.bfSize = lFileSize;
	bmfh.bfReserved1 = bmfh.bfReserved2 = 0;

	// Write the bitmap file header
	pFile.write((const char*)& bmfh, sizeof(BITMAPFILEHEADER));
	UINT nWrittenFileHeaderSize = pFile.tellp();

	// And then the bitmap info header
	pFile.write((const char*)& bmih, sizeof(BITMAPINFOHEADER));
	UINT nWrittenInfoHeaderSize = pFile.tellp();

	// Finally, write the image data itself
	//-- the data represents our drawing
	pFile.write(&lpBits[0], lpBits.size());
	UINT nWrittenDIBDataSize = pFile.tellp();
	pFile.close();

	return true;
}
//Открытие БМП-файла, возвращает массив битовых данных и через указатель структуру BITMAPINFOHEADER с параметрами битовых данных
unsigned char* OpenBitmap(const std::string & name, BITMAPINFOHEADER * retbih)
{
	HANDLE hbmp, mapfile;    //Хэндлы открытых файлов
	BITMAPFILEHEADER* bfh;          //Файловый заголовок
	BITMAPINFOHEADER* bih;       //Информационный заголовок файла
	BITMAPINFO* bi;                 //BITMAPINFO
	unsigned char* mf, * bits, * newbits;//указатели на блоки памяти
	unsigned int size;              //Зазмер файла
	unsigned int index;             //используется для преобразования индексного цвета в truecolor
	unsigned int newsts, oldsts; //размер новой и старой строки битовой карты в байтах
	CA2W imageBMP(name.c_str());
	hbmp = CreateFile(imageBMP, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);//открываем файл из командной строки
	if (hbmp == INVALID_HANDLE_VALUE)  //Если не открылся
	{
		return 0;                            //возвращаем ошибку
	}
	size = GetFileSize(hbmp, NULL);    //получаем его размер
	mapfile = CreateFileMapping(hbmp, NULL, PAGE_READWRITE, 0, size, L"MyFileMappingObject"); //получаем хэндл маппирования
	mf = (unsigned char*)MapViewOfFile(mapfile, FILE_MAP_ALL_ACCESS, 0, 0, size);//Маппируем файл на участок памяти (то есть теперь файл представляет собой массим из байт в памяти)
	bfh = (BITMAPFILEHEADER*)mf;//инициализируем указатель на файловый заголовок файла
	if (bfh->bfType != 0x4d42)     //Если сигнатура файла не равна BM
	{
		return 0;                               //возвращаем ошибку
	}
	bih = (BITMAPINFOHEADER*)(mf + 0xe);            //инициализируем указатель на информационный заголовок файла
	bi = (BITMAPINFO*)(mf + 0xe);                   //инициализируем указатель на структуру BITMAPINFO
	bits = mf + bfh->bfOffBits;                     //массив с растровыми данными
	oldsts = (bfh->bfSize - bfh->bfOffBits) / bih->biHeight;  //длина строки растра в байтах старого файла
	newsts = bih->biWidth * 3;                              //длина строки растра в байтах нового файла
	if ((newsts & 3) != 0)newsts = newsts & 0xfffffffc + 4;  //если размер стртки не кратен 4, то дополняем его до 4
	newbits = new unsigned char[newsts * bih->biHeight];    //Массив нового растра
	memset(newbits, 0, newsts * bih->biHeight);
	for (int i = 0; i != bih->biHeight; i++)        //Идем по каждому пикселю
		for (int j = 0; j != bih->biWidth; j++)
		{
			switch (bih->biBitCount)     //и в зависимости от глубины цвета преобразовываем при помощи разных алгоритмов
			{
			case 1:                           //для 1 бита на пиксель
			{
				index = (bits[i * oldsts + j / 8] >> (7 - j & 7)) & 1;          //получаем цвет пикселя, как индекс в палитре файла
				newbits[i * newsts + j * 3] = bi->bmiColors[index].rgbBlue;       //Заполняем массив битовых данных соответствующим цветом из палитры
				newbits[i * newsts + j * 3 + 1] = bi->bmiColors[index].rgbGreen;
				newbits[i * newsts + j * 3 + 2] = bi->bmiColors[index].rgbRed;
				break;
			}
			case 4:                    //для 4 бит на пиксель
			{
				index = (bits[i * oldsts + j / 2] >> ((1 - j % 2) * 4)) & 0xf; //получаем цвет пикселя, как индекс в палитре файла
				newbits[i * newsts + j * 3] = bi->bmiColors[index].rgbBlue;       //Заполняем массив битовых данных соответствующим цветом из палитры
				newbits[i * newsts + j * 3 + 1] = bi->bmiColors[index].rgbGreen;
				newbits[i * newsts + j * 3 + 2] = bi->bmiColors[index].rgbRed;
				break;
			}
			case 8:                   //для 8 бит на пиксель
			{
				index = bits[i * oldsts + j];                     //получаем цвет пикселя, как индекс в палитре файла
				newbits[i * newsts + j * 3] = bi->bmiColors[index].rgbBlue;       //Заполняем массив битовых данных соответствующим цветом из палитры
				newbits[i * newsts + j * 3 + 1] = bi->bmiColors[index].rgbGreen;
				newbits[i * newsts + j * 3 + 2] = bi->bmiColors[index].rgbRed;
				break;
			}
			case 16:                  //для 16 бит на пиксель
			{
				index = bits[i * oldsts + j * 2] + (bits[i * oldsts + j * 2 + 1] << 8);      //берем 16 бит цвета
				newbits[i * newsts + j * 3] = (index & 0x1f) << 3;                     //разлагаем на составляющие (красный, зеленый, синий)
				newbits[i * newsts + j * 3 + 1] = (index & 0x3e0) >> 2;                  //и преобразуем каждую 5-битную составляющую в 8-битную
				newbits[i * newsts + j * 3 + 2] = (index & 0x7c00) >> 7;
				break;
			}
			case 24:                 //для 24 бит на пиксель
			{
				newbits[i * newsts + j * 3] = bits[i * oldsts + j * 3];              //копируем цветовые составляющие из старого файла в новый
				newbits[i * newsts + j * 3 + 1] = bits[i * oldsts + j * 3 + 1];
				newbits[i * newsts + j * 3 + 2] = bits[i * oldsts + j * 3 + 2];
				break;
			}
			}
		}

	retbih->biBitCount = 24;          //количество бит на пиксель
	retbih->biCompression = BI_RGB;   //без компрессии
	retbih->biSizeImage = newsts * bih->biHeight;   //размер изображения
	retbih->biSize = sizeof(BITMAPINFOHEADER);    //размер заголовка
	retbih->biWidth = bih->biWidth;       //ширина растра
	retbih->biHeight = bih->biHeight;   //высота растра
	retbih->biPlanes = 1;                 //количестао плоскостей, должно быть 1
	retbih->biXPelsPerMeter = bih->biXPelsPerMeter;//разрешение пикселей на метр
	retbih->biYPelsPerMeter = bih->biYPelsPerMeter;

	UnmapViewOfFile(mf);                 //Закрываем маппирование
	CloseHandle(mapfile);                //закрываем файл
	CloseHandle(hbmp);                   //закрываем файл
	return newbits;                     //возвращаем битовые данные
}

unsigned char* readBMP(char* filename)
{
	int i;
	FILE* f = fopen(filename, "rb");
	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

	// extract image height and width from header
	int width, height;
	memcpy(&width, info + 18, sizeof(int));
	memcpy(&height, info + 22, sizeof(int));

	int heightSign = 1;
	if (height < 0) {
		heightSign = -1;
	}

	int size = 3 * width * abs(height);
	unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
	fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
	fclose(f);

	if (heightSign == 1) {
		for (i = 0; i < size; i += 3)
		{
			//code to flip the image data here....
		}
	}
	return data;
}

void CharToByte(char* chars, byte * bytes, unsigned int count) {
	for (unsigned int i = 0; i < count; i++)
		bytes[i] = (byte)chars[i];
}

void ByteToChar(byte * bytes, char* chars, unsigned int count) {
	for (unsigned int i = 0; i < count; i++)
		chars[i] = (char)bytes[i];
}
