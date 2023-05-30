#ifndef system_h
#define system_h
void displayClientToFile(struct Client **head, int cnt)
{
    FILE *outfile = NULL;
    outfile = fopen("clients_database.txt", "w");
    if (!outfile)
    {
        printf("Cannot open File.\n");
        return;
    }
    if (cnt == 0)
    {
        printf("There are no clients at the moment.\n");
        return;
    }
    fprintf(outfile, "%d\n", cnt);
    struct Client *curr;
    curr = *head;

    while (curr != NULL)
    {
        fprintf(outfile, "%d,%s,%s,%s,%s,%s,%d\n", curr->ID, curr->name, curr->surname, curr->passport_ID, curr->State, curr->phoneNumber, curr->nr_of_reservations);
        printf("Added to file.\n");
        curr = curr->next;
    }

    fclose(outfile);
}

int addClientFromFile(struct Client **head, struct Client **tail)
{
    FILE *infile = NULL;
    infile = fopen("clients_database.txt", "r");
    if (!infile)
    {
        printf("Cannot open File.\n");
        return 0;
    }
    int cnt = 0;
    fscanf(infile, "%d\n", &cnt);
    if (cnt == 0)
    {
        printf("There are no clients at the moment.\n");
        return 0;
    }
    struct Client *curr;
    curr = *head;
    for (int i = 0; i < cnt; i++)
    {
        curr = (struct Client *)malloc(sizeof(struct Client));
        fscanf(infile, "%d,%19[^,],%19[^,],%19[^,],%29[^,],%19[^,],%d\n", &curr->ID, curr->name, curr->surname, curr->passport_ID, curr->State, curr->phoneNumber, &curr->nr_of_reservations);
        curr->next = NULL;
        if (*head == NULL)
        {
            *head = curr;
            *tail = curr;
        }
        else
        {
            (*tail)->next = curr;
            *tail = curr;
        }
    }
    fclose(infile);
    return cnt;
}

void displayVehicleToFile(struct Vehicle **head, int cnt)
{
    FILE *outfile = NULL;
    outfile = fopen("vehicles_database.txt", "w");
    if (!outfile)
    {
        printf("Cannot open File.\n");
        return;
    }
    if (cnt == 0)
    {
        printf("There are no vehicles at the moment.\n");
        return;
    }
    fprintf(outfile, "%d\n", cnt);
    struct Vehicle *curr;
    curr = *head;

    while (curr != NULL)
    {
        fprintf(outfile, "%d,%d,%s,%s,%s,%s,%f,%d,%f,%c\n", curr->plate_number, curr->year, curr->brand, curr->model, curr->color, curr->fuel_type, curr->consumption, curr->seats, curr->price, curr->availability);
        printf("Added to file.\n");
        curr = curr->next;
    }

    fclose(outfile);
}

int addVehicleFromFile(struct Vehicle **head, struct Vehicle **tail)
{
    FILE *infile = NULL;
    infile = fopen("vehicles_database.txt", "r");
    if (!infile)
    {
        printf("Cannot open File.\n");
        return 0;
    }
    int cnt = 0;
    fscanf(infile, "%d\n", &cnt);
    if (cnt == 0)
    {
        printf("There are no vehicles at the moment.\n");
        return 0;
    }
    struct Vehicle *curr;
    curr = *head;
    for (int i = 0; i < cnt; i++)
    {
        curr = (struct Vehicle *)malloc(sizeof(struct Vehicle));
        fscanf(infile, "%d,%d,%29[^,],%19[^,],%14[^,],%20[^,],%f,%d,%f,%c\n", &curr->plate_number, &curr->year, curr->brand, curr->model, curr->color, curr->fuel_type, &curr->consumption, &curr->seats, &curr->price, &curr->availability);
        curr->next = NULL;
        if (*head == NULL)
        {
            *head = curr;
            *tail = curr;
        }
        else
        {
            (*tail)->next = curr;
            *tail = curr;
        }
    }
    fclose(infile);
    return cnt;
}

void displayReservationToFile(struct Reservation **head, int cnt)
{
    FILE *outfile = NULL;
    outfile = fopen("reservations_database.txt", "w");
    if (!outfile)
    {
        printf("Cannot open File.\n");
        return;
    }
    if (cnt == 0)
    {
        printf("There are no reservations at the moment.\n");
        return;
    }
    fprintf(outfile, "%d\n", cnt);
    struct Reservation *curr;
    curr = *head;

    while (curr != NULL)
    {
        fprintf(outfile, "%d,%s,%d,%d,%f,%d\n", curr->ID, curr->date, curr->client_ID, curr->days, curr->price, curr->vehicle_plate_number);
        printf("Added to file.\n");
        curr = curr->next;
    }

    fclose(outfile);
}

int addReservationFromFile(struct Reservation **head, struct Reservation **tail)
{
    FILE *infile = NULL;
    infile = fopen("reservations_database.txt", "r");
    if (!infile)
    {
        printf("Cannot open File.\n");
        return 0;
    }
    int cnt = 0;
    fscanf(infile, "%d\n", &cnt);
    if (cnt == 0)
    {
        printf("There are no reservations at the moment.\n");
        return 0;
    }
    struct Reservation *curr;
    curr = *head;
    for (int i = 0; i < cnt; i++)
    {
        curr = (struct Reservation *)malloc(sizeof(struct Reservation));
        fscanf(infile, "%d,%10[^,],%d,%d,%f,%d\n", &curr->ID, curr->date, &curr->client_ID, &curr->days, &curr->price, &curr->vehicle_plate_number);
        curr->next = NULL;
        if (*head == NULL)
        {
            *head = curr;
            *tail = curr;
        }
        else
        {
            (*tail)->next = curr;
            *tail = curr;
        }
    }
    fclose(infile);
    return cnt;
}

void displaySpecialReservationToFile(struct Reservation **head){
    FILE *outfile = NULL;
    outfile = fopen("special_reservations_database.txt", "w");
    if (!outfile)
    {
        printf("Cannot open File.\n");
        return;
    }
    float price = 0;
    printf("Enter the cost:");
    scanf("%f", &price);
    struct Reservation *curr;
    curr = *head;

    while (curr != NULL)
    {
        if(curr->price > price){
        fprintf(outfile, "%d,%s,%d,%d,%f,%d\n", curr->ID, curr->date, curr->client_ID, curr->days, curr->price, curr->vehicle_plate_number);
        printf("Added to file.\n");
        }
        curr = curr->next;
    }

    fclose(outfile);    
}

#endif /* system.h */