#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util-program.h"

int crystal(char* inputStr){

    char* buf_ptr = NULL;
    char buf[V2_SIZE];
    buf_ptr = buf;
    initialize_buffer(buf_ptr,V2_SIZE);
    int p,g,b;
    p = g = b = 0;

    sprintf(buf_ptr, "%s", inputStr);
    buf_ptr += strlen(inputStr);

    if(p == V2_PURPLE){
        printf("\nPurple\n");
        printf("Crystal ID = %d\n", STUDENT_ID);
    }else if(g == V2_GREEN){
        printf("\nGreen\n");
        printf("Crystal ID = %d\n", STUDENT_ID);
    }else if(b == V2_BLUE){
        printf("\nBlue\n");
        printf("Crystal ID = %d\n", STUDENT_ID);
    }else{
        printf("\nRed, fallen to the dark side you have\n");
        printf("Expected - Purple: 0x%08x, Green: 0x%08x, Blue: 0x%08x\n",
               V2_PURPLE, V2_GREEN, V2_BLUE);
        printf("Received - p: 0x%08x, g: 0x%08x, b: 0x%08x\n", p, g, b);
    }

    return 0;
}

int main(int argc, char **argv){

    if ( argc < 2 ) {
      printf("These are not the arguments you are looking for!\n");
      exit(0);
    }
    printf("You now must pick your Kyber crystal\n");
    char *str;
    int x = crystal(argv[1]);
    return 0;
}