#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int key;
    if (argc != 2 || (key = atoi(argv[1])) <= 0) {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    for (int i = 0, len = strlen(argv[1]); i < len; i++) {
        char n = argv[1][i];
        if (n < '0' || n > '9') {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }
    printf("Success\n%d\n",key);
    key = key % 26;
    string text = get_string("plaintext: ");
    
    printf("ciphertext: ");
    for (int i = 0, len = strlen(text); i < len; i++) {
        if (islower(text[i])) {
            printf("%c", (text[i] - 'a' + key) % 26 + 'a');
        } else if (isupper(text[i])) {
            printf("%c", (text[i] - 'A' + key) % 26 + 'A');
        } else {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}