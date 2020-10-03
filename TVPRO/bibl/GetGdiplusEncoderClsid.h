// BMP, GIF, JPEG, PNG, TIFF, Exif, WMF, and EMF
// requires GDIPlus
HBITMAP mLoadImg(WCHAR* szFilename)
{
	HBITMAP result = NULL;

	Gdiplus::Bitmap* bitmap = new Gdiplus::Bitmap(szFilename, false);
	bitmap->GetHBITMAP(NULL, &result);
	delete bitmap;
	return result;
}
//Конвертер изображений
HRESULT GetGdiplusEncoderClsid(const std::wstring & format, GUID * pGuid)
{
	HRESULT hr = S_OK;
	UINT  nEncoders = 0;          // number of image encoders
	UINT  nSize = 0;              // size of the image encoder array in bytes
	std::vector<BYTE> spData;
	Gdiplus::ImageCodecInfo* pImageCodecInfo = NULL;
	Gdiplus::Status status;
	bool found = false;

	if (format.empty() || !pGuid)
	{
		hr = E_INVALIDARG;
	}

	if (SUCCEEDED(hr))
	{
		*pGuid = GUID_NULL;
		status = Gdiplus::GetImageEncodersSize(&nEncoders, &nSize);

		if ((status != Gdiplus::Ok) || (nSize == 0))
		{
			hr = E_FAIL;
		}
	}

	if (SUCCEEDED(hr))
	{
		spData.resize(nSize);
		pImageCodecInfo = (Gdiplus::ImageCodecInfo*) & spData.front();
		status = Gdiplus::GetImageEncoders(nEncoders, nSize, pImageCodecInfo);
		if (status != Gdiplus::Ok)
		{
			hr = E_FAIL;
		}
	}

	if (SUCCEEDED(hr))
	{
		for (UINT j = 0; j < nEncoders && !found; j++)
		{
			if (pImageCodecInfo[j].MimeType == format)
			{
				*pGuid = pImageCodecInfo[j].Clsid;
				found = true;
			}
		}

		hr = found ? S_OK : E_FAIL;
	}

	return hr;
}
//Кодер изображений
int GetEncoderClsid(const WCHAR * format, CLSID * pClsid)
{
	UINT  num = 0;
	UINT  size = 0;
	GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;
	ImageCodecInfo * pImageCodecInfo = (ImageCodecInfo*)malloc(size);
	GetImageEncoders(num, size, pImageCodecInfo);
	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;
		}
	}
	free(pImageCodecInfo);
	return -1;
}