#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util-program.h"

void capture(){
    printf("You were captured by storm troopers\n");
    printf("\n");
    return;
}

void rescue(){
    printf("You have opened the shell and rescued Leia!!\n");
    printf("Rescue ID = %d\n", STUDENT_ID);  /* CHANGED: Added verification */
    system("/bin/sh");
    return;
}

int death_star(int argc, char* inputStr){

    char* buf_ptr = NULL;
    void (*functionPtr) () = capture;
    int key = argc;

    char buf[V3_SIZE];
    buf_ptr = buf;
    initialize_buffer(buf,V3_SIZE);

    sprintf(buf_ptr, "%s", inputStr);
    buf_ptr += strlen(inputStr);

    functionPtr();

    return 0;
}

int main(int argc, char **argv){

    if ( argc < 2 ) {
      printf("These are not the arguments you are looking for!\n");
      exit(0);
    }
    printf("You have made it to death star to rescue Princess Leia\n");
    printf("To do so open a shell\n");
    char *str;
    read_from_file(argv[1], &str);
    death_star(argc, str);
    return 0;
}