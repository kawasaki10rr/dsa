#include <stdio.h>
#include <string.h>

int main() {
    char data[100], poly[50], crc[150];

    printf("Enter data bits: ");
    scanf("%s", data);
    printf("Enter generator polynomial: ");
    scanf("%s", poly);

    int d = strlen(data), p = strlen(poly);

    strcpy(crc, data);
    for (int i = 0; i < p - 1; i++)
        crc[d + i] = '0';
    crc[d + p - 1] = '\0';

    for (int i = 0; i < d; i++)      
        if (crc[i] == '1')
            for (int j = 0; j < p; j++)
                crc[i + j] = (crc[i + j] == poly[j]) ? '0' : '1';

    printf("CRC remainder: %.*s\n", p - 1, crc + d);
    return 0;
}

