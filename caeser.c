//write a program to encrypt and decrypt the user input message and key using caeser cipher.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void encrypt(char *message, int key)
{
    int i;
    for (i = 0; message[i] != '\0'; i++)
    {
        if (isalpha(message[i]))
        {
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = (message[i] - base + key) % 26 + base;
        }
    }
}

void decrypt(char *message, int key)
{
    int i;
    for (i = 0; message[i] != '\0'; i++)
    {
        if (isalpha(message[i]))
        {
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = (message[i] - base - key + 26) % 26 + base;
        }
    }
}

int main()
{
    char message[MAX_LENGTH];
    int key;
    printf("Caeser Cipher \n ");
    printf("Enter a message to encrypt and decrypt: ");
    fgets(message, MAX_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove trailing newline

    printf("Enter the key between 0 to 25: ");
    scanf("%d", &key);

    printf("The Original message is: %s\n", message);

    encrypt(message, key);
    printf("The encrypted message is: %s\n", message);

    decrypt(message, key);
    printf("The decrypted message is: %s\n", message);

    return 0;
}
