#ifndef display_h
#define display_h
//Arlind Alliu
void displayAllVehicles(struct Vehicle* head) {
    if (head == NULL) {
        printf("No vehicles found.\n");
        return;
    }
    else
        printf("All Vehicles Information\n");
    
    int vehicleCount = 0;
    struct Vehicle* current = head;
    while (current != NULL) {
        vehicleCount++;
        printf("\nPlate Number: %d\n", current->plate_number);
        printf("Year: %d\n", current->year);
        printf("Brand: %s\n", current->brand);
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

void availableVehicles(struct Vehicle *head){
    printf("Not implemented.\n");
}

void availableVehiclesAfterXDays(struct Vehicle* head){
    printf("Not implemented.\n");
}

void searchVehiclePLATE(struct Vehicle* head){
    printf("Not implemented.\n");
}

void top3Vehicles(struct Vehicle* head){
    printf("Not implemented.\n");
}

void displayAllReservations(struct Reservation *head){
    printf("Not implemented.\n");
}

void client_rent_more_than_3_times(struct Client *head){
    printf("Not implemented.\n");
}

void displayAllClients(struct Client *head){
    printf("Not implemented.\n");
}

#endif /* display.h */