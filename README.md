[![Build Status](https://travis-ci.org/msolomatin/redis-client-cpp.svg)](https://travis-ci.org/msolomatin/redis-client-cpp) [![Coverity Scan Build Status](https://scan.coverity.com/projects/6455/badge.svg)](https://scan.coverity.com/projects/msolomatin-redis-client-cpp)

#Redis API Client Library for C++

##Description
Redis API Client Library is a small C++11 library for [Redis](http://redis.io/) and allows you to call Redis APIs
directly from your C++ code.

##Alpha
This library is at the earliest stage of development. Currently it supports only
SET, GET and PING commands. Library is being developed and tested on Mac OS X 10.10.5.

##Requirements
C++11 compatible compiler.

##Basic Example

```C++
#include "Redis.h"

// ...

Redis r("localhost", 6379, "");
std::cout << r.ping() << std::endl;
r.set("hello github");
std::cout << r.get("hello") << std::endl;
r.quit();
```
