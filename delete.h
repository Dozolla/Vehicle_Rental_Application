#ifndef delete_h
#define delete_h
// Hedije Jazaj

void deleteReservation(struct Reservation **head)
{
    int resID;
    struct Reservation *current = *head;
    struct Reservation *prev = NULL;

    if (*head == NULL)
    {
        fg_color(1);
        printf("There are no reservations to delete.\n\n");
        fg_color(0);
        return;
    }

    printf("Enter the Reservation ID of the Reservation you want to delete: ");

    scanf("%d", &resID);

    while (current != NULL && current->ID != resID)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        fg_color(1);
        printf("There is no reservation for this vehicle with Reservation ID %d \n\n", resID);
        fg_color(0);
        return;
    }

    if (prev == NULL)
    {
        *head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    free(current);
    fg_color(2);
    printf("Reservation with ID %d is deleted.\n\n", resID);
    fg_color(0);
}


// Arlind Alliu
void removeVehicle(struct Vehicle **head)
{
    char vehicleplate_number[10],temp;
    struct Vehicle *current = *head;
    struct Vehicle *prev = NULL;

    if (*head == NULL)
    {
        fg_color(1);
        printf("There are no vehicles to delete.\n\n");
        fg_color(0);
        return;
    }

    printf("Enter the vehicle Plate Number you want to delete: ");
    scanf("%c", &temp); // temp statement to clear buffer
    scanf("%[^\n]", vehicleplate_number);

    while (current != NULL && strcmp(current->plate_number, vehicleplate_number) != 0)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        fg_color(1);
        printf("Vehicle with Plate Number %s does not exist.\n\n", vehicleplate_number);
        fg_color(0);
        return;
    }

    if (prev == NULL)
    {
        *head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    free(current);
    fg_color(2);
    printf("Vehicle with Plate Number %s is deleted.\n\n", vehicleplate_number);
    fg_color(0);
}

#endif /* delete.h */