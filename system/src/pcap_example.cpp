/*
   To compile:
     $gcc pcap_example.cpp -lpcap

   Looks for an interface, and lists the network ip
   and mask associated with that interface.

   inet_ntoa():   convert internet host addr to dot-decimal notation string

   Note: run with sudo
*/
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h> 
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void show_interface_info()
{
    char *dev;              /* name of the device to use */ 
    char *net;              /* dot notation of the network address */
    char *mask;             /* dot notation of the network mask    */
    bpf_u_int32 netp;       /* ip          */
    bpf_u_int32 maskp;      /* subnet mask */
    struct in_addr addr;    /* network byte order */
    char errbuf[PCAP_ERRBUF_SIZE];
    int ret;                /* return code */

    /* ask pcap to find a valid device for use to sniff on */
    dev = pcap_lookupdev(errbuf);
    if(dev == NULL) {
        printf("%s\n",errbuf);
        exit(1);
    }

    /* print out device name */
    printf("INTERFACE:\t%s\n",dev);

    /* Pcap: look up network address and mask of the device */
    ret = pcap_lookupnet(dev,
                         &netp,
                         &maskp,
                         errbuf);
    if(ret == -1) {
        printf("%s\n",errbuf);
        exit(1);
    }

    /* Get the network address in a human readable form */
    addr.s_addr = netp;
    net = inet_ntoa(addr);
    if(net == NULL) {
        perror("inet_ntoa");
        exit(1);
    }
    printf("NETWORK IP:\t%s\n",net);

    /* Device's mask */
    addr.s_addr = maskp;
    mask = inet_ntoa(addr);
    if(mask == NULL) {
        perror("inet_ntoa");
        exit(1);
    }
    printf("SUBNET MASK:\t%s\n",mask);
}

void TEST_pcap_example() 
{
    printf("TEST pcap lib functionality.\n");

    show_interface_info();
}
