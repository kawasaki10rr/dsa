#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUCCESS 1
#define LOST 0

int main() {
    int total_frames, window_size;
    int next_frame = 1;

    printf("Enter total number of frames: ");
    scanf("%d", &total_frames);

    printf("Enter window size: ");
    scanf("%d", &window_size);

    srand(time(NULL)); 

    while (next_frame <= total_frames) {

        int end_frame = next_frame + window_size - 1;
        if (end_frame > total_frames)
            end_frame = total_frames;

        printf("\nSender: Sending frames %d to %d\n", next_frame, end_frame);

        int lost_frame = -1;
        for (int i = next_frame; i <= end_frame; i++) {
            if (rand() % 10 < 3) {  
                lost_frame = i;
                break;
            }
        }

        if (lost_frame != -1) {
            printf("Receiver: Frame %d LOST!\n", lost_frame);
            printf("Receiver: ACK %d sent (Go-Back-N triggered) \n", next_frame - 1);
            printf("Sender: Resending from frame %d...\n", next_frame);
        } else {
            printf("Receiver: All frames %d to %d received successfully. \n", 
                   next_frame, end_frame);
            printf("Receiver: Sending ACK %d\n", end_frame);
            next_frame = end_frame + 1;
        }
    }

    printf("\nAll frames sent successfully!\n");
    return 0;
}
