#ifndef create_h
#define create_h
void addVehicle(struct Vehicle **head)
{
    // Create a new vehicle node
    struct Vehicle *newVehicle = (struct Vehicle *)malloc(sizeof(struct Vehicle));

    if (newVehicle == NULL)
    {
        printf("Failed to allocate memory for the new vehicle.\n");
        return;
    }

    printf("Enter the plate number: ");
    scanf("%d", &newVehicle->plate_number);

    // Get other details for the new vehicle
    printf("Enter the year: ");
    scanf("%d", &(newVehicle->year));

    printf("Enter the model: ");
    scanf("%s", newVehicle->model);

    printf("Enter the fuel type: ");
    scanf("%s", newVehicle->fuel_type);

    printf("Enter the fuel consumption: ");
    scanf("%f", &(newVehicle->consumption));

    printf("Enter the number of seats: ");
    scanf("%d", &(newVehicle->seats));

    printf("Enter the price: ");
    scanf("%f", &(newVehicle->price));

    newVehicle->next = NULL;
    if (*head == NULL)
    {
        *head = newVehicle;
    }
    else
    {

        struct Vehicle *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newVehicle;
    }

    printf("New vehicle added successfully!\n");
}

// Hedije Jazaj
void addReservation(struct Reservation **head)
{
    // Create a new Reservation node
    struct Reservation *newReservation = (struct Reservation *)malloc(sizeof(struct Reservation));
    if (newReservation == NULL)
    {
        printf("Failed to allocate memory for the new reservation.\n");
        return;
    }
    printf("Enter the reservation ID");
    scanf("%d", &newReservation->ID);

    printf("Enter the reservation date");
    scanf("%s", newReservation->date);

    printf("Enter the Client ID");
    scanf("%D", &newReservation->client_ID);

    printf("Enter the days");
    scanf("%d", &newReservation->days);

    printf("Enter the price");
    scanf("%f", &newReservation->price);

    newReservation->next = NULL;
    if (*head == NULL)
    {
        *head = newReservation;
    }
    else
    {

        struct Reservation *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newReservation;
    }

    printf("New Reservation added successfully!\n");
}

#endif /* create.h */