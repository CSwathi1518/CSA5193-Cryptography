#include <stdio.h>
#include <stdlib.h>

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1;
}

void encrypt(char plaintext[], int a, int b) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] != ' ') {
            plaintext[i] = (char)(((a * (plaintext[i] - 'A') + b) % 26) + 'A');
        }
    }
}

void decrypt(char ciphertext[], int a, int b) {
    int aInverse = modInverse(a, 26);
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] != ' ') {
            ciphertext[i] = (char)((aInverse * (ciphertext[i] - 'A' - b + 26) % 26) + 'A');
        }
    }
}

int main() {
    char text[100];
    int a, b;

    printf("Enter the text to be encrypted: ");
    gets(text);

    printf("Enter the key values (a and b) for encryption (space-separated): ");
    scanf("%d %d", &a, &b);

    encrypt(text, a, b);
    printf("Encrypted text: %s\n", text);

    decrypt(text, a, b);
    printf("Decrypted text: %s\n", text);

    return 0;
}
