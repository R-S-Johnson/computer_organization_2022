#include <stdio.h>

int a = 8;
int b = -3;
int m = 10;


int summation(int n) {
    int toReturn = 0;
    for (int i = 0; i <= n; i++) {
        toReturn += b;
        for (int j = 0; j < i; j++) {
            toReturn += a;
        }
    }
    return toReturn;
}

int main(int argc, char const *argv[]) {
    for (int i = 0; i < m; i++) {
        printf("%-2d ", i);
        printf("%-2x :", i);
        int output = summation(i);
        printf("   %-3d   ", output);
        printf("%08x\n", output);
    }
}
