#ifndef create_h
#define create_h
// Arlind Alliu
void addVehicle(struct Vehicle **head)
{
    // Create a new vehicle node
    struct Vehicle *newVehicle = (struct Vehicle *)malloc(sizeof(struct Vehicle));

    if (newVehicle == NULL)
    {
        fg_color(1);
        printf("Failed to allocate memory for the new vehicle.\n");
        fg_color(0);
        return;
    }

    char temp;
    scanf("%c", &temp); // temp statement to clear buffer

    printf("Enter the plate number: ");
    scanf("%[^\n]", newVehicle->plate_number);

    // Get other details for the new vehicle

    printf("Enter the year: ");
    scanf("%d", &(newVehicle->year));
    while (1)
    {
        if (newVehicle->year < 1920 || newVehicle->year > 2023)
        {
            fg_color(1);
            printf("Invalid year inputed.\n");
            fg_color(0);
            printf("Enter the year: ");
            scanf("%d", &(newVehicle->year));
        }
        else
            break;
    }
    // As we enter an integer value and hit enter to read next value, compiler stores either enter or null into the string's first character and string input terminates. To avoid this, we use a temp statement to clear the buffer.
    scanf("%c", &temp); // temp statement to clear buffer

    printf("Enter the brand: ");
    scanf("%[^\n]", newVehicle->brand);

    scanf("%c", &temp); // again clear buffer

    printf("Enter the model: ");
    scanf("%[^\n]", newVehicle->model);

    printf("Enter the fuel type: ");
    scanf("%s", newVehicle->fuel_type);

    printf("Enter the fuel consumption: ");
    scanf("%f", &(newVehicle->consumption));

    printf("Enter the number of seats: ");
    scanf("%d", &(newVehicle->seats));

    scanf("%c", &temp); // temp statement to clear buffer

    printf("Enter the color: ");
    scanf("%[^\n]", newVehicle->color);

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

    fg_color(2);
    printf("New vehicle added successfully!\n");
    fg_color(0);
}

void addNewClient(struct Client **head)
{
    struct Client *newClient = (struct Client *)malloc(sizeof(struct Client));
    if (newClient == NULL)
    {
        fg_color(1);
        printf("Failed to allocate memory for the new client.\n");
        fg_color(0);
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
    fg_color(2);
    printf("New client added successfully!\n");
    fg_color(0);
}

// Hedije Jazaj
int addReservation(struct Reservation **head, struct Client **headClient, struct Client **tailClient, struct Vehicle **headVehicle)
{
    // Create a new Reservation node
    char temp;
    struct Reservation *newReservation = (struct Reservation *)malloc(sizeof(struct Reservation));
    if (newReservation == NULL)
    {
        fg_color(1);
        printf("Failed to allocate memory for the new reservation.\n");
        fg_color(0);
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
            scanf("%c", &temp); // temp statement to clear buffer
            printf("Enter the vehicle plate number: ");
            scanf("%[^\n]", newReservation->vehicle_plate_number);
            while (currV != NULL)
            {
                if (strcmp(currV->plate_number, newReservation->vehicle_plate_number) == 0)
                {
                    if (currV->availability != 'a')
                    {
                        fg_color(1);
                        printf("Vehicle is not available. Please choose another vehicle.\n");
                        fg_color(0);
                        return 0;
                    }
                    else
                    {
                        currV->availability = 'b';

                        printf("Enter the reservation date dd/mm/yyyy: ");
                        scanf("%s", newReservation->date);

                        printf("Enter how many days will the vehicle be rented: ");
                        scanf("%d", &newReservation->days);

                        newReservation->price = newReservation->days * currV->price;
                        printf("The price for the reservation is: $%.2f", newReservation->price);

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

                        fg_color(2);
                        printf("\nNew Reservation added successfully!\n");
                        fg_color(0);
                        return 1;
                    }
                }
                currV = currV->next;
            }
            fg_color(1);
            printf("Vehicle does not exist. Please add the vehicle first.\n");
            fg_color(0);
            return 0;
        }
        *tailClient = (*tailClient)->next;
    }
    fg_color(1);
    printf("Client does not exist. Please add the client first.\n");
    fg_color(0);
    return 0;
}

#endif /* create.h */