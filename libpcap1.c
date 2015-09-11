#include <stdio.h>
int main()
{
	char *dev, errbuf[PCAP_ERRBUF_SIZE];
	dev = pcap_lookupdev(errbuf);
	printf("Device:%s", dev);
	return 0;
}