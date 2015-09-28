#ifndef REDISCLIENTCPP_REDIS_H_
#define REDISCLIENTCPP_REDIS_H_

#include <string>
#include <memory>

class Redis {
public:
  Redis();
  Redis(const std::string &url, const int port, const std::string &password);
  ~Redis();

  std::string ping();
  std::string ping(const std::string &arg);  
  std::string quit();
  std::string set(const std::string &arg);
  std::string get(const std::string &key);
  bool exists(const std::string &key);
private:
  class Connection;
  std::unique_ptr<Connection> PConnection;
};
#endif  // REDISCLIENTCPP_REDIS_H_
