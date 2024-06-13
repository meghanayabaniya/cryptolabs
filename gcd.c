//write a program to find gcd of two input integer using euclidean algorithm.
#include<stdio.h>
#include<math.h>

int gcd (int a, int b){
    if (b==0){
        return a;
    }
    else{
        printf("%d = %d * %d = %d \n",a,b, (a/b),((a-(b*(a/b))))  );
        return gcd(b,a%b);
    }
}
int main(){
    int a,b ;
    printf("Enter the value of a: ");
    scanf("%d",&a);

    printf("Enter the value of b: ");
    scanf("%d",&b);

    if (a>b ||gcd(a,b)==1){
        printf("The gcd of %d and %d is: %d \n ", a, b, gcd(a,b));
        printf("Since gcd of %d and %d is 1. The numbers are relatively prime.\n ");
    }
    else if (a>b ||gcd(a,b)!=1){
        printf("Since gcd of %d and %d is not 1. The numbers are relatively prime.");

    }
    
    else{
        printf("The value is greater than %d",a);
    }    
}

// if(gcd(a,b)==1){
//             printf("since gcd of %d and %d is 1. The numbers are relatively prime.");
//         }
//         else{ 
//             printf("since gcd of %d and %d is not 1. The numbers are relatively prime.");
//         }