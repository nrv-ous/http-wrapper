# http-wrapper

Little wrapper for libcurl that I wrote up in a few minutes.

```cpp
#include "iostream"
#include "http.h"

int main()
{
  auto req = http::get("https://github.com");
  
  std::cout << req.text() << '\n';
}
```
