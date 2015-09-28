
#include "../include/Redis.h"
#include <string>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <string.h>
#include <signal.h>
#include <assert.h>
#include <syslog.h>


#include <sys/types.h>
#include <sys/select.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/wait.h>

#include <netinet/in.h>

#include <arpa/ftp.h>
#include <arpa/inet.h>
#include <arpa/telnet.h>

#ifndef REDISCLIENTCPP_CONNECTION_H_
#define REDISCLIENTCPP_CONNECTION_H_

class Redis::Connection {
public:
  Connection();
  Connection(const std::string &url, const int port, const std::string &password);
  std::string ping(const std::string &arg);
  std::string ping();
  std::string quit();
  std::string set(const std::string &arg);
  std::string get(const std::string &key);
  bool exists(const std::string &args);
private:
  void Open(const std::string &url, const int port, const std::string &password);
  std::string SendCommand(std::string command);
  
  // Next three helper functions should be in a separate class or namespace,
  // but I'll leave them here for now
  bool ToBool(const std::string &response);
  int ToInt(const std::string &response);
  std::string ToString(const std::string &response);

  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
};

#endif  // REDISCLIENTCPP_CONNECTION_H_
