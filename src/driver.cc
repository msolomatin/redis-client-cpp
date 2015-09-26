#include <iostream>
#include <vector>
#include <string>
#include "../include/Redis.h"

int main() {
  
  Redis r("localhost", 6379, "");
  auto value = r.ping("preved");
  std::cout << value << std::endl;
  r.set("hello world");
  std::cout << r.get("hello") << std::endl;
  r.quit();

  return 0;
}
