#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util-program.h"

void hyperspace(){
    printf("You escaped to the outer rim, well done!\n");
    printf("Escape ID = %d\n", STUDENT_ID);  /* CHANGED: Added verification */
    exit(0);
    return;
}

void hoth(int argc, char* inputStr){

    char* buf_ptr = NULL;
    int key = argc;

    char buf[V4_SIZE];
    buf_ptr = buf;
    initialize_buffer(buf,V4_SIZE);

    sscanf(inputStr, "%s", buf_ptr);
    buf_ptr += strlen(inputStr);
    return;
}

int main(int argc, char **argv){

    if ( argc < 2 ) {
      printf("These are not the arguments you are looking for!\n");
      exit(0);
    }
    printf("The Empire Strikes Back, escape Hoth!\n");
    char *str;
    read_from_file(argv[1], &str);
    hoth(argc, str);
    printf("The empire bested the rebel alliance. Try again you must.\n");
    return 0;
}