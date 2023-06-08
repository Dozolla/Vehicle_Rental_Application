#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// header files for functions
#include "color.h"
#include "structures.h"
#include "system_file.h"
#include "create.h"
#include "delete.h"
#include "display.h"
#include "modify.h"
#include "sort.h"
#include "admin.h"

int main()
{
    struct Client *chead = NULL, *ctail = NULL;
    struct Vehicle *vhead = NULL, *vtail = NULL;
    struct Reservation *rhead = NULL, *rtail = NULL;
    int vcnt = 0, ccnt = 0, rcnt = 0;

    ccnt = addClientFromFile(&chead, &ctail);
    vcnt = addVehicleFromFile(&vhead, &vtail);
    rcnt = addReservationFromFile(&rhead, &rtail);

    printf("\n");

    bg_color(7);
    fg_color(13);
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*                                                     *\n");
    printf("*          Welcome to the Car Rental System!          *\n");
    printf("*                                                     *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * *");
    fg_color(0);
    bg_color(0);

    time_t raw;
    time(&raw);

    struct tm *time_ptr;
    time_ptr = localtime(&raw);

    char *current_date = malloc(20 * sizeof(char));
    // char current_time [20];
    strftime(current_date, 20, "%d/%m/%Y", time_ptr);
    // strftime(current_time, sizeof(current_time), "%H:%M:%S", time_ptr);
    fg_color(11);
    printf("\n\nToday's date is: %s", current_date);
    fg_color(0);
    printf("\n\n");

    // below is to check if the current date is the same as the end date of a reservation therefore make the vehicle is available if true
    struct Reservation *current = rhead;
    struct Vehicle *currentV = vhead;

    while (current != NULL)
    {
        struct tm date;
        sscanf(current->end_date, "%d/%d/%d", &date.tm_mday, &date.tm_mon, &date.tm_year);
        date.tm_mon -= 1;
        date.tm_year -= 1900;
        date.tm_hour = 12; // midday
        date.tm_min = 0;
        date.tm_sec = 0;
        time_t endDate = mktime(&date);
        time_t now = time(NULL);

        if (endDate <= now && strcmp(current->end_date, current_date) == 0)
        {
            while (currentV != NULL)
            {
                if (strcmp(current->vehicle_plate_number, currentV->plate_number) == 0)
                {
                    currentV->availability = 'a';
                }
                currentV = currentV->next;
            }
        }
        current = current->next;
    }
    Options(&vhead, &vtail, &chead, &ctail, &rhead, &rtail, &vcnt, &ccnt, &rcnt, current_date);

    return 0;
}