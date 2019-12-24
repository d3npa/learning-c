#include <stdio.h>
#include <math.h>

void main() {
    float a, b, c;
    float plus, minus;
    printf("Enter the value for A: ");
    scanf("%f", &a);
    printf("Enter the value for B: ");
    scanf("%f", &b);
    printf("Enter the value for C: ");
    scanf("%f", &c);

    plus = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
    minus = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
    printf("The solution using the '+' operator is: %.6f", plus);
    if (a * (plus * plus) + b * plus + c != 0) {
        printf(", but you might need to double-check that...\n");
    } else {
        printf("\n");
    }

    printf("The solution using the '-' operator is: %.6f", minus);
    if (a * (minus * minus) + b * minus + c != 0) {
        printf(", but you might need to double-check that...\n");
    } else {
        printf("\n");
    }
}
