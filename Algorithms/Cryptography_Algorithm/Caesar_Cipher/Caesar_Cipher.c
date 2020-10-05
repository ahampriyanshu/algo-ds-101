#include<stdio.h>

int main() {
    char message[100], ch;
    int i, key;

    printf("Message to encrypt: ");
    gets(message);
    do {
        printf("Key: ");
        scanf("%d", & key);
    } while (key < 0 || key > 26);

    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;

            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;

            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }

    printf("Encrypted message: %s\n", message);

    return 0;
}
