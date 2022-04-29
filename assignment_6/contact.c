#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

CONTACT_T * create_contact(CONTACT_T * contact) {
    CONTACT_T * toReturn = (CONTACT_T *) malloc(268);

    strcpy(toReturn->first_name, contact->first_name);
    strcpy(toReturn->last_name, contact->last_name);
    strcpy(toReturn->co_name, contact->co_name);
    strcpy(toReturn->addr, contact->addr);
    strcpy(toReturn->city, contact->city);
    strcpy(toReturn->county, contact->county);
    strcpy(toReturn->state, contact->state);
    strcpy(toReturn->zip, contact->zip);
    strcpy(toReturn->phone1, contact->phone1);
    strcpy(toReturn->phone2, contact->phone2);
    strcpy(toReturn->email, contact->email);
    strcpy(toReturn->web, contact->web);

    toReturn->next = NULL;

    return toReturn;
}

void print_contact(CONTACT_T * contact, char mode) {
    if (mode == 'C') {
        printf("%18s", contact->last_name);
        printf("%18s", contact->first_name);
        printf("%15s", contact->phone1);
        printf("%s\n", contact->email);
    }
    else {
        printf("Name:    %s %s\n", contact->first_name, contact->last_name);
        printf("Address: %s\n", contact->addr);
        printf("Phone:   %s (primary)  %s\n", contact->phone1, contact->phone2);
        printf("email:   %s\n", contact->email);
        printf("web:     %s\n", contact->web);
    }
}