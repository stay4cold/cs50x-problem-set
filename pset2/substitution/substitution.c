#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    string key = argv[1];
    if (strlen(key) != 26) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 'A'; i <= 'Z';i++) {
        int f = 0;
        for (int j = 0, len = strlen(key); j < len; j++) {
            if (key[j] == i || key[j] == i + ('a' - 'A')) {
                f = 1;
                break;
            }
        }
        if (!f) {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plain); i < len; i++) {
        char c = plain[i];
        if (islower(c)) {
            printf("%c", tolower(key[c - 'a']));
        } else if (isupper(c)) {
            printf("%c", toupper(key[c - 'A']));
        } else {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}