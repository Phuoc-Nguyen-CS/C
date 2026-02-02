#include <stdio.h>

int power (int a, int b) {
    if (b == 0) {
        return 1;
    } else {
        return a * power(a, b - 1);
    }
}

int main() {
    int base = 2;
    int exponent = 3;
    int result = power(base, exponent);
    printf("%d raised to the power of %d is: %d\n", base, exponent, result);
    return 0;
}