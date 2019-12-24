#include <stdio.h>

void main() {
    int total, hours, minutes, seconds;
    printf("Enter the amount of seconds: ");
    scanf("%d", &total);
    seconds = total;
    hours = seconds / 3600;
    seconds %= 3600;
    minutes = seconds / 60;
    seconds %= 60;
    printf("%d seconds is equal to %d hours, %d minutes and %d seconds.\n",
        total, hours, minutes, seconds);
}
