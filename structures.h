
#ifndef structures_h
#define structures_h

struct Vehicle{
    char plate_number[10];
    int year;
    char model[20];
    char brand[100];
    char color[15];
    char fuel_type[20];
    float consumption;
    int seats;
    float price;
    char availability;
    int nr_of_reservations;

    struct Vehicle *next;
};

struct Client{
    int ID;
    char name[20];
    char surname[20];
    char passport_ID[20];
    char State[30];
    char phoneNumber[20];
    int nr_of_reservations;

    struct Client *next;
};

struct Reservation{
    int ID;
    char date[11];
    int client_ID;
    int days;
    float price;
    char vehicle_plate_number[10];
    
    struct Reservation *next;
};


#endif /* structures.h */