#include <string>
#define CURL_STATICLIB
#include "curl/curl.h"
#pragma warning(disable : 4996)
#pragma comment(lib,"bibl/curl/libcurl_a.lib")
#pragma comment (lib,"Ws2_32.lib")
#pragma comment (lib,"Wldap32.lib")
#pragma comment (lib,"Crypt32.lib")
#pragma comment (lib,"Normaliz.lib")

//download_data
static char download_data(char* ptr, size_t size, size_t nmemb, FILE* data)
{
	return fwrite(ptr, size, nmemb, data);
}

//Loading Curl File Pro (string)
void DownoladfileURLPRO_string(string url, string file, int fileok)
{
	int st______;
	if (fileok == 1)
	{
		const char* d = file.c_str();
		struct stat s = { 0 };

		if (!stat(d, &s)) {
			st______ = 0;
		}
		else {
			st______ = 1;
		}
	}
	else
	{
		st______ = 1;
	}

	if (st______ == 1)
	{
		if (url != "" || url != "0" || file != "" || file != "0")
		{
			CURL* image;
			CURLcode imgresult;
			FILE* fp = nullptr;
			const char* url_ = url.c_str();;
			image = curl_easy_init();
			if (image)
			{
				// Open file 
				fp = fopen(file.c_str(), "wb");
				if (fp == NULL) cout << "File cannot be opened";
				curl_easy_setopt(image, CURLOPT_FOLLOWLOCATION, 1);
				curl_easy_setopt(image, CURLOPT_USERAGENT, "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36");
				curl_easy_setopt(image, CURLOPT_WRITEFUNCTION, NULL);
				curl_easy_setopt(image, CURLOPT_WRITEDATA, fp);
				curl_easy_setopt(image, CURLOPT_URL, url_);
				// Grab image 
				imgresult = curl_easy_perform(image);
				if (imgresult)
					cout << "Cannot grab the image!\n";
			}
			// Clean up the resources 
			curl_easy_cleanup(image);
			// Close the file 
			fclose(fp);
		}
	}
}