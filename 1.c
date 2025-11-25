#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int a, b, c, d;

    printf("Enter an IPv4 address (e.g., 192.168.1.1): ");
    if (scanf("%u.%u.%u.%u", &a, &b, &c, &d) != 4) {
        printf("Invalid input format.\n");
        return 1;
    }

    if (a > 255 || b > 255 || c > 255 || d > 255) {
        printf("Invalid IPv4 address.\n");
        return 1;
    }
    
    char ipClass;
    if (a <= 127)
        ipClass = 'A';
    else if (a <= 191)
        ipClass = 'B';
    else if (a <= 223)
        ipClass = 'C';
    else if (a <= 239)
        ipClass = 'D';
    else
        ipClass = 'E';

    printf("\nGiven IP Address: %u.%u.%u.%u\n", a, b, c, d);
    printf("Class: %c\n", ipClass);

    switch (ipClass) {
        case 'A':
            printf("Network ID: %u.0.0.0\n", a);
            printf("Host ID: 0.%u.%u.%u\n", b, c, d);
            break;

        case 'B':
            printf("Network ID: %u.%u.0.0\n", a, b);
            printf("Host ID: 0.0.%u.%u\n", c, d);
            break;

        case 'C':
            printf("Network ID: %u.%u.%u.0\n", a, b, c);
            printf("Host ID: 0.0.0.%u\n", d);
            break;

        case 'D':
            printf("Class D is for multicast. No network/host division.\n");
            break;

        case 'E':
            printf("Class E is for experimental use. No network/host division.\n");
            break;
    }

    return 0;
}