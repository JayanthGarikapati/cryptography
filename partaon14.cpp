#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char plaintext[] = "send more money";
    int key[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    int len = strlen(plaintext);
    char ciphertext[len + 1]; // add 1 for null terminator

    for (int i = 0; i < len; i++) {
        char c = plaintext[i];
        int shift = key[i];
        ciphertext[i] = ((c - 'a' + shift) % 26) + 'a';
    }
    ciphertext[len] = '\0';

    printf("Plaintext: %s\n", plaintext);
    printf("Key: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", key[i]);
    }
    printf("\n");
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
