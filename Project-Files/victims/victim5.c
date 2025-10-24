#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util-program.h"

void round_1(){
    printf("You carry Yoda through the woods\n");
    printf("Round Code = %d\n\n", V5_ROUND1);
    return;
}

void round_2(){
    printf("You start to harness the force\n");
    printf("Round Code = %d\n\n", V5_ROUND2);
    return;
}

void round_3(){
    printf("You think you are ready and leave to face Vader\n");
    printf("Yoda readies your ship\n");
    printf("Round Code = %d\n", V5_ROUND3);
    printf("Training ID = %d\n\n", STUDENT_ID);
    return;
}

int training(int argc, char* inputStr){

    char* buf_ptr = NULL;
    int key = 0;

    char buf[V5_SIZE];
    buf_ptr = buf;
    initialize_buffer(buf,V5_SIZE);

    sscanf(inputStr, "%s", buf_ptr);
    buf_ptr += strlen(inputStr);
    return 0;
}

int main(int argc, char **argv){

    if ( argc < 2 ) {
      printf("These are not the arguments you are looking for!\n");
      exit(0);
    }
    printf("Welcome to your training\n");
    char *str;
    read_from_file(argv[1], &str);
    training(argc, str);
    return 0;
}