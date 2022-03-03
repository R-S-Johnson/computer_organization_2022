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

}

int main(void) {
    
}