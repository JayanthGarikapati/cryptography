#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define ALPHABET_SIZE 26

char* generate_cipher_alphabet() {
    char plain_alphabet[ALPHABET_SIZE + 1] = "abcdefghijklmnopqrstuvwxyz";
    char cipher_alphabet[ALPHABET_SIZE + 1] = "abcdefghijklmnopqrstuvwxyz";
    int i, j;
    char temp;
    srand(time(NULL));
    for (i = 0; i < ALPHABET_SIZE; i++) {
        j = rand() % ALPHABET_SIZE;
        temp = cipher_alphabet[i];
        cipher_alphabet[i] = cipher_alphabet[j];
        cipher_alphabet[j] = temp;
    }
    return strdup(cipher_alphabet);
}

char* encrypt(char* plaintext, char* cipher_alphabet) {
    int i;
    int len = strlen(plaintext);
    char* ciphertext = malloc(len + 1);
    for (i = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[i] = tolower(cipher_alphabet[tolower(plaintext[i]) - 'a']);
        } else {
            ciphertext[i] = plaintext[i]; 
        }
    }
    ciphertext[i] = '\0';
    return ciphertext;
}

int main() {
    char* cipher_alphabet = generate_cipher_alphabet();
    printf("Cipher alphabet: %s\n", cipher_alphabet);
    char plaintext[] = "The quick brown fox jumps over the lazy dog.";
    char* ciphertext = encrypt(, cipher_alphabet);
    printf("Ciphertext: %s\n", ciphertext);
    free(cipher_alphabet);
    free(ciphertext);
    return 0;
}


