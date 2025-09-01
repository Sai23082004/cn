#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char pwd[20];                   // input password
    char alpha[27] = "abcdefghijklmnopqrstuvwxyz"; // alphabet
    int num[20], i, n, key;

    // Input password
    printf("\nEnter the password: ");
    scanf("%s", pwd);

    n = strlen(pwd);

    // Convert characters to numbers (0-25)
    for (i = 0; i < n; i++)
        num[i] = toascii(tolower(pwd[i])) - 'a';

    // Input key
    printf("\nEnter the key: ");
    scanf("%d", &key);

    // Encryption: (num + key) % 26
    for (i = 0; i < n; i++)
        num[i] = (num[i] + key) % 26;

    for (i = 0; i < n; i++)
        pwd[i] = alpha[num[i]];

    printf("\nThe key is: %d", key);
    printf("\nEncrypted text is: %s", pwd);

    // Decryption: (num - key + 26) % 26
    for (i = 0; i < n; i++) {
        num[i] = (num[i] - key) % 26;
        if (num[i] < 0)
            num[i] += 26;
        pwd[i] = alpha[num[i]];
    }
    printf("\nDecrypted text is: %s\n", pwd);

    return 0;
}
