#include <stdio.h>
#include <string.h>

char data[100], div[30];
int datalen, divlen;

void check() {
    int limit = datalen - divlen + 1; 
    for (int i = 0; i < limit; i++) {
        if (data[i] == '1') {
            for (int j = 0; j < divlen; j++)
                data[i + j] = (data[i + j] == div[j]) ? '0' : '1';
        }
    }
}

int main() {
    char og_data[100];

    printf("Enter Data: ");
    scanf("%s", data);
    printf("Enter Divisor: ");
    scanf("%s", div);
    
    datalen = strlen(data);
    divlen = strlen(div);
    strcpy(og_data, data);

    
    for (int i = 0; i < divlen - 1; i++) strcat(data, "0");
    datalen = strlen(data);  
    check();
    printf("CRC (Remainder): %s\n", data + datalen - (divlen - 1));
    printf("Transmitted Frame: %s%s\n", og_data, data + datalen - (divlen - 1));

  
    printf("\nEnter Received Data: ");
    scanf("%s", data); 
    
    datalen = strlen(data);  
    check();

    int error = 0;
    for (int i = 0; i < datalen; i++)
        if (data[i] == '1') error = 1;

    if (error) printf("Error Detected\n");
    else printf("No Error\n");

    return 0;
}
