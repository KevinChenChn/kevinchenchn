/*************************************************************************
	> File Name: client.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Sat 15 Aug 2015 09:06:48 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<errno.h>
#include<string.h>
int main(int argc,char *argv[])
{
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in seraddr;
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(atoi(argv[2]));
	inet_pton(AF_INET,argv[1],&seraddr.sin_addr);
	socklen_t seraddrlen=sizeof(seraddr);
	if(connect(sfd,(struct sockaddr*)&seraddr,seraddrlen)==-1)
	{
		perror("connect");
		return 0;
	}
	char buf[256];
	int fn;
	struct timeval tm;
	fd_set fds;
	char s[20];
	int port;
	while(1)
	{
		FD_ZERO(&fds);
		FD_SET(0,&fds);
		FD_SET(sfd,&fds);
		tm.tv_sec=3;
		tm.tv_usec=0;
		select(sfd+1,&fds,NULL,NULL,0);
		if(FD_ISSET(0,&fds))
		{
			memset(buf,0,256);
			fn=read(0,buf,256);
			if(fn-1==0)
			{
				continue;
			}
			send(sfd,buf,fn,0);
			if(strncmp(buf,"@#$%",fn-1)==0)
			{
				printf("bey!\n");
				break;
			}
		}
		if(FD_ISSET(sfd,&fds))
		{
			memset(buf,0,256);
			fn=recv(sfd,buf,256,0);
			write(1,buf,fn);
		}
	}
}
