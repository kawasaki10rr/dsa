/* Program : Sliding Window Protocol Simulation (Flow Control) */

#include <stdio.h>

int main() {
    int n, w;          // n = total frames, w = window size
    int sent = 0;      // index of next frame to send

    printf("Enter total number of frames : ");
    scanf("%d", &n);
    printf("Enter window size           : ");
    scanf("%d", &w);

    while (sent < n) {
        int i;

        /* show current window */
        printf("\nCurrent window: ");
        for (i = sent; i < sent + w && i < n; i++)
            printf("%d ", i);
        printf("\n");

        /* send all frames in window one by one */
        for (i = sent; i < sent + w && i < n; i++) {
            printf("Sending frame %d\n", i);
            printf("ACK received for frame %d\n", i);
            sent++;        // window base moves by one
        }

        printf("Window slides. Next base frame = %d\n", sent);
    }

    printf("\nAll %d frames transmitted successfully.\n", n);
    return 0;
}
