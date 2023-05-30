#ifndef delete_h
#define delete_h

void deleteReservation(struct Reservation **head)
{
    printf("Not implemented.\n");
}


void removeVehicle(struct Vehicle **head,int *cnt){
     struct Vehicle *prev;
     if (*head==NULL){
         printf("There are no vehicles to delete\n\n");
         return;
     }
     prev=*head;
     *head=prev->next;
     free(prev);
     printf("Vehicle is deleted.\n\n");
     int i;
     i=*cnt;
     *cnt=i-1
 }

#endif /* delete.h */