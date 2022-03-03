#include <stdio.h>
#include <string.h>

short get_operand(char mode) {
    short input;
    switch (mode) {
        case 'D': {
            printf("Enter decimal value: ");
            scanf("%d", &input);
            printf("%d\n", input);
            break;
        }
        case 'H': {
            printf("Enter hex value: ");
            scanf("%X", &input);
            printf("%X\n", input);
            break;
        }
        case 'O': {
            printf("Enter octal value: ");
            scanf("%o", &input);
            printf("%o\n", input);
            break;
        }
    }
    return input;
}

void print_acc(short acc, char mode) {

}

char print_menu(void) {
    short need_input = 1;
    char choice;
    while (need_input){
        char valid_input [6] = "OHCSQ";
        printf("Please select one of the following options:\n\n");
        printf("O  Octal Mode\n");
        printf("H  Hexidecimal Mode\n\n");
        printf("C  Clear Accumulator\n");
        printf("S  Set Accumulator\n\n");
        printf("Q  Quit\n\n");
        printf("Option: ");

        char input [10];
        scanf("%s", &input);
        printf("%s\n", input);
        choice = toupper(input[0]);

        if (strlen(input) > 1 || !strchr(valid_input, choice)) {
            printf("Invalid option: %s\n\n", input);
        } else {
            need_input = 0;
        }
    }
    return choice;
}

int main(void) {

}