#ifndef create_h
#define create_h
// Arlind Alliu
void addVehicle(struct Vehicle **head)
{
    // Create a new vehicle node
    struct Vehicle *newVehicle = (struct Vehicle *)malloc(sizeof(struct Vehicle));

    if (newVehicle == NULL)
    {
        printf("Failed to allocate memory for the new vehicle.\n");
        return;
    }

    char temp;

    printf("Enter the plate number: ");
    scanf("%d", &newVehicle->plate_number);

    // Get other details for the new vehicle
    printf("Enter the year: ");
    scanf("%d", &(newVehicle->year));
    // As we enter an integer value and hit enter to read next value, compiler stores either enter or null into the string's first character and string input terminates. To avoid this, we use a temp statement to clear the buffer.
    scanf("%c", &temp); // temp statement to clear buffer

    printf("Enter the brand: ");
    scanf("%[^\n]", newVehicle->brand);

    printf("Enter the model: ");
    scanf("%s", newVehicle->model);

    printf("Enter the fuel type: ");
    scanf("%s", newVehicle->fuel_type);

    printf("Enter the fuel consumption: ");
    scanf("%f", &(newVehicle->consumption));

    printf("Enter the number of seats: ");
    scanf("%d", &(newVehicle->seats));

    printf("Enter the color: ");
    scanf("%s", newVehicle->color);

    printf("Enter the price: ");
    scanf("%f", &(newVehicle->price));

    newVehicle->availability = 'a';

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

void addNewClient(struct Client **head)
{
    struct Client *newClient = (struct Client *)malloc(sizeof(struct Client));
    if (newClient == NULL)
    {
        printf("Failed to allocate memory for the new client.\n");
        return;
    }
    printf("Enter the client ID: ");
    scanf("%d", &newClient->ID);
    printf("Enter the client name: ");
    scanf("%s", newClient->name);
    printf("Enter the client surname: ");
    scanf("%s", newClient->surname);
    printf("Enter the client passport ID: ");
    scanf("%s", newClient->passport_ID);
    printf("Enter the client state: ");
    scanf("%s", newClient->State);
    printf("Enter the client phone number: ");
    scanf("%s", newClient->phoneNumber);
    newClient->nr_of_reservations = 0;
    newClient->next = NULL;
    if (*head == NULL)
    {
        *head = newClient;
    }
    else
    {
        struct Client *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newClient;
    }
    printf("New client added successfully!\n");
}

// Hedije Jazaj
int addReservation(struct Reservation **head, struct Client **headClient, struct Client **tailClient, struct Vehicle **headVehicle)
{
    // Create a new Reservation node
    struct Reservation *newReservation = (struct Reservation *)malloc(sizeof(struct Reservation));
    if (newReservation == NULL)
    {
        printf("Failed to allocate memory for the new reservation.\n");
        return 0;
    }

    printf("Enter the Client ID: ");
    scanf("%d", &newReservation->client_ID);
    *tailClient = *headClient;
    while (*headClient != NULL && *tailClient != NULL)
    {
        if (newReservation->client_ID == (*tailClient)->ID)
        {
            printf("Enter the reservation ID: ");
            scanf("%d", &newReservation->ID);

            struct Vehicle *currV = (struct Vehicle *)malloc(sizeof(struct Vehicle));
            currV = *headVehicle;

            printf("Enter the vehicle plate number: ");
            scanf("%d", &newReservation->vehicle_plate_number);
            while (currV != NULL)
            {
                if (currV->plate_number == newReservation->vehicle_plate_number)
                {
                    if (currV->availability == 'a')
                    {
                        currV->availability = 'b';

                        printf("Enter the reservation date: ");
                        scanf("%s", newReservation->date);

                        printf("Enter how many days will the vehicle be rented: ");
                        scanf("%d", &newReservation->days);

                        newReservation->price = newReservation->days * currV->price;
                        printf("The price for the reservation is: %.2f", newReservation->price);

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

                        (*tailClient)->nr_of_reservations++;

                        printf("\nNew Reservation added successfully!\n");
                        return 1;
                    }
                    else
                    {
                        printf("Vehicle is not available.\n");
                        return 0;
                    }
                }
                currV = currV->next;
            }
            printf("Vehicle does not exist. Please add the vehicle first.\n");
            return 0;
        }
        *tailClient = (*tailClient)->next;
    }
    printf("Client does not exist. Please add the client first.\n");
    return 0;
}

#endif /* create.h */