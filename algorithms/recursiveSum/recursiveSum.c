#include <stdio.h>

int sum(int);

int main() {

    int total = sum(5);
    printf("Total: %d\n", total);
    
    return 0;
}

int sum(int n) {
    if (n <= 0) {
        return 0;
    } else {
        printf("Adding: %d\n", n);
        return n + sum(n - 1);
    }
}
