/*
Finding the Greatest Common Divisor using Euclid's Method.
The program is in C. 
It took me a while to understand the gcd(int a, int b) function but it works like this:
It's a recursive function that continuously uses the modulo function to reduce the b value to 0.
First, it receives the numerator and denominator as int a and b.
Then it recurses itself by the denominator as int a, (numerator % denominator = remainder) goes in as int b.
The second recursion, int b(the remainder) now becomes int a. Int a(the denominator) % int b(the remainder) now becomes int b.
Here's an easy example of input 10 and 8 going through the GCD recursion:
10, 8
8, 10 % 8 = 2
A = 8, B = 2
2, 8 % 2 = 6,
A = 2, B = 6
6, 2 % 6 = 2,
A = 6, B = 2
2, 6 % 2 = 0,
A = 2, B = 0
B = 0, return 2
I hope this makes sense. Please let me know if you have any questions!
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int* solution(int numer1, int denom1, int numer2, int denom2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2 * sizeof(int));
     
    int denom = denom1 * denom2;
    
    numer1 = denom2 * numer1;
    numer2 = denom1 * numer2;
    
    answer[0] = numer1 + numer2;
    answer[1] = denom;

    int gcdResult = gcd(answer[0], answer[1]);
    
    answer[0] /= gcdResult;
    answer[1] /= gcdResult;
    
    return answer;
}
