#include <stdio.h>

int main() {
    int window, frames;

    printf("Enter window size: ");
    scanf("%d", &window);

    printf("Enter number of frames to send: ");
    scanf("%d", &frames);

    int i = 1; 

    while (i <= frames) {
        printf("\nSending frames: ");
        for (int j = i; j < i + window && j <= frames; j++) {
            printf("%d ", j);
        }

        printf("\nWaiting for ACK (cumulative)...\n");

        int ack;
        printf("Enter last ACK received: ");
        scanf("%d", &ack);

        
        if (ack < i - 1 || ack > frames || ack > i + window - 1) {
            printf("Invalid ACK value. Please enter a valid ACK within the current window.\n");
            continue; 
        }

        if (ack < i) {
            printf("ACK not received properly… Resending window\n");
          
        } else {
           
            i = ack + 1;
        }
    }

    printf("\nAll frames sent successfully.\n");
    return 0;
}
