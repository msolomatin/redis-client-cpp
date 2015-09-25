
#include "Redis.h"
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

#ifndef CONNECTION_H
#define CONNECTION_H

class Redis::Connection 
public:
  Connection();
  Connection(std::string url, int port, std::string password);
  std::string SendCommand(std::string command);
private:
  void Init(std::string url, int port, std::string password);
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
};

#endif
