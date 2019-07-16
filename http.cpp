#include "string"
#include "http.h"
#include "curl/curl.h"

#pragma comment(lib, "curl/libcurl_a.lib")

namespace http
{
  size_t write(char* ptr, size_t size, uint32_t nmemb, std::string* data) {
    data->append(ptr, size * nmemb);
    return size * nmemb;
  }

  get::get(std::string url)
  {
    CURL* curl = curl_easy_init();
    if (curl)
    {
      curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &write);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &Text);
      curl_easy_perform(curl);
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &StatusCode);
      curl_easy_cleanup(curl); 
    }
  }

  const std::string get::text() const
  {
    return Text;
  }

  const int get::status() const
  {
    return StatusCode;
  }
}
