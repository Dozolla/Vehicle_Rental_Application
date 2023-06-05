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
    int vehicleCount = 0;
    struct Vehicle *current = head;
    while (current != NULL)
    {
        vehicleCount++;
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
        printf("There are no vehicles available.\n\n");
        fg_color(0);
        return;
    }

    fg_color(15);
    printf("Available Vehicles are:\n");
    fg_color(0);
    struct Vehicle *current = head;
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
        }
        current = current->next;
    }

    printf("\n");
}

void availableVehiclesAfterXDays(struct Vehicle *head)
{
    printf("Not implemented.\n");
}

// Arlind Alliu
void searchVehiclePLATE(struct Vehicle *head)
{
    char temp, plate[20];
    scanf("%c", &temp);
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

void top3Vehicles(struct Vehicle *head)
{
    printf("Not implemented.\n");
}

void displayAllReservations(struct Reservation *head)
{
    printf("Not implemented.\n");
}

void client_rent_more_than_3_times(struct Client *head)
{
    int cnt = 0;
    printf("Clients with more than 3 rentals are: \n");
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

void displayAllClients(struct Client *head)
{
    printf("Not implemented.\n");
}

#endif /* display.h */