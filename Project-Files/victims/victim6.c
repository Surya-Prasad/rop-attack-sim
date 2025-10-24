#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util-program.h"

struct ship {
    int (*ship)();
};

struct jedi {
    char name[V6_SIZE];
};

void duel_loss(){
    printf("You are defeat by Boba Fett, Jabba's rule remains\n");
    return;
}

void duel_win(){
    printf("You rescue Han from Jabba!\n");
    printf("Rescue ID = %d\n", STUDENT_ID);
    return;
}

int main(int argc, char **argv)
{
    if ( argc < 2 ) {
        printf("These are not the arguments you are looking for!\n");
        exit(0);
    }

    printf("");
    struct jedi *master;
    struct ship *ship_ptr;
    master = malloc(sizeof(struct jedi));
    ship_ptr = malloc(sizeof(struct ship));
    ship_ptr->ship = duel_loss;

    char *str;
    read_from_file(argv[1], &str);
    strcpy(master->name, str);
    ship_ptr->ship();

    return 0;
}