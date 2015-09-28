#include "../include/Redis.h"
#include "Connection.h"
#include <string>

Redis::Redis() : PConnection (new Connection ()) {}

Redis::Redis(const std::string &url, const int port, const std::string &password) :
  PConnection (new Connection(url, port, password)) {}

Redis::~Redis() {}

std::string Redis::ping(const std::string &arg) {
  return PConnection->ping();
}

std::string Redis::ping() {
  return PConnection->ping();
}

std::string Redis::quit() {
  return PConnection->quit();
}

std::string Redis::set(const std::string &arg) {
  return PConnection->set(arg);
}

std::string Redis::get(const std::string &key) {
  return PConnection->get(key);
}

bool Redis::exists(const std::string &key) {
  return PConnection->exists(key);
}
