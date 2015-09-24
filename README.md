#Redis API Client Library for C++

##Description
Redis API Client LIbrary is a small C++11 library for Redis and allows you to call Redis functions
directly from your code.

##Alpha
This library is at the earliest stage of development. Currently it supports only
SET, GET and PING commands. Library is being developed and tested on Mac OS X 10.10.5.


```C++
#include "Redis.h"

// ...

Redis r("localhost", 6379, "");
std::cout << r.ping() << std::endl;
r.set("hello github");
std::cout << r.get("hello") << std::endl;
r.quit();
```
