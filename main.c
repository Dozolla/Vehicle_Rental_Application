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

    ccnt=addClientFromFile(&chead,&ctail);
    vcnt=addVehicleFromFile(&vhead,&vtail);
    rcnt=addReservationFromFile(&rhead,&rtail);

    printf("\n");

    helper_bg_color(Cyan);
    printf("Welcome to the Car Rental System!");
    helper_bg_color(Reset);
    printf("\n\n");

    Options(&vhead, &vtail, &chead, &ctail, &rhead, &rtail, &vcnt, &ccnt, &rcnt);

    return 0;
}