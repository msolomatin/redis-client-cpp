#include "Redis.h"
#include "Connection.h"
#include <iostream>

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

Redis::Connection::Connection() {}

Redis::Connection::Connection(std::string url, int port, std::string password) {
  Init(url, port, password);
}

void Redis::Connection::Init(std::string url, int port, std::string password) {
    portno = port;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
      std::cerr << "ERROR opening socket" << std::endl;

    server = gethostbyname(url.c_str());
  
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
      std::cerr << "ERROR connecting" << std::endl;
}

  std::string Redis::Connection::SendCommand(std::string command) {
    command = command + "\n";
    n = write(sockfd, command.c_str(), command.length());
    if (n < 0)
      std::cerr << "ERROR writing to socket" << std::endl;

    char buffer[256];
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);

    if (n < 0)
      std::cerr << "ERROR reading from socket" << std::endl;

    return buffer;
  }