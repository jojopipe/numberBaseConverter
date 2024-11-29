#include <stdio.h>
#include <math.h>
#include <string.h>

int toDecimal(char* num, int base) {
    if (!num) return 0;
    int result = 0;
    int len = (int) strlen(num);
    char curr;
    int mult;
    for (int i = 0; i < len; ++i) {
        curr = num[len - i - 1];
        if (1 <= base && base <= 10) {
            mult = curr - '0';
        }
        else if (11 <= base && base <= 36) {
            mult = 10 + curr - 'a';
        }
        else {
            return 0;
        }
        if (mult >= base) return 0;
        result += (int) pow(base, i) * mult;
    }
    return result;
}

int main(void) {
    int base = 16;
    char* num = "ffaadd";
    int decimal = toDecimal(num, base);
    printf("%s_%d in base 10: %d\n", num, base, decimal);
    return 0;
}
