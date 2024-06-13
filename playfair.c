#include <stdio.h>

int check(char table[5][5], char k) {
    int i, j;
    for (i = 0; i < 5; ++i)
        for (j = 0; j < 5; ++j) {
            if (table[i][j] == k)
                return 0;
        }
    return 1;
}

int main() {
    int i, j, key_len;
    char table[5][5];
    for (i = 0; i < 5; ++i)
        for (j = 0; j < 5; ++j)
            table[i][j] = '0';

    printf("**********Playfair Cipher************\n");

    printf("Enter the length of the Key: ");
    scanf("%d", &key_len);
    getchar(); // to consume the newline after the key length input

    char key[key_len + 1]; // +1 for the null terminator

    printf("Enter the Key: ");
    fgets(key, key_len + 1, stdin);
    getchar(); // to consume the newline after the key input

    // Replace 'j' with 'i' in the key
    for (i = 0; i < key_len; ++i) {
        if (key[i] == 'j')
            key[i] = 'i';
    }

    int flag;
    int count = 0;

    // Inserting the key into the table
    for (i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j) {
            flag = 0;
            while (flag != 1) {
                if (count >= key_len) // fixed off-by-one error
                    goto l1;
                flag = check(table, key[count]);
                ++count;
            }
            table[i][j] = key[count - 1]; // fixed indexing
        }
    }

    l1:
    printf("\n");

    int val = 97;
    // Inserting other alphabets
    for (i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j) {
            if (table[i][j] >= 97 && table[i][j] <= 123) {
                continue;
            } else {
                flag = 0;
                while (flag != 1) {
                    if (val == 'j')
                        ++val;
                    flag = check(table, (char)val);
                    ++val;
                }
                table[i][j] = (char)(val - 1);
            }
        }
    }

    printf("The table is as follows:\n");
    for (i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }

    int l = 0;
    printf("\nEnter the length of plain text (without spaces): ");
    scanf("%d", &l);
    getchar(); // to consume the newline after the length input

    printf("\nEnter the Plain text: ");
    char p[l + 1];
    fgets(p, l + 1, stdin);
    getchar(); // to consume the newline after the plain text input

    // Replace 'j' with 'i' in the plain text
    for (i = 0; i < l; ++i) {
        if (p[i] == 'j')
            p[i] = 'i';
    }

    printf("\nThe replaced text (j with i): ");
    for (i = 0; i < l; ++i)
        printf("%c ", p[i]);
    printf("\n");

    // Count bogus characters needed
    count = 0;
    for (i = 0; i < l - 1; ++i) {
        if (p[i] == p[i + 1])
            count++;
    }

   // printf("\nThe cipher has to enter %d bogus char(s). It is either 'x' or 'z'\n", count);

    int length = l + count;
    if (length % 2 != 0)
        length++;

    char p1[length + 1]; // +1 for the null terminator

    // Inserting bogus characters
    int count1 = 0;
    for (i = 0; i < l; ++i) {
        p1[count1++] = p[i];
        if (p[i] == p[i + 1]) {
            p1[count1++] = (p[i] == 'x') ? 'z' : 'x';
        }
    }
    if (count1 < length) {
        p1[count1++] = (p1[count1 - 1] == 'x') ? 'z' : 'x';
    }
    p1[length] = '\0'; // null-terminate the string

    printf("The Decryption message is:");
    for (i = 0; i < length; ++i)
        printf("%c ", p1[i]);
    printf("\n");

    char cipher_text[length + 1]; // +1 for the null terminator
    int r1, r2, c1, c2;
    int k1;

    for (k1 = 0; k1 < length; k1 += 2) {
        for (i = 0; i < 5; ++i) {
            for (j = 0; j < 5; ++j) {
                if (table[i][j] == p1[k1]) {
                    r1 = i;
                    c1 = j;
                } else if (table[i][j] == p1[k1 + 1]) {
                    r2 = i;
                    c2 = j;
                }
            }
        }

        if (r1 == r2) {
            cipher_text[k1] = table[r1][(c1 + 1) % 5];
            cipher_text[k1 + 1] = table[r1][(c2 + 1) % 5];
        } else if (c1 == c2) {
            cipher_text[k1] = table[(r1 + 1) % 5][c1];
            cipher_text[k1 + 1] = table[(r2 + 1) % 5][c1];
        } else {
            cipher_text[k1] = table[r1][c2];
            cipher_text[k1 + 1] = table[r2][c1];
        }
    }
    cipher_text[length] = '\0'; // null-terminate the string

    printf("\nThe encryption message is:\n ");
    for (i = 0; i < length; ++i)
        printf("%c ", cipher_text[i]);
    printf("\n");

    return 0;
}