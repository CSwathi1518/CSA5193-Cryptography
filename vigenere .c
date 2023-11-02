#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char *plaintext, char *keyword, char *ciphertext) {
    int plainLen = strlen(plaintext);
    int keywordLen = strlen(keyword);
    int i, j;

    for (i = 0; i < plainLen; i++) {
        if (isalpha(plaintext[i])) {
            int shift = keyword[i % keywordLen] - 'A'; 
            if (islower(plaintext[i])) {
                ciphertext[i] = 'a' + (plaintext[i] - 'a' + shift) % 26;
            } else {
                ciphertext[i] = 'A' + (plaintext[i] - 'A' + shift) % 26;
            }
        } else {
            ciphertext[i] = plaintext[i]; 
        }
    }

    ciphertext[plainLen] = '\0';
}

int main() {
    char plaintext[1000], keyword[100];
    char ciphertext[1000];

    printf("Enter the plaintext: ");
    gets(plaintext);

    printf("Enter the keyword: ");
    gets(keyword);

    vigenereEncrypt(plaintext, keyword, ciphertext);

    printf("Cipher Text: %s\n", ciphertext);

    return 0;
}

Output:
Enter the plaintext: GEEKSFORGEEKS
Enter the keyword: AYUSH
Cipher Text: GCYCZFMLYLEIM
