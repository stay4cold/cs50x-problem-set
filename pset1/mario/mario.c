#include <cs50.h>
#include <stdio.h>

int main(void) {
    int height;
    do {
        height = get_int("Height: ");
    } while(height < 1 || height > 8);
    for (int i = 1; i <= height; i++) {
        int j = 0;
        while (j < height) {
            if (j < height - i) {
                printf(" ");
            } else {
                printf("#");
            }
            j++;
        }
        
        printf("  ");
        
        j = 0;
        while (j < i) {
            printf("#");
            j++;
        }
        
        printf("\n");
    }
    return 0;
}