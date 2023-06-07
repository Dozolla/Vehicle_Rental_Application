#ifndef sort_h
#define sort_h

void sortVehiclesByPrice(struct Vehicle **head)
{
    if (head==NULL)
    {
        fg_color(1);
        printf("There are no vehicles to sort.\n");
        fg_color(0);
        return;
    }
    struct Vehicle *current = *head;
    struct Vehicle *index = NULL;
    float temp;
    char tempPlate[10];
    int tempYear;
    char tempBrand[20];
    char tempModel[20];
    char tempColor[20];
    char tempFuel[20];
    float tempConsumption;
    int tempSeats;
    char tempAvailability;
    while (current != NULL)
    {
        index = current->next;
        while (index != NULL)
        {
            if (current->price > index->price)
            {
                temp = current->price;
                current->price = index->price;
                index->price = temp;

                strcpy(tempPlate, current->plate_number);
                strcpy(current->plate_number, index->plate_number);
                strcpy(index->plate_number, tempPlate);

                tempYear = current->year;
                current->year = index->year;
                index->year = tempYear;

                strcpy(tempBrand, current->brand);
                strcpy(current->brand, index->brand);
                strcpy(index->brand, tempBrand);

                strcpy(tempModel, current->model);
                strcpy(current->model, index->model);
                strcpy(index->model, tempModel);

                strcpy(tempColor, current->color);
                strcpy(current->color, index->color);
                strcpy(index->color, tempColor);

                strcpy(tempFuel, current->fuel_type);
                strcpy(current->fuel_type, index->fuel_type);
                strcpy(index->fuel_type, tempFuel);

                tempConsumption = current->consumption;
                current->consumption = index->consumption;
                index->consumption = tempConsumption;

                tempSeats = current->seats;
                current->seats = index->seats;
                index->seats = tempSeats;

                tempAvailability = current->availability;
                current->availability = index->availability;
                index->availability = tempAvailability;
            }
            index = index->next;
        }
        current = current->next;
    }
}

#endif /* sort.h */