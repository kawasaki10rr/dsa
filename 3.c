#include <stdio.h>

#define INF 999
#define MAX 10

int main() {
    int n, cost[MAX][MAX], dist[MAX][MAX], nextHop[MAX][MAX];
    int i, j, k, updated;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix (use %d for no link):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i == j) cost[i][j] = 0;
            dist[i][j] = cost[i][j];
            nextHop[i][j] = j;     
        }
    }
    
    do {
        updated = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < n; k++) {
                    if (dist[i][j] > cost[i][k] + dist[k][j]) {
                        dist[i][j] = cost[i][k] + dist[k][j];
                        nextHop[i][j] = k;   
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);

    printf("\n--- Final Distance Vector Table ---\n");
    for (i = 0; i < n; i++) {
        printf("\nRouter %d:\n", i + 1);
        printf("Dest\tCost\tNextHop\n");
        for (j = 0; j < n; j++) {
            printf("%d\t%d\t%d\n", j + 1, dist[i][j], nextHop[i][j] + 1);
        }
    }
    return 0;
}
