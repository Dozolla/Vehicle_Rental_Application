#ifndef delete_h
#define delete_h

void deleteReservation(struct Reservation **head)
{
    printf("Not implemented.\n");
}


void removeVehicle(struct Vehicle **head) {
    int vehicleplate_number;
    struct Vehicle *current = *head;
    struct Vehicle *prev = NULL;

    if (*head == NULL) {
        printf("There are no vehicles to delete.\n\n");
        return;
    }

    printf("Enter the vehicle Plate Number you want to delete: ");
    scanf("%d", &vehicleplate_number);

    
    while (current != NULL && current->plate_number != vehicleplate_number) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Vehicle with Plate Number %d does not exist.\n\n", vehicleplate_number);
        return;
    }

     if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Vehicle with Plate Number %d is deleted.\n\n", vehicleplate_number);
}


#endif /* delete.h */