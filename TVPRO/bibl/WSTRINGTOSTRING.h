//WSTRING TO STRING
inline std::wstring ConvertEncoding(const std::string& normalString)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
	return convert.from_bytes(normalString);
}
//STRING TO WSTRING
inline std::string ConvertEncodingBack(const std::wstring& wideString)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
	return convert.to_bytes(wideString);
}