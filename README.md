# redis-client-cpp

redis-client-cpp is a small C++11 library for Redis. This library
is at the earliest stage of development. Currently it supports only
SET, GET and PING commands. Library is being developed and tested on Mac OS X 10.10.5.
'Redis r("localhost", 6379, "");
std::cout << r.ping() << std::endl;
r.set("hello github");
std::cout << r.get("hello") << std::endl;
r.quit();'
