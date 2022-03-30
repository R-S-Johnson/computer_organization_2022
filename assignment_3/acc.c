#include <stdio.h>
#include <string.h>

short get_operand(char mode) {
    short input;
    switch (mode) {
        case 'D': {
            printf("Enter decimal value: ");
            scanf("%hd", &input);
            printf("%hd\n\n", input);
            break;
        }
        case 'H': {
            printf("Enter hex value: ");
            scanf("%hX", &input);
            printf("%hX\n\n", input);
            break;
        }
        case 'O': {
            printf("Enter octal value: ");
            scanf("%ho", &input);
            printf("%ho\n\n", input);
            break;
        }
    }
    return input;
}

void print_acc(short acc, char mode) {

    printf("****************************************\n");
    switch (mode) {
        case 'B': printf("* Accumulator:         Input Mode: Bin *\n"); break;
        case 'D': printf("* Accumulator:         Input Mode: Dec *\n"); break;
        case 'H': printf("* Accumulator:         Input Mode: Hex *\n"); break;
        case 'O': printf("* Accumulator:         Input Mode: Oct *\n"); break;
    }
    printf("*   Binary  :  0000 0000 0000 0000     *\n", acc);
    printf("*   Hex     :  %04hX                    *\n", acc);
    printf("*   Octal   :  %06ho                  *\n", acc);
    printf("*   Decimal :  %-10hd              *\n", acc);
    printf("****************************************\n\n");
}

char print_menu(void) {
    short need_input = 1;
    char choice;
    while (need_input){
        char valid_input [7] = "OHDCSQ&|^~><+-N";
        printf("Please select one of the following options:\n\n");
        printf("B  Binary Mode             &  AND with Accumulator           +  Add to Accumulator\n");
        printf("O  Octal Mode              |  OR  with Accumulator           -  Subtract from Accumulator\n");
        printf("H  Hexadecimal Mode        ^  XOR with Accumulator           N  Negate Accumulator\n");
        printf("D  Decimal Mode            ~  Complement Accumulator\n\n");
        printf("C  Clear Accumulator       <  Shift Accumulator Left\n");
        printf("S  Set Accumulator         >  Shift Accumulator Right\n\n");
        printf("Q  Quit\n\n");
        printf("Option: ");

        char input [10];
        scanf("%s", &input);
        printf("%s\n", input);
        choice = toupper(input[0]);

        if (strlen(input) > 1 || !strchr(valid_input, choice)) {
            printf("\nInvalid option: %s\n\n", input);
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
            case 'C': printf("\n"); acc_value = 0; break;
            case 'H': mode = 'H'; printf("Mode is Hexadecimal\n\n"); break;
            case 'O': mode = 'O'; printf("Mode is Octal\n\n"); break;
            case 'D': mode = 'D'; printf("Mode is Decimal\n\n"); break;
        }
    }
}