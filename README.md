# http-wrapper

Simple wrapper for libcurl that I wrote in a few minutes.

```cpp
#include "http.h"

int main()
{
  auto req = http::get("https://github.com");
  
  std::cout << req.text() << '\n';
}
```
