#pragma once

namespace http
{
  size_t write(char* ptr, size_t size, size_t nmemb, std::string* data);
  class get {
    std::string Text = "";
    int StatusCode = 0;
  public:
    get(std::string url);
    const std::string text() const;
    const int status() const;
  };
}
