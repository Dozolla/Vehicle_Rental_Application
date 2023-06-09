#ifndef display_h
#define display_h
// Arlind Alliu
void displayAllVehicles(struct Vehicle *head)
{
    if (head == NULL)
    {
        fg_color(1);
        printf("No vehicles found.\n");
        fg_color(0);
        return;
    }
    else
    {
        fg_color(15);
        printf("All Vehicles Information\n");
        fg_color(0);
    }
    struct Vehicle *current = head;
    while (current != NULL)
    {
        fg_color(6);
        printf("\nPlate Number: %s\n", current->plate_number);
        printf("Year: %d\n", current->year);
        printf("Brand: %s\n", current->brand);
        printf("Model: %s\n", current->model);
        printf("Color: %s\n", current->color);
        printf("Fuel Type: %s\n", current->fuel_type);
        printf("Fuel Consumption: %.2f liters/100km\n", current->consumption);
        printf("Number of Seats: %d\n", current->seats);
        printf("Daily Price: %.2f\n", current->price);
        fg_color(0);

        current = current->next;
    }
}
// Arlind Alliu
void availableVehicles(struct Vehicle *head)
{

    if (head == NULL)
    {
        fg_color(1);
        printf("There are no vehicles in the database.\n\n");
        fg_color(0);
        return;
    }

    fg_color(15);
    printf("Available Vehicles are:\n");
    fg_color(0);
    struct Vehicle *current = head;
    int vehicle_count = 0;
    while (current != NULL)
    {
        if (current->availability == 'a')
        {
            fg_color(6);
            printf("\nPlate Number: %s\n", current->plate_number);
            printf("Year: %d\n", current->year);
            printf("Brand: %s\n", current->brand);
            printf("Model: %s\n", current->model);
            printf("Color: %s\n", current->color);
            printf("Fuel Type: %s\n", current->fuel_type);
            printf("Fuel Consumption: %.2f liters/km\n", current->consumption);
            printf("Number of Seats: %d\n", current->seats);
            printf("Daily Price: %.2f\n", current->price);
            fg_color(0);
            printf("\n");
            vehicle_count++;
        }
        current = current->next;
    }
    if (vehicle_count == 0)
    {
        printf("There are no available vehicles at the moment.\n");
    }
    printf("\n");
}

void availableVehiclesAfterXDays(struct Vehicle **head, struct Reservation **headR)
{
    int x, day, month, year;
    if (head == NULL)
    {
        fg_color(1);
        printf("There are no vehicles in the database.\n\n");
        fg_color(0);
        return;
    }

    struct Vehicle *current = *head;
    struct Reservation *currentR = *headR;

    int vehicle_count = 0;
    while (current != NULL)
    {
        if (current->availability == 'b')
        {
            currentR = *headR;
            while (currentR != NULL)
            {
                if (strcmp(currentR->vehicle_plate_number, current->plate_number) == 0)
                {
                    struct tm date;
                    sscanf(currentR->end_date, "%d/%d/%d", &date.tm_mday, &date.tm_mon, &date.tm_year);
                    date.tm_mon -= 1;
                    date.tm_year -= 1900;
                    date.tm_hour = 12; // midday
                    date.tm_min = 0;
                    date.tm_sec = 0;
                    time_t endDate = mktime(&date);
                    if (endDate == -1)
                    {
                        fg_color(1);
                        printf("Error in date format.\n");
                        fg_color(0);
                        return;
                    }
                    time_t now = time(NULL);
                    time_t xdayslater = endDate - now;

                    if (endDate > now)
                    {
                        x = xdayslater / (60 * 60 * 24);

                        fg_color(6);
                        printf("\nPlate Number: %s\n", current->plate_number);
                        printf("Year: %d\n", current->year);
                        printf("Brand: %s\n", current->brand);
                        printf("Model: %s\n", current->model);
                        printf("Color: %s\n", current->color);
                        printf("Fuel Type: %s\n", current->fuel_type);
                        printf("Fuel Consumption: %.2f liters/km\n", current->consumption);
                        printf("Number of Seats: %d\n", current->seats);
                        printf("Daily Price: %.2f\n", current->price);
                        fg_color(0);

                        fg_color(15);
                        if (x == 0)
                            printf("This vehicle will be available in less than a day.\n\n");
                        else
                            printf("This vehicle is available after %d days.\n\n", x);
                        fg_color(0);
                        vehicle_count++;
                    }
                }
                currentR = currentR->next;
            }
        }
        current = current->next;
    }
    if (vehicle_count == 0)
    {
        printf("All vehicles are available.\n");
    }
}

