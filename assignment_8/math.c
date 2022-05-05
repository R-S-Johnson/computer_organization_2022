#include <stdio.h>

int abs(int n);
int mult(int x, int y);
int rfact(int n);

int main(int argc, char const *argv[])
{
    int input[5] = {3, -5, -4, 7, 0};
    int index = 0;
    int num = input[0];
    do {
        printf("%d\n", num);
        int absReturn = abs(num);
        printf("%08X\n", absReturn);
        if (num % 2 == 0) {
            int multReturn = mult(absReturn, absReturn);
            printf("%08X\n", multReturn);
        }
        else {
            int factReturn = rfact(absReturn);
            printf("%08X\n", factReturn);
        }
    index++;
    num = input[index];
    } while (num != 0);
    return 0;
}


int abs(int n) {
    if (n < 0) {
        return -n;
    }
    else {
        return n;
    }
}

int mult(int x, int y) {
    int toReturn = 0;
    for (int i = 0; i < x; i++) {
        toReturn += y;
    }
    return toReturn;
}

int rfact(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n*rfact(n - 1);
    }
}