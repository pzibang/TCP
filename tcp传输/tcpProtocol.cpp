#include "tcpProtocol.h"


int tcpClientInit(SOCKET *sclient, sockaddr_in *serAddr)
{
	WSADATA wsadata;

	if(WSAStartup(MAKEWORD(2,2),&wsadata) != 0)
	{
		printf("WSA��ʼ��ʧ��\n");
		return 0;
	}

	*sclient = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(*sclient == INVALID_SOCKET)
	{
		printf("socket�ͻ��˴���ʧ��\n");
		return 0;
	}

	(*serAddr).sin_family = AF_INET;
	(*serAddr).sin_port = htons(PORT);
	(*serAddr).sin_addr.S_un.S_addr = inet_addr(DEST_IP_ADDR);
	if( connect(*sclient,(SOCKADDR *)serAddr,sizeof(sockaddr_in)) == SOCKET_ERROR )
	{
		printf("socket�ͻ�������ʧ��\n");
		return 0;
	}
	else
	{
		printf("socket�ͻ������ӳɹ�\n");
	}

	return 1;
}







