#include <iostream>
using namespace std;

int i;

bool is_power_of_2(int); // loop function
bool isPowerOfTwo(int); // non-loop function
bool isPrime(int);
bool reduceFraction(int num1, int num2);

int main() {
    int n = 8;  // non-loop test
    if (isPowerOfTwo(n)) {
        printf("%d is a power of 2\n", n);
    } else {
        printf("%d is not a power of 2\n", n);
    }

    printf("\n");
    for (int num = 0; num < 10; num++) {    // loop test

        bool result = is_power_of_2(num);

        if (result == true) {
            printf("%d is a power of 2\n", num);
        } else {
            printf("%d is not a power of 2\n", num);
        }
    }

    printf("\n");


    int primeNum = 3;   // prime test
    if (isPrime(primeNum)) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    printf("\n");

    int Num1 = 1;   // reduce test
    int Num2 = 3;
    cout << Num1 << "/" << Num2 << endl;
    if (reduceFraction(Num1, Num2)) {   // could not get test to work properly :(
        printf("PASS\n");
    } else {
        if (reduceFraction(!Num1, Num2)) {
            printf("FAIL\n");
        }
    }
    return 0;
}


bool is_power_of_2(int num) { // looping function
    if (num == 0) {
        return false;
    }

    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            return false;
        }
    }
    return true;
}


bool isPowerOfTwo(int n) { // non-looping function
    return n > 0 && (n & (n - 1)) == 0;
}


bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    if (number == 2) {
        return true;
    }
    if (number % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int gcd(int a, int b) {     // gcd function help from tutorialspoint
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

bool reduceFraction(int num1, int num2) {       // help from tutorialspoint
    int denom = gcd(num1, num2);
    num1 /= denom;
    num2 /= denom;
    cout << "lowest fraction : " << num1 << "/" << num2 << endl;
    return true;
}