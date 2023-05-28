
#ifndef structures_h
#define structures_h

struct Vehicle{
    int plate_number;
    int year;
    char model[20];
    char color[10];
    char fuel_type[20];
    float consumption;
    int seats;
    float price;

    struct Vehicle *next;
};

struct Client{
    int ID;
    char name[20];
    char surname[20];
    char passport_ID[20];
    char State[30];
    char phoneNumber[20];

    struct Client *next;
};

struct Reservation{
    int ID;
    char date[10];
    int client_ID;
    int days;
    float price;
    
    struct Reservation *next;
};


#endif /* structures.h */