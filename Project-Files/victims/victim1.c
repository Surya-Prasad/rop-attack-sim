#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util-program.h"

void get_saber(int key){

    if(key != V1_TARGET){
        printf("Wrong key to collect your saber. Keep trying you must. \n");
        printf("Expected: %d, Received: %d\n", V1_TARGET, key);  /* CHANGED */
    }
    else{
        printf("Congratulations Padawan! You wield your first lightsaber.\n");
        printf("\nSaber ID = %d\n", STUDENT_ID);  /* CHANGED */
    }
    return;
}


int enter_temple(int argc, char* inputStr){

    char* buf_ptr = NULL;
    int a,b,c = 0;
    int key = 0;
    char buf[V1_SIZE];  /* CHANGED: Now student-specific */
    buf_ptr = buf;
    initialize_buffer(buf_ptr,V1_SIZE);

    a = 45;
    b = 46;
    c = 47;
    key = argc;
    strcpy(buf_ptr, inputStr);
    buf_ptr += strlen(inputStr);

    printf("Task 1 :- Collect your saber, Padawan!\n");
    get_saber(key);

    c = a+b+c;
    b = a+b+c;
    a = a+b+c;
    return 0;
}

int main(int argc, char **argv){

    if ( argc < 2 ) {
      printf("These are not the arguments you are looking for!\n");
      exit(0);
    }
    printf("Welcome to the Jedi Academy - CSE543\n");
    char *str;
    read_from_file(argv[1], &str);
    enter_temple(argc, str);
    return 0;
}