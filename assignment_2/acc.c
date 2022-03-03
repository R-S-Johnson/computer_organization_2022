#include <stdio.h>
#include <string.h>

short get_operand(char mode) {
    short input;
    if (mode == 'D') {
        printf("Enter decimal value: ");
        scanf("%d", &input);
        printf("%d\n", input);
    }
}

void print_acc(short acc, char mode) {

}

char print_menu(void) {

}

int main(void) {
    char input = 'D';
    get_operand(input);
}