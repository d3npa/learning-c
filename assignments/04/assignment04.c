#include <stdio.h>
#define PI 3.14

void main() {
    float r;
    printf("Enter the radius of your circle: ");
    scanf("%f", &r);
    printf("The area of your circle is: %.6f\n", PI*(r*r));
}
