/* ============================================================
   NUMBER HELPERS -- the "math part" of most BST questions
   Copy only the helper you need into your question file.
   ============================================================ */
#include <stdio.h>

int isSquare(int x) {                  // 16 -> 1, 15 -> 0
    for (int i = 1; i * i <= x; i++)
        if (i * i == x) return 1;
    return 0;
}

int isCube(int x) {                    // 27 -> 1, 26 -> 0
    for (int i = 1; i * i * i <= x; i++)
        if (i * i * i == x) return 1;
    return 0;
}

int isPrime(int n) {                   // 7 -> 1, 8 -> 0
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int digitSum(int n) {                  // 123 -> 6
    int sum = 0;
    while (n > 0) {
        sum += n % 10;                 // last digit
        n /= 10;                       // drop last digit
    }
    return sum;
}

int digitalRoot(int n) {               // 16 -> 7
    while (n > 9) n = digitSum(n);
    return n;
}

int countDivisors(int n) {             // 12 -> 6
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0) count++;
    return count;
}

int binaryLength(int n) {              // 10 (1010) -> 4
    int len = 0;
    while (n > 0) {
        len++;
        n /= 2;
    }
    return len;
}

int isNonDecreasing(int n) {           // 455 -> 1, 321 -> 0
    int prev = 9;
    while (n > 0) {
        int d = n % 10;
        if (d > prev) return 0;
        prev = d;
        n /= 10;
    }
    return 1;
}

int isPalindromeNumber(int n) {        // 121 -> 1
    int original = n, rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev == original;
}

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long lcm(long long a, long long b) {      // divide first to stay small
    return a / gcd(a, b) * b;
}

int main() {
    printf("isSquare(16)=%d isCube(27)=%d isPrime(7)=%d\n", isSquare(16), isCube(27), isPrime(7));
    printf("digitSum(123)=%d digitalRoot(16)=%d countDivisors(12)=%d\n", digitSum(123), digitalRoot(16), countDivisors(12));
    printf("binaryLength(10)=%d isNonDecreasing(455)=%d palindrome(121)=%d\n", binaryLength(10), isNonDecreasing(455), isPalindromeNumber(121));
    printf("gcd(12,18)=%lld lcm(4,6)=%lld\n", gcd(12, 18), lcm(4, 6));
    return 0;
}