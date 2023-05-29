#ifndef system_h
#define system_h
void displayClientToFile(struct Client **head, int cnt)
{
    FILE *outfile = NULL;
    outfile = fopen("clients_database.txt", "a");
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
        fprintf(outfile, "%d,%s,%s,%s,%s,%s", curr->ID, curr->name, curr->surname, curr->passport_ID, curr->State, curr->phoneNumber);
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
        fscanf(infile, "%d,%s,%s,%s,%s,%s\n", &curr->ID, curr->name, curr->surname, curr->passport_ID, curr->State, curr->phoneNumber);
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
    outfile = fopen("vehicles_database.txt", "a");
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
        fprintf(outfile, "%d,%d,%s,%s,%s,%f,%d,%f", curr->plate_number, curr->year, curr->model, curr->color, curr->fuel_type, curr->consumption, curr->seats, curr->price);
        printf("Added to file.\n");
        curr = curr->next;
    }

    fclose(outfile);
}

int addVehicleFormFile(struct Vehicle **head, struct Vehicle **tail)
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
        fscanf(infile, "%d,%d,%s,%s,%s,%f,%d,%f\n", &curr->plate_number, &curr->year, curr->model, curr->color, curr->fuel_type, &curr->consumption, &curr->seats, &curr->price);
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
    outfile = fopen("reservations_database.txt", "a");
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
        fprintf(outfile, "%d,%s,%d,%d,%f", curr->ID, curr->date, curr->client_ID, curr->days, curr->price);
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
        fscanf(infile, "%d,%s,%d,%d,%f\n", &curr->ID, curr->date, &curr->client_ID, &curr->days, &curr->price);
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

#endif /* system.h */