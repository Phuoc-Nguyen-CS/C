#include <stdio.h>

int pairSum(int a, int b) {
    return a + b;
}
// Adds the previous number's pair sum to the current number's pair sum
int pairSumSequence(int n) {
    int sum = 0;
     for (int i = 0; i < n; i++) {
        printf("Calculating pair sum for (%d, %d)\n", i, i + 1);
        sum += pairSum(i, i + 1);
     }
     return sum;
}

int main() {
    int n = 5;
    int result = pairSumSequence(n);
    printf("The pair sum sequence for n=%d is: %d\n", n, result);
    return 0;
}