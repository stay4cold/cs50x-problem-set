#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long number;
    do {
        number = get_long("Number: ");
    } while (number < 1);
    int even = 0;
    for (int i = 0; i < 16;i+=2) {
        long a = (long)pow(10, i + 2 );
        long b = number % a;
        int c = b / (a/10);
        int d = c * 2;
        if (d > 9) {
            d = (d/10) + (d%10);
        }
        even += d;
    }
    for (int i = 0; i < 16;i+=2) {
        long a = (long)pow(10, i + 1 );
        long b = number % a;
        int c = b / (a/10);
        even += c;
    }
    int n = even % 10;
    if (n != 0 || (number / ((long)pow(10, 16)) > 0) || (number / ((long)pow(10, 12)) == 0)) {
        printf("INVALID\n");
    } else {
        long m = number / ((long)pow(10, 12));
        if (m / 10000 > 0) {
            printf("INVALID\n");
        } else {
            m = m % 10000;
            if (m >= 1000) { // 16 
                int a = m / 100;
                if (a >= 51 && a <= 55) {
                    printf("MASTERCARD\n");
                } else if (a >= 40 && a <= 49) {
                    printf("VISA\n");
                } else {
                    printf("INVALID\n");
                }
            } else if (m >= 100) { // 15
                int b = m / 10;
                if (b == 34 || b == 37) {
                    printf("AMEX\n");
                } else {
                    printf("INVALID\n");
                }
            } else if (m >= 10) { // 14
                if (m >=40 && m <=49) {
                     printf("VISA\n");
                } else {
                    printf("INVALID\n");
                }
            } else if (m > 0) { // 13
                if (m ==4) {
                     printf("VISA\n");
                } else {
                    printf("INVALID\n");
                }
            } else {
                printf("INVALID\n");
            }
        }
    }
    return 0;
}