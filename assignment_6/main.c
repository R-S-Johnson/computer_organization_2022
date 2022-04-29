#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "contact.h"
#include "contact_list.h"

void process_file(char * filename) {

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

}

void print_tab(char mode) {

}

void process_state_contacts(char mode) {

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