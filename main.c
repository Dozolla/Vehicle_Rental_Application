#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "structures.h"
#include "system_file.h"
#include "helper.h"
#include "create.h"
#include "delete.h"
#include "display.h"
#include "modify.h"
#include "sort.h"
#include "admin.h"

int main(){
    struct Client *chead=NULL,*ctail=NULL;
    struct Vehicle *vhead=NULL,*vtail=NULL;
    struct Reservation *rhead=NULL,*rtail=NULL;
    int vcnt=0,ccnt=0,rcnt=0;

    printf("Welcome to the Car Rental System!\n");
    Options(&vhead, &vtail, &chead, &ctail, &rhead, &rtail, &vcnt, &ccnt, &rcnt);

    
    /*
    if( n == 1)
        create();
    else if( n == 2)
        delete();
    else if( n == 3)
        display();
    else if( n == 4)
        modify();
    else if( n == 5)
        sort();
    else if( n == 6)
        admin();
    else if( n == 7)
        exit(0);
    else
        printf("Invalid Input\n");*/
    return 0;
}