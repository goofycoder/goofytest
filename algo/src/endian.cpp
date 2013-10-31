/*
    Endianness specifies how data bytes are stored in order in memory
    
    Big Endian: 
        Most significant byte is stored at smallest address.

    Date: 10/31/2013
 */
#include <stdio.h>

bool isBigEndian()
{
    int hex = 0x1;

    char *val = (char *)&hex;

    printf("%x\n", hex);

    printf("%hhx %hhx %hhx %hhx\n", val[0], val[1], val[2], val[3]);    // 'hh' means you are passing a char value

    if (val[0] == 0x1) {
        return false;       // least significant byte stores at lowest memory addess [LITTLE ENDIAN]
    } else {
        return true;
    }
}

void TEST_endian()
{
    if (isBigEndian()) {
        printf("Big Endian.\n");
    } else {
        printf("Little Endian.\n");
    }
}
