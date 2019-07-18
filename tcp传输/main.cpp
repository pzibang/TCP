#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include "tcpProtocol.h"
#include "fileTransfer.h"

#pragma comment(lib,"ws2_32.lib")


int main(void)
{
	char senddata[255];
	char revdata[1024];
	char fileName[FILE_NAME_MAX_SIZE + 1];    
	SOCKET sclient ;
	sockaddr_in serAddr;

	if(tcpClientInit(&sclient, &serAddr) == 0)			//tcp初始化
	{
		return 0;
	}
	printf("waitting \n");

	send(sclient, "asd", strlen("asd"), 0);

	//while(1)
	//{
	//	printf("input the words\r\n");
	//	gets(senddata);
	//	if (senddata[0] == 'e'&&senddata[1] == 'n'&&senddata[2] == 'd')
	//	{
	//		printf("停止发送输入!");
	//		break;
	//	}
	//	send(sclient, senddata, strlen(senddata), 0);
	//}

	wordRecv(revdata, sclient);

	closesocket(sclient);
	WSACleanup();

	getchar();
	return 0;
}