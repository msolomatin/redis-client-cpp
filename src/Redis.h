#ifndef REDIS_H
#define REDIS_H

#include <string>

class Redis {
public:
  Redis();
  Redis(std::string url, int port, std::string password);
  ~Redis();

  std::string ping(std::string arg);
  std::string ping();
  std::string quit();
  std::string set(std::string arg);
  std::string get(std::string key);
private:
  class Connection;
  std::unique_ptr<Connection> PConnection;
};
#endif
