for(;;)
{
	nfds = epoll_wait(epfd,events,20,500);
	for(i=0li<nfds;++i)
	{
		if(events[i].data.fd==listenfd)
		{
			connfd = accept(listenfd,(sockaddr *)&clientaddr,&clilen);
			ev.data.fd=connfd;
			ev.events=EPOLLIN|EPOLLET;
			epoll_ctl(epfd,EPOLL_CTL_ADD,connfd,&ev);
		}
		else if (events[i].events&EPOLLIN)
		{
			n = read(sockfd,line,MAXLINE)<0;

			
			ev.data.ptr = md;
			ev.events=EPOLLOUT|EPOLLET;
			epoll_ctl(epfd,EPOLL_CTL_MOD,sockfd,&ev);
		}
		else if(events[i].events&EPOLLOUT)
		{
			struct myepoll_data* md = (myepoll_data*)events[i].data.ptr;
			sockfd = md->fd;
			send(sockfd,md->ptr,strlen(((char*)md->ptr),0);
				ev.data.fd=sockfd;
				ev.events=EPOLLIN|EPOLLET;
				epoll_ctl(epfd,EPOLL_CTL_MOD,sockfd,&ev);
		}
		else
		{
			///////
		}
	}
}