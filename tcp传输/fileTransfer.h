#ifndef __fileTransfer__H
#define __fileTransfer__H
#include <winsock2.h>
#include <stdio.h>
#define FILE_NAME_MAX_SIZE    1024  
#define MAX_DATA_BLOCK_SIZE   8192   

int fileSend(char *fileName, SOCKET sclient);     //�ļ����Ͳ���
int fileLength(FILE *fp, SOCKET sclient);   //ͳ���ļ�����
int fileRecv(char *fileName, char *recvData, SOCKET sclient);
int wordRecv(char *revData, SOCKET sclient);
#endif