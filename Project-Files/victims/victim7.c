#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util-program.h"

void ewoks(int argc, char* inputStr){

    char* buf_ptr = NULL;
    int key = argc;

    char buf[V7_SIZE];
    buf_ptr = buf;
    initialize_buffer(buf,V7_SIZE);
    printf("You make friends with Ewoks, they want to know your name:\n");
    printf("\nYour Name is :- \n");
    sprintf(buf_ptr, "%s", inputStr);
    buf_ptr += strlen(inputStr);
    return;
}

int main(int argc, char **argv){

    if ( argc < 2 ) {
      printf("These are not the arguments you are looking for!\n");
      exit(0);
    }
    printf("You travel to Endor\n");
    char *str;
    read_from_file(argv[1], &str);
    ewoks(argc, str);
    return 0;
}