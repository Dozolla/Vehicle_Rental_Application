#ifndef admin_h
#define admin_h

#include <unistd.h>

void Options(struct Vehicle **head, struct Vehicle **tail, struct Client **headC, struct Client **tailC, struct Reservation **headR, struct Reservation **tailR, int *cntV, int *cntC, int *cntR, char *current_date)
{
    int a;
    while (1)
    {
        fg_color(15);
        printf("\n   1. Display all vehicle information.\
\n   2. Display available vehicles currently.\
\n   3. Display vehicles that will be available after x days.\
\n   4. Create a new reservation.\
\n   5. Add a new vehicle.\
\n   6. Search for a vehicle using the license plate number.\
\n   7. Sort and display all vehicles according to their daily rental price.\
\n   8. Display the top 3 most reserved vehicles.\
\n   9. Display all reservations.\
\n   10. Remove a vehicle. (delete)\
\n   11. Cancel a reservation. (delete)\
\n   12. Display the name, surname and Client ID of all clients who have rented a vehicle (not necessarily the same) more than 3 times.\
\n   13. Save all reservations with a total cost exceeding x to a new file.\
\n   14. Modify information for a vehicle using its plate number.\
\n   15. Add new client.\
\n   16. Show all clients.\
\n   0. Exit the program.\n");
        fg_color(0);
        fg_color(12);
        printf("Please choose one of the above options:\n");
        int option;
        printf("~ ");
        scanf("%d", &option);
        fg_color(0);
        switch (option)
        {
        case 1:
            displayAllVehicles(*head);
            break;
        case 2:
            availableVehicles(*head);
            break;
        case 3:
            availableVehiclesAfterXDays(*head);
            break;
        case 4:
            a = addReservation(headR, headC, tailC, head, current_date);
            if (a == 1)
            {
                *cntR = *cntR + 1;
            }
            break;
        case 5:
            addVehicle(head);
            *cntV = *cntV + 1;
            break;
        case 6:
            searchVehiclePLATE(*head);
            break;
        case 7:
            sortVehiclesByPrice(head);
            break;
        case 8:
            top3Vehicles(*head);
            break;
        case 9:
            displayAllReservations(*headR);
            break;
        case 10:
            removeVehicle(head);
            *cntV = *cntV - 1;
            break;
        case 11:
            deleteReservation(headR);
            //*cntR = *cntR - 1;
            break;
        case 12:
            client_rent_more_than_3_times(*headC);
            break;
        case 13:
            displaySpecialReservationToFile(headR);
            break;
        case 14:
            modifyVehicle(head);
            break;
        case 15:
            addNewClient(headC);
            *cntC = *cntC + 1;
            break;
        case 16:
            displayAllClients(*headC);
        case -1:
            break;
        case 0:
            fg_color(15); 
            printf("Exiting the program...\n");
            printf("Saving data to files...\n");
            for (int i = 0; i < 25; i++)
            {
                fg_color(2);
                printf("▓");
                fg_color(0);
                fflush(stdout);
                usleep(45000); // delay in microseconds
            }
            fg_color(2);
            printf(" 100%%\n");
            fg_color(0);
            displayReservationToFile(headR, *cntR);
            displayVehicleToFile(head, *cntV);
            displayClientToFile(headC, *cntC);
            fg_color(11);
            printf("Data saved successfully!\nFinished!\n");
            fg_color(0);
            return;
        default:
            fg_color(1);
            printf("Invalid option! Please try again!\n");
            fg_color(0);
            break;
        }
    }
}
#endif /* admin.h */