#ifndef admin_h
#define admin_h
void Options(struct Vehicle **head, struct Vehicle **tail, struct Client **headC, struct Client **tailC, struct Reservation **headR, struct Reservation **tailR, int *cntV, int *cntC, int *cntR)
{
    int a;
    while (1)
    {
        printf("\n1. Display all vehicle information.\
\n2. Display available vehicles currently.\
\n3. Display vehicles that will be available after x days.\
\n4. Create a new reservation.\
\n5. Add a new vehicle.\
\n6. Search for a vehicle using the license plate number.\
\n7. Sort and display all vehicles according to their daily rental price.\
\n8. Display the top 3 most reserved vehicles.\
\n9. Display all reservations.\
\n10. Remove a vehicle. (delete)\
\n11. Cancel a reservation. (delete)\
\n12. Display the name, surname and Client ID of all clients who have rented a vehicle (not necessarily the same) more than 3 times.\
\n13. Save all reservations with a total cost exceeding x to a new file.\
\n14. Modify information for a vehicle using its plate number.\
\n15. Add new client.\
\n16. Show all clients.\
\n0. Exit the program.\n");

        printf("Please choose one of the following options:\n");
        int option;
        scanf("%d", &option);
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
            a=addReservation(headR, headC, tailC, head);
            if (a == 1){
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
            //what do we do with this?
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
            printf("Exiting the program...\n");
            displayReservationToFile(headR, *cntR);
            displayVehicleToFile(head, *cntV);
            displayClientToFile(headC, *cntC);
            return;
        default:
            printf("Invalid option! Please try again!\n");
            break;
        }
    }
}
#endif /* admin.h */