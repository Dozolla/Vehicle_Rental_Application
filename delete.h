#ifndef delete_h
#define delete_h
 //hedije jazaj
void deleteReservation(struct Reservation **head)
{
      struct Reservation *prev;
     if (*head==NULL){
         printf("There are no reservations to delete\n\n");
         return;
     }
     prev=*head;
     *head=prev->next;
     free(prev);
     printf("Reservation is deleted.\n\n");
}


void removeVehicle(struct Vehicle **head){
     struct Vehicle *prev;
     if (*head==NULL){
         printf("There are no vehicles to delete\n\n");
         return;
     }
     prev=*head;
     *head=prev->next;
     free(prev);
     printf("Vehicle is deleted.\n\n");
 }

#endif /* delete.h */