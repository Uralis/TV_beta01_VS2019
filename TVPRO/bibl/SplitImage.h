//Обрезка изображений SplitImage(L"test.gif",L"Split.bmp",300,300,500,500,1);
void SplitImage(LPCWSTR pszFrom, LPCWSTR pszTo, int x, int y, int cx, int cy, double dblScale)
{
	CLSID encoderClsidBMP;
	GetEncoderClsid(L"image/bmp", &encoderClsidBMP);

	Image* imageLoad = new Image(pszFrom);
	Bitmap* bitmapSave = new Bitmap(cx, cy);
	Image* imageSplit = (Image*)bitmapSave;
	Graphics* g = Graphics::FromImage(imageSplit);
	g->DrawImage(imageLoad, -x, -y,
		imageLoad->GetWidth() * dblScale, imageLoad->GetHeight() * dblScale);
	if (((Image*)imageSplit)->Save(pszTo, &encoderClsidBMP, NULL) == Ok)
		_tprintf(_T("Image saved\n"));
	delete imageLoad;
	delete bitmapSave;
	delete g;
}
