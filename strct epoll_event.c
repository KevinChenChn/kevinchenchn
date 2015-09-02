typedef union epoll_data{
	void *ptr;
	int fd;
	__uint32_t u32;
	__unit64_t u64;
}epoll_data_t;

struct epoll_event
{
	__unit32_t events;
	rpoll_data_t data;
};