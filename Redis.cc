#include "Redis.h"
#include "Connection.h"
#include <string>

Redis::Redis() : PConnection (new Connection ()) {
  
}

Redis::Redis(std::string url, int port, std::string password) :
  PConnection (new Connection(url, port, password)) {
  
}

Redis::~Redis() {
  
}

std::string Redis::ping(std::string arg) {
  return PConnection->SendCommand("PING " + arg);
}

std::string Redis::ping() {
  return PConnection->SendCommand("PING");
}

std::string Redis::quit() {
  return PConnection->SendCommand("QUIT");
}
std::string Redis::set(std::string arg) {
  return PConnection->SendCommand("SET " + arg);
}

std::string Redis::get(std::string key) {
  return PConnection->SendCommand("GET " + key);
}
