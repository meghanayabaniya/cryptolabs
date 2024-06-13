//write a program to test if the number is primitive root or not.
#include <stdio.h>
#include <math.h>

int main() {
    int p, q;
    int v[20] = {0};  // Ensure array is initialized to zero
    
    printf("Enter the prime number: ");
    scanf("%d", &p);
    
    printf("Enter the positive integer: ");
    scanf("%d", &q);

    int is_primitive_root = 1;  // Flag to check if q is a primitive root

    // Check if q^i mod p results in unique values from 1 to p-1
    for (int i = 1; i < p; i++) {
        v[i] = (int)pow(q, i) % p;
        printf("%d^%d mod %d = %d\n", q, i, p, v[i]);
        
        // Check if the value repeats
        for (int j = 1; j < i; j++) {
            if (v[i] == v[j]) {
                is_primitive_root = 0;
                break;
            }
        }
        
        if (!is_primitive_root) {
            break;
        }
    }
    
    if (is_primitive_root) {
        printf("%d is a primitive root of %d.\n", q, p);
    } else {
        printf("%d is not a primitive root of %d.\n", q, p);
    }

    return 0;
}
