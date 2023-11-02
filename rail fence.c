#include <stdio.h>
#include <string.h>
void railFenceEncrypt(char *plaintext, int rails, char *ciphertext) {
    int len = strlen(plaintext);
    char matrix[rails][len];
    int row = 0, direction = 1;

    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            matrix[i][j] = ' '; 
        }
    }

    for (int i = 0; i < len; i++) {
        matrix[row][i] = plaintext[i];

        if (row == 0) {
            direction = 1;
        } else if (row == rails - 1) {
            direction = -1;
        }

        row += direction;
    }

    // Extract the ciphertext from the matrix
    int k = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (matrix[i][j] != ' ') {
                ciphertext[k++] = matrix[i][j];
            }
        }
    }
    ciphertext[len] = '\0';
}

int main() {
    char plaintext[1000], ciphertext[1000];
    int rails;

    printf("Enter the plaintext: ");
    gets(plaintext);

    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    railFenceEncrypt(plaintext, rails, ciphertext);

    printf("Cipher Text: %s\n", ciphertext);

    return 0;
}

Output:
Enter the plaintext: defend the east wall
Enter the number of rails: 3
Cipher Text: dnhaweedteesalftl
