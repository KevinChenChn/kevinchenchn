/*************************************************************************
  > File Name: server.c
  > Author: Comst
  > Mail:750145240@qq.com 
  > Created Time: Sat 15 Aug 2015 08:44:27 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<pthread.h>
typedef struct nc
{
	int client_fd;
	struct sockaddr_in clientaddr;
	socklen_t clientaddrlen;
	struct nc *next;
}client,*pclient;

fd_set fds;
char buf[256];
struct timeval tm;
int fn;
char ip[20];
int port;
char message[256];

void insert(pclient *phead,pclient pnew)
{
	pclient p1;
	p1=*phead;
	while(p1->next)
	{
		p1=p1->next;
	}
	p1->next=pnew;
}



void *func(void *args)
{
	pclient phead=(pclient)args;
	while(1)
	{
		FD_ZERO(&fds);
		pclient p1=phead;
		while(p1->next)
		{
			p1=p1->next;
			FD_SET(p1->client_fd,&fds);
		}
		tm.tv_sec=3;
		tm.tv_usec=0;
		select(1024,&fds,NULL,NULL,&tm);
		p1=phead;
		pclient p2;
		while(p1->next)
		{
			p2=p1;
			p1=p1->next;
			if(FD_ISSET(p1->client_fd,&fds))
			{
				memset(ip,0,20);
				memset(buf,0,256);
				memset(message,0,256);
				fn=recv(p1->client_fd,buf,256,0);
				inet_ntop(AF_INET,&(p1->clientaddr.sin_addr),ip,20);
				port=ntohs(p1->clientaddr.sin_port);
				if(fn==0||strncmp(buf,"@#$%",fn-1)==0)
				{
					sprintf(message,"ip %s port %d was off\n",ip,port);
					p2->next=p1->next;
					free(p1);
				}
				else
				{
					sprintf(message,"a message from %s port %d:%s",ip,port,buf);
				}
				pclient p3=phead;
				while(p3->next)
				{
					p3=p3->next;
					send(p3->client_fd,message,strlen(message),0);
				}
			}
		}
	}

}



int main(int argc,char *argv[])
{
	pthread_t tid;
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd==-1)
	{
		perror("socket");
		return 0;
	}
	struct sockaddr_in seraddr;
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(atoi(argv[2]));
	inet_pton(AF_INET,argv[1],&seraddr.sin_addr);
	socklen_t seraddrlen=sizeof(seraddr);
	if(bind(sfd,(struct sockaddr *)&seraddr,seraddrlen)==-1)
	{
		perror("bind");
		return 0;
	}
	if(listen(sfd,10)==-1)
	{
		perror("listen");
		return 0;
	}
	int new_fd;
	struct sockaddr_in client_addr;
	socklen_t client_addrlen=sizeof(struct sockaddr);
	pclient phead=(pclient)calloc(1,sizeof(client));
	pthread_create(&tid,NULL,func,(void *)phead);
	while(1)
	{
		new_fd=accept(sfd,(struct sockaddr *)&client_addr,&client_addrlen);
		if(new_fd==-1)
		{
			perror("accept");
			return 0;
		}
		if(new_fd!=-1)
		{
			pclient pc=(pclient)calloc(1,sizeof(client));
			pc->client_fd=new_fd;
			pc->clientaddr.sin_family=AF_INET;
			pc->clientaddr.sin_port=client_addr.sin_port;
			pc->clientaddr.sin_addr.s_addr=client_addr.sin_addr.s_addr;
			pc->clientaddrlen=client_addrlen;
			insert(&phead,pc);
			memset(ip,0,20);
			memset(buf,0,256);
			memset(message,0,256);
			inet_ntop(AF_INET,&(pc->clientaddr.sin_addr),ip,20);
			port=ntohs(pc->clientaddr.sin_port);
			sprintf(message,"%s port %d is on\n",ip,port);
			pclient p3=phead;
			while(p3->next)
			{
				p3=p3->next;
				send(p3->client_fd,message,strlen(message),0);
			}
		}
	}
}
