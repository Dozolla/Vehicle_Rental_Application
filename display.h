#ifndef display_h
#define display_h

void displayAllVehicles(struct Vehicle* head) {
    printf("All Vehicles Information\n");
    if (head == NULL) {
        printf("No vehicles found.\n");
        return;
    }
    
    int vehicleCount = 0;
    struct Vehicle* current = head;
    while (current != NULL) {
        vehicleCount++;
        printf("Plate Number: %d\n", current->plate_number);
        printf("Year: %d\n", current->year);
        printf("Model: %s\n", current->model);
        printf("Color: %s\n", current->color);
        printf("Fuel Type: %s\n", current->fuel_type);
        printf("Fuel Consumption: %.2f liters/km\n", current->consumption);
        printf("Number of Seats: %d\n", current->seats);
        printf("Daily Price: %.2f\n", current->price);
        printf("\n");
        
        current = current->next;
    }
}


#endif /* display.h */