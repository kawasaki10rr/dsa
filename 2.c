#include <stdio.h>
#include <string.h>

int main() {
    char data[500], poly[100], crc[600];

    printf("Enter data bits: ");
    scanf("%499s", data);
    printf("Enter generator polynomial: ");
    scanf("%99s", poly);

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
    printf("Transmitted frame: %s%.*s\n", data, p - 1, crc + d);

    return 0;
}
