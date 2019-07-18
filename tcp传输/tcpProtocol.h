#ifndef __TCP_H
#define __TCP_H

#include <stdio.h>
#include <winsock2.h>

#define DEST_IP_ADDR "192.168.1.162"
#define PORT 8080

int tcpClientInit(SOCKET* sclient, sockaddr_in* serAddr);    //TCP≥ı ºªØ





#endif