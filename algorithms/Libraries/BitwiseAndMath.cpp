void math_review() {
    int a = 5; // 0101
    int b = 9; // 1001

    // Common Bitwise Operations
    int and_op = a & b;
    int or_op  = a | b;
    int xor_op = a ^ b;
    int not_op = ~a;

    // Shifts 
    int leftShift = a << 1; // Multiplying by 2
    int rightShift = b >> 1; // Dividing by 2

    // Built-ins
    int count = __builtin_popcount(a); // Number of set bits (1s)
}