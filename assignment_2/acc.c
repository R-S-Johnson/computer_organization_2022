#include <stdio.h>
#include <string.h>

short get_operand(char mode) {
    short input;
    switch (mode) {
        case 'D': {
            printf("Enter decimal value: ");
            scanf("%hd", &input);
            printf("%hd\n", input);
            break;
        }
        case 'H': {
            printf("Enter hex value: ");
            scanf("%hX", &input);
            printf("%hX\n", input);
            break;
        }
        case 'O': {
            printf("Enter octal value: ");
            scanf("%ho", &input);
            printf("%ho\n", input);
            break;
        }
    }
    return input;
}

void print_acc(short acc, char mode) {

    printf("****************************************\n");
    switch (mode) {
        case 'D': printf("* Accumulator:         Input Mode: Dec *\n"); break;
        case 'H': printf("* Accumulator:         Input Mode: Hex *\n"); break;
        case 'O': printf("* Accumulator:         Input Mode: Oct *\n"); break;
    }
    printf("*   Hex     :  %04hX                    *\n", acc);
    printf("*   Octal   :  %06ho                  *\n", acc);
    printf("*   Decimal :  %-10hd              *\n", acc);
    printf("****************************************\n\n");
}

char print_menu(void) {
    short need_input = 1;
    char choice;
    while (need_input){
        char valid_input [6] = "OHCSQ";
        printf("Please select one of the following options:\n\n");
        printf("O  Octal Mode\n");
        printf("H  Hexadecimal Mode\n");
        printf("D  Decimal Mode\n\n");
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
    return toupper(choice);
}

int main(void) {
    short run = 1;
    short acc_value = 0;
    char mode = 'D';

    while (run) {
        print_acc(acc_value, mode);
        char menu_choice = print_menu();

        switch (menu_choice) {
            case 'Q': run = 0; break;
            case 'S': acc_value = get_operand(mode); break;
            case 'C': acc_value = 0; mode = 'D'; break;
            case 'H': mode = 'H'; printf("Mode is Hexadecimal\n\n"); break;
            case 'O': mode = 'O'; printf("Mode is Octal\n\n"); break;
            case 'D': mode = 'D'; printf("Mode is Decimal\n\n"); break;
        }
    }
}