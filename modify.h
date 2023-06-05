#ifndef modify_h
#define modify_h

// Arlind Alliu
void modifyVehicle(struct Vehicle **head)
{
    char temp1, plateNumber[10];
    scanf("%c", &temp1); // clear buffer
    printf("Enter the plate number of the vehicle you want to modify: ");
    scanf("%[^\n]", plateNumber);
    struct Vehicle *current = *head;
    while (current != NULL)
    {
        if (strcmp(current->plate_number, plateNumber) == 0)
        {
            printf("Current data of the vehicle");
            fg_color(6);
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
            fg_color(0);

            printf("Enter the new plate number: ");
            scanf("%c", &temp1); // clear buffer
            scanf("%[^\n]", current->plate_number);
            printf("Enter the new year: ");
            scanf("%d", &current->year);
            printf("Enter the new brand: ");
            scanf("%c", &temp1); // clear buffer
            scanf("%[^\n]", current->brand);
            printf("Enter the new model: ");
            scanf("%c", &temp1); // clear buffer
            scanf("%[^\n]", current->model);
            printf("Enter the new color: ");
            scanf("%c", &temp1); // clear buffer
            scanf("%[^\n]", current->color);
            printf("Enter the new fuel type: ");
            scanf("%s", current->fuel_type);
            printf("Enter the new fuel consumption: ");
            scanf("%f", &current->consumption);
            printf("Enter the new number of seats: ");
            scanf("%d", &current->seats);
            printf("Enter the new daily price: ");
            scanf("%f", &current->price);
            fg_color(2);
            printf("\nVehicle modified successfully.\n");
            fg_color(0);
            current->availability = 'a';
            return;
        }
        current = current->next;
    }
    fg_color(1);
    printf("Vehicle not found.\n");
    fg_color(0);
}
#endif /* modify.h */