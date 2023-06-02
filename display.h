#ifndef display_h
#define display_h
// Arlind Alliu
void displayAllVehicles(struct Vehicle *head)
{
    if (head == NULL)
    {
        helper_fg_color(1); 
        printf("No vehicles found.\n");
        helper_fg_color(0);
        return;
    }
    else
    {
        helper_fg_color(15);
        printf("All Vehicles Information\n");
        helper_fg_color(0);
    }
    int vehicleCount = 0;
    struct Vehicle *current = head;
    while (current != NULL)
    {
        vehicleCount++;
        helper_fg_color(6);
        printf("\nPlate Number: %s\n", current->plate_number);
        printf("Year: %d\n", current->year);
        printf("Brand: %s\n", current->brand);
        printf("Model: %s\n", current->model);
        printf("Color: %s\n", current->color);
        printf("Fuel Type: %s\n", current->fuel_type);
        printf("Fuel Consumption: %.2f liters/100km\n", current->consumption);
        printf("Number of Seats: %d\n", current->seats);
        printf("Daily Price: %.2f\n", current->price);
        helper_fg_color(0);

        current = current->next;
    }
}

void availableVehicles(struct Vehicle *head)
{

    if (head == NULL)
    {
        helper_fg_color(1);
        printf("There are no vehicles available.\n\n");
        helper_fg_color(0);
        return;
    }

    helper_fg_color(15);
    printf("Available Vehicles are:\n");
    helper_fg_color(0);
    struct Vehicle *current = head;
    while (current != NULL)
    {
        if (current->availability == 'a')
        {
            helper_fg_color(6);
            printf("\nPlate Number: %s\n", current->plate_number);
            printf("Year: %d\n", current->year);
            printf("Brand: %s\n", current->brand);
            printf("Model: %s\n", current->model);
            printf("Color: %s\n", current->color);
            printf("Fuel Type: %s\n", current->fuel_type);
            printf("Fuel Consumption: %.2f liters/km\n", current->consumption);
            printf("Number of Seats: %d\n", current->seats);
            printf("Daily Price: %.2f\n", current->price);
            helper_fg_color(0);
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

void searchVehiclePLATE(struct Vehicle *head)
{
    
    char plate[20];
    printf("Enter the plate number: ");
    scanf("%s", plate);

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
    printf("No vehicle with plate number %s found.\n", plate);
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
    printf("Not implemented.\n");
}

void displayAllClients(struct Client *head)
{
    printf("Not implemented.\n");
}

#endif /* display.h */