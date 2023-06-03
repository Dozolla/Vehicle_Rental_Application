#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <errno.h>

#include "structures.h"
#include "system_file.h"
#include "color.h"
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

    ccnt=addClientFromFile(&chead,&ctail);
    vcnt=addVehicleFromFile(&vhead,&vtail);
    rcnt=addReservationFromFile(&rhead,&rtail);

    printf("\n");

     bg_color(6);
     fg_color(16);
    printf("    * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\
    *                                                     *\n\
    *          Welcome to the Car Rental System!          *\n\
    *                                                     *\n\
    * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
     fg_color(0);
     bg_color(0);
    printf("\n\n");

    Options(&vhead, &vtail, &chead, &ctail, &rhead, &rtail, &vcnt, &ccnt, &rcnt);

    return 0;
}