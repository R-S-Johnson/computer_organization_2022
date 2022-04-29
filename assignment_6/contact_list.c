#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "contact.h"
#include "contact_list.h"
#include "utils.h"


static CONTACT_T * bucket[26];


void init_contact_list(void) {
    for (int i = 0; i < 26; i++) {
        bucket[i] = NULL;
    }
}

void insert_contact(CONTACT_T * contact) {
    int bucketIndex = contact->last_name[0] - 'A';

    if (bucket[bucketIndex] == NULL) {
        // goes there
        bucket[bucketIndex] = contact;
    }
    else if (strcmp(contact->last_name, bucket[bucketIndex]->last_name) < 0) {
        // first position
        contact->next = bucket[bucketIndex];
        bucket[bucketIndex] = contact;
    }
    else {
        CONTACT_T * prev = bucket[bucketIndex];
        CONTACT_T * curr = prev->next;

        while (strcmp(contact->last_name, curr->last_name) > 0) {
            prev = prev->next;
            curr = curr->next;

            if (curr == NULL) {
                // put at end
                prev->next = contact;
                return;
            }
        }
        // put in position
        contact->next = curr;
        prev->next = contact;
    }
}

void print_contact_list(char mode) {
    int empty = 1;
    for (int i = 0; i < 26; i++) {
        if (bucket[i] != NULL) {
            empty = 0;
            CONTACT_T * curr = bucket[i];
            do {
                print_contact(curr, mode);
                curr = curr->next;
            } while (curr != NULL);
        }
    }
    if (empty) {
        printf("Bucket list is empty!");
    }
}

CONTACT_T * find_contact(NAME_T last_name, NAME_T first_name) {
    int bucketIndex = last_name[0] - 'A';
    CONTACT_T * curr = bucket[bucketIndex];
    while (curr != NULL) {
        NAME_T compLastName;
        NAME_T compFirstName;

        NAME_T compBinLastName;
        NAME_T compBinFirstName;

        strcpy(compLastName, last_name);
        strcpy(compFirstName, first_name);
        strcpy(compBinLastName, curr->last_name);
        strcpy(compBinFirstName, curr->first_name);

        upper(compLastName);
        upper(compFirstName);
        upper(compBinFirstName);
        upper(compBinLastName);

        if (strcmp(compLastName, compBinLastName) == 0 && strcmp(compFirstName, compBinFirstName) == 0) {
            return curr;
        }
        curr = curr->next;
    }
}

CONTACT_T * get_next_contact(char letter) {
    static CONTACT_T * curr = NULL;

    if (curr == NULL) {
        curr = bucket[letter - 'A'];
        return curr;
    }
    else {
        curr = curr->next;
        return curr;
    }
}

void print_state_contacts(char state[], char mode) {
    int empty = 1;

    for (int i = 0; i < 26; i++) {
        CONTACT_T * curr;
        curr = bucket[i];

        while (curr != NULL) {
            if (strcmp(curr->state, state) == 0) {
                empty = 0;
                print_contact(curr, mode);
            }
        }
    }
    if (empty) {
        printf("No matching contacts!");
    }
}

void free_contact_list(void) {
    for (int i = 0; i < 26; i++) {
        if (bucket[i] != NULL) {
            CONTACT_T * curr;
            curr = bucket[i];
            if (curr->next == NULL) {
                free(curr);
                bucket[i] = NULL;
            }
            else {
                CONTACT_T * next;
                next = curr->next;

                while (next != NULL) {
                    free(curr);
                    curr = next;
                    next = next->next;
                }
                free(curr);
                bucket[i] = NULL;
            }
        }
    }
}