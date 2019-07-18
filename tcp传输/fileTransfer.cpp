#include "fileTransfer.h"
#include "tcpProtocol.h"

int fileSend(char *fileName, SOCKET sclient)
{
	FILE *fp;
	char ch[255];
    send(sclient, "start sending", sizeof("start sending"), 0);  //提示开始发送数据

    if ((fp = fopen(fileName, "rb"))== NULL)  
    {  
        printf("File %s Can Not Open To Read!\n", fileName);  
        return 0;  
    }

	 while(!feof(fp))
    {
		fgets(ch, sizeof(ch),fp);
		send(sclient, ch, sizeof(ch), 0);
		memset(ch, 0,sizeof(ch));
    }	
	
	fclose(fp);
	return 1;
}

int fileLength(FILE *fp, SOCKET sclient)   //统计文件长度
{
	 int num;
	 fseek(fp,0,SEEK_END);
	 num=ftell(fp);
	 fseek(fp,0,SEEK_SET);
	 return num;
}
/*
 *参数说明：
 *fileName：保存文件名
 *
*/
int fileRecv(char *fileName, char *revData, SOCKET sclient)
{	
	FILE *fp;
	int ret = -1;
	send(sclient, "asd", strlen("asd"), 0);

	while(1)
	{
		ret = recv(sclient,fileName,255,0);
		if(ret > 0)
		{
			fileName[ret] = '\0';
			puts(fileName);
			break;
		}	
	}

    if ((fp = fopen(fileName, "wb+"))== NULL)  
    {  
        printf("File %s Can Not Open To Read!\n", fileName);  
        return 0;  
    }
	else
	{
		printf("File Open Sucessful!\n");
	}
	while (1)
	{
		printf("waitting ,if you wann't to continue,send end to close \n");
		int ret = recv(sclient, revData, 7680, 0);
		if (ret==3)
		{
			if (revData[0] == 'e'&&revData[1] == 'n'&&revData[2] == 'd')
			{
				printf("接收完成!");
				break;
			}
		}
		if (ret>0)
		{
			fwrite(revData, 1, ret, fp);
		}
	}

	fclose(fp);
	return 1;
}


int wordRecv(char *revData, SOCKET sclient)
{
	int ret = -1; 
	while(1)
	{
		ret = recv(sclient,revData,1024,0);
		if (ret==3)
		{
			if (revData[0] == 'e'&&revData[1] == 'n'&&revData[2] == 'd')
			{
				printf("接收完成!");
				return ret;
			}
		}
		else if(ret > 0)
		{
			revData[ret] = '\0';
			puts(revData);
			//return ret;			//加返回值，只发送一次
		}	
	}
	return 1;
}




