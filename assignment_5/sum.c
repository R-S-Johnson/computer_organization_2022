#include <stdio.h>

int a = 8;
int b = -3;
int m = 10;


int summation(int n) {
    int toReturn = 0;
    int i = 0;
    while (i <= n) {
        toReturn += b;
        int j = 0;
        while (j < i) {
            toReturn += a;
            j++;
        }
        i++;
    }
    return toReturn;
}

int main(int argc, char const *argv[]) {
    int i = 0;
    while (i < m) {
        printf("%-2d ", i);
        printf("%-2x :", i);
        int output = summation(i);
        printf("   %-3d   ", output);
        printf("%08x\n", output);
        i++;
    }
}
