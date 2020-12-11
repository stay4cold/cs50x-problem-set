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
    if (n == 0) {
        
    } else {
        printf("INVALID\n");
    }

}