#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util-program.h"

void xwings(int argc, char* inputStr){

    char* buf_ptr = NULL;
    int key = argc;

    char buf[V9_SIZE];
    buf_ptr = buf;
    initialize_buffer(buf,V9_SIZE);

    sprintf(buf_ptr, "%s", inputStr);
    buf_ptr += strlen(inputStr);
    return;
}

int main(int argc, char **argv){

    if ( argc < 2 ) {
      printf("These are not the arguments you are looking for!\n");
      exit(0);
    }
    printf("Get Shell from here!\n");
    char *str;
    xwings(argc, argv[1]);  /* Takes input from command line, not file */
    return 0;
}