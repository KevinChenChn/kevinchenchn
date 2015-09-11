#include <stdio.h>
pcap_t *handle; /* 会话的句柄 */
char dev[] = "eth0"; /* 执行嗅探的设备 */
char errbuf[PCAP_ERRBUF_SIZE]; /* 存储错误 信息的字符串 */
struct bpf_program filter; /*已经编译好的过滤表达式*/
char filter_app[] = "port 23"; /* 过滤表达式*/
bpf_u_int32 mask; /* 执行嗅探的设备的网络掩码 */
bpf_u_int32 net; /* 执行嗅探的设备的IP地址 */
pcap_lookupnet(dev, &net, &mask, errbuf);
handle = pcap_open_live(dev, BUFSIZ, 1, 0, errbuf);
pcap_compile(handle, &filter, filter_app, 0, net);
pcap_setfilter(handle, &filter);