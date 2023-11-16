#include <stdio.h>
#include <string.h>
#include <ctype.h>

void calculateFrequency(char *text, int *frequency) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                frequency[c - 'A']++;
            } else {
                frequency[c - 'a']++;
            }
        }
    }
}

int main() {
    char text[1000];
    int frequency[26] = {0}; // Initialize frequency array for 26 English letters

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    calculateFrequency(text, frequency);

    printf("Letter frequencies:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'A' + i, frequency[i]);
    }

    return 0;
}