// Arlind Alliu
void searchVehiclePLATE(struct Vehicle *head)
{
    char temp, plate[20];
    scanf("%c", &temp); // to clear the buffer
    printf("Enter the plate number: ");
    scanf("%[^\n]", plate);

    struct Vehicle *current = head;
    while (current != NULL)
    {
        if (strcmp(current->plate_number, plate) == 0)
        {
            printf("\nPlate Number: %s\n", current->plate_number);
            printf("Year: %d\n", current->year);
            printf("Model: %s\n", current->model);
            printf("Brand: %s\n", current->brand);
            printf("Color: %s\n", current->color);
            printf("Fuel Type: %s\n", current->fuel_type);
            printf("Fuel Consumption: %.2f liters/km\n", current->consumption);
            printf("Number of Seats: %d\n", current->seats);
            printf("Daily Price: %.2f\n", current->price);
            printf("\n");
            return;
        }
        current = current->next;
    }
    fg_color(1);
    printf("No vehicle with plate number %s found.\n", plate);
    fg_color(0);
}

// Hedije Jazaj
void top3Vehicles(struct Vehicle *head)
{
    struct Vehicle *number_of_res[3] = {NULL, NULL, NULL};
    struct Vehicle *current = head;

    if (current == NULL)
    {
        fg_color(1);
        printf("No vehicles found.\n");
        fg_color(0);
        return;
    }

    while (current != NULL)
    {
        for (int i = 0; i < 3; i++)
        {
            if (number_of_res[i] == NULL || current->nr_of_reservations > number_of_res[i]->nr_of_reservations)
            {
                for (int j = 2; j > i; j--)
                {
                    number_of_res[j] = number_of_res[j - 1];
                }
                number_of_res[i] = current;
                break;
            }
        }
        current = current->next;
    }
    fg_color(16);
    printf("Top Three Reserved Vehicles:\n");
    fg_color(0);
    for (int i = 0; i < 3; i++)
    {
        if (number_of_res[i] != NULL)
        {
            fg_color(6);
            printf("\nPlate Number: %s\n", number_of_res[i]->plate_number);
            printf("Year: %d\n", number_of_res[i]->year);
            printf("Brand: %s\n", number_of_res[i]->brand);
            printf("Model: %s\n", number_of_res[i]->model);
            printf("Color: %s\n", number_of_res[i]->color);
            printf("Fuel Type: %s\n", number_of_res[i]->fuel_type);
            printf("Fuel Consumption: %.2f liters/km\n", number_of_res[i]->consumption);
            printf("Number of Seats: %d\n", number_of_res[i]->seats);
            printf("Daily Price: %.2f\n", number_of_res[i]->price);
            printf("\n");
            fg_color(0);
        }
    }
}

// Hedije Jazaj
void displayAllReservations(struct Reservation *head)
{
    if (head == NULL)
    {
        fg_color(1);
        printf("No reservations found.\n");
        fg_color(0);
        return;
    }
    else
    {
        fg_color(15);
        printf("All Reservation Information\n");
        fg_color(0);
    }
    int reservationCount = 0;
    struct Reservation *current = head;
    while (current != NULL)
    {
        reservationCount++;
        fg_color(6);
        printf("\nReservation ID: %d\n", current->ID);
        printf("Date %s\n", current->date);
        printf("Client ID: %d\n", current->client_ID);
        printf("Number of Days: %d\n", current->days);
        printf("End Date: %s\n", current->end_date);
        printf("Price: %.2f\n", current->price);
        printf("Vehicle Plate Number: %s\n", current->vehicle_plate_number);
        fg_color(0);

        current = current->next;
    }
}

// Arlind Alliu
void client_rent_more_than_3_times(struct Client *head)
{
    int cnt = 0;
    fg_color(16);
    printf("Clients with more than 3 rentals are: \n");
    fg_color(0);
    struct Client *current = head;

    while (current != NULL)
    {
        if (current->nr_of_reservations > 3)
        {
            fg_color(16);
            printf("\nName: %s\n", current->name);
            printf("Surname: %s\n", current->surname);
            printf("Client ID: %d\n", current->ID);
            fg_color(0);
            cnt++;
        }
        current = current->next;
    }
    if (cnt == 0)
    {
        fg_color(1);
        printf("No client with more than 3 rentals found.\n");
        fg_color(0);
    }
}

// Hedije Jazaj
void displayAllClients(struct Client *head)
{
    if (head == NULL)
    {
        fg_color(1);
        printf("No clients found.\n");
        fg_color(0);
        return;
    }
    else
    {
        fg_color(15);
        printf("All Clients Information\n");
        fg_color(0);
    }
    int clientCount = 0;
    struct Client *current = head;
    while (current != NULL)
    {
        clientCount++;
        fg_color(6);
        printf("\nClient ID: %d\n", current->ID);
        printf("Client name: %s\n", current->name);
        printf("Client surname: %s\n", current->surname);
        printf("Passport ID: %s\n", current->passport_ID);
        printf("State: %s\n", current->State);
        printf("Phone number: %s\n", current->phoneNumber);
        printf("Number of reservations: %d\n", current->nr_of_reservations);
        fg_color(0);

        current = current->next;
    }
}

#endif /* display.h */