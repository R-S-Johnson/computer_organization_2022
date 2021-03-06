#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "calc.h"

unsigned short get_binary_op(char *bin);
void convert_to_binary(short acc, char *bin);

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
        case 'B': {
            char char_input[16];
            printf("Enter binary value: ");
            scanf("%s", &char_input);
            printf("%s\n\n", char_input);
            input = get_binary_op(char_input);
        }
    }
    return input;
}

void print_acc(short acc, char mode) {

    bin_str bin = {'0', '0', '0', '0', ' ', '0', '0', '0', '0', ' ', '0', '0', '0', '0', ' ', '0', '0', '0', '0', '\0'};
    convert_to_binary(acc, bin);

    printf("****************************************\n");
    switch (mode) {
        case 'B': printf("* Accumulator:         Input Mode: Bin *\n"); break;
        case 'D': printf("* Accumulator:         Input Mode: Dec *\n"); break;
        case 'H': printf("* Accumulator:         Input Mode: Hex *\n"); break;
        case 'O': printf("* Accumulator:         Input Mode: Oct *\n"); break;
    }
    printf("*   Binary  :  %s     *\n", bin);
    printf("*   Hex     :  %04hX                    *\n", acc);
    printf("*   Octal   :  %06ho                  *\n", acc);
    printf("*   Decimal :  %-10hd              *\n", acc);
    printf("****************************************\n\n");
}

char print_menu(void) {
    short need_input = 1;
    char choice;
    while (need_input){
        char valid_input [17] = "OHDCSQ&|^~><+-NB";
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

void add(short *acc, char mode) {
    short temp = *acc;
    short add_var = get_operand(mode);
    *acc += add_var;
    if (temp > 0 && add_var > 0 && *acc < 0) {
        printf("Positive Overflow\n");
    }
    else if (temp < 0 && add_var < 0 && *acc > 0) {
        printf("Negative Overflow\n");
    }
}

void subtract(short *acc, char mode) {
    short temp = *acc;
    short sub_var = get_operand(mode);
    *acc -= sub_var;
    if (temp > 0 && sub_var < 0 && *acc < 0) {
        printf("Positive Overflow\n");
    }
    else if (temp < 0 && sub_var > 0 && *acc > 0) {
        printf("Negative Overflow\n");
    }
}

unsigned short get_binary_op(char *bin) {
    unsigned to_return = 0;
    short count = 1;
    for (int i = strlen(bin) - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            to_return += count;
        }
        count *= 2;
    }
    return to_return;
}

void convert_to_binary(short acc, char *bin) {
    unsigned short acc_us = (unsigned) acc;
    unsigned power_tracker = 32768;
    for (int i = 0; i < 20; i++) {
        if ((i + 1)%5 == 0 || i == 19) {
            continue;
        }
        if (acc_us >= power_tracker) {
            bin[i] = '1';
            acc_us -= power_tracker;
        }
        power_tracker /= 2;
    }
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
            case 'B': mode = 'B'; printf("Mode is Binary\n\n"); break;
            case 'N': acc_value = -acc_value; break;
            case '~': acc_value = ~acc_value; break;
            case '<': {
                int shift;
                printf("Enter number of positions to left shift accumulator: ");
                scanf("%d", &shift);
                printf("%d\n", shift);
                acc_value <<= shift;
                break;
            }
            case '>': {
                int shift;
                printf("Enter number of positions to right shift accumulator: ");
                scanf("%d", &shift);
                printf("%d\n", shift);
                acc_value >>= shift;
                break;
            }
            case '&': {
                short compare_value = get_operand(mode);
                acc_value &= compare_value;
                break;
            }
            case '|': {
                short compare_value = get_operand(mode);
                acc_value |= compare_value;
                break;
            }
            case '^': {
                short compare_value = get_operand(mode);
                acc_value ^= compare_value;
                break;
            }
            case '+': add(&acc_value, mode); break;
            case '-': subtract(&acc_value, mode); break;
        }
    }
}