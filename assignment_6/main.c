#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "contact.h"
#include "contact_list.h"

void process_file(char * filename) {
    FILE *fp;
    fp = fopen(filename, "r");

    fscanf(fp,"%*s\n");

    CONTACT_T * input;

    while (fscanf(fp, "[^;];[^;];[^;];[^;];[^;];[^;];[^;];[^;];[^;];[^;];[^;];%s ", input->first_name, input->last_name, input->co_name,
    input->addr, input->city, input->county, input->state, input->zip, input->phone1, input->phone2, input->email, input->web) == 12) {
        CONTACT_T * newContact = create_contact(input);
        insert_contact(newContact);
    }
}

char print_menu(void) {
    short need_input = 1;
    char choice;
    while (need_input) {
        char valid_input [6] = "CITSQ";
        printf("Please select one of the following:\n\n");
        printf(" c  Change output format\n");
        printf(" i  Search for individual\n");
        printf(" t  Print tab\n");
        printf(" s  Look up by state\n");
        printf(" q  Quit\n\n");
        printf("Option: ");

        char input [10];
        scanf("%s", &input);
        printf("%s\n", input);
        upper(input);
        choice = input[0];

        if (strlen(input) > 1 || !strchr(valid_input, choice)) {
            printf("\nInvalid option: %s\n\n", input);
        } else {
            need_input = 0;
        }
    }
    return choice;
}

char print_format_menu(void){
    char choice [10];
    printf("\nPlease select one of the following:\n\n");
    printf(" c  Condensed output information\n");
    printf(" f  Full output information\n\n");
    printf("Option: ");

    scanf("%s", &choice);
    printf("%s\n", choice);
    upper(choice);
    
    return choice[0];
}

void find_individual(char mode) {
    char * firstName [15];
    char * lastName [15];
    printf("Please enter last name: ");
    scanf("%s", &lastName);
    printf("%s\n", lastName);
    
    printf("Please enter first name: ");
    scanf("%s", &firstName);
    printf("%s\n", firstName);

    CONTACT_T * foundContact = find_contact(lastName, firstName);
    print_contact(foundContact, mode);
}

void print_tab(char mode) {
    char * tabLetter;
    printf("Please enter last name tab letter: ");
    scanf("%s", &tabLetter);
    printf("%s\n", tabLetter);
    upper(tabLetter);

    CONTACT_T * returnedContact = get_next_contact(tabLetter[0]);
    if (returnedContact == NULL) {
        printf("Contact was not found!");
    }
    else {
        while (returnedContact != NULL) {
            print_contact(returnedContact, mode);
            returnedContact = get_next_contact(tabLetter[0]);
        }
    }
}

void process_state_contacts(char mode) {
    char * stateChoice;
    printf("Please enter two-letter state abbreviation: ");
    scanf("%s", &stateChoice);
    printf("%s\n", stateChoice);
    upper(stateChoice);
    print_state_contacts(stateChoice, mode);
}

int main(int argc, char const *argv[])
{
    char mode = 'C';
    if (argc != 2) {
        exit(EXIT_FAILURE);
    }
    
    init_contact_list();
    process_file(argv[1]);
    print_contact_list(mode);

    int stillgo = 1;
    do {
        char option = print_menu();
        switch (option) {
            case 'Q': stillgo = 0;
            case 'O': mode = print_format_menu();
            case 'I': find_individual(mode);
            case 'T': print_tab(mode);
            case 'S': process_state_contacts(mode);
        }
    } while (stillgo);
    
    free_contact_list();
}