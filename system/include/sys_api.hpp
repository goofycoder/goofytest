#ifndef SYS_API_H
#define SYS_API_H

/* Display the network interface's IP and mask info */
void show_interface_info();

/************************************************
 ********* Unit Test APIS ***********************
 ************************************************/
void TEST_RAII_example();

void TEST_exception_example();

void TEST_rlimit();

void TEST_hash();

void TEST_hashtable();

void TEST_pcap_example();

#endif //SYS_API_H
