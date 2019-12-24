#include <stdio.h>

void main() {
    int numerator, denominator;
    printf("Enter a numerator: ");
    scanf("%d", &numerator);
    printf("Enter a denominator: ");
    scanf("%d", &denominator);

    if (numerator % denominator) {
        printf("There is a remainder!\n");
    } else {
        printf("There is no remainder!\n");
    }
}
