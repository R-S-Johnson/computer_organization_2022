#include "utils.h"
#include <string.h>

void upper(char str[]) {
    for (int ch = 0; ch < strlen(str); ch++) {
        if (str[ch] < 96 && str[ch] > 123) {
            str[ch] = str[ch] - ('a' - 'A');
        }
    }
}