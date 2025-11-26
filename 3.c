#include <stdio.h>
#define INF 9999

struct Edge {
    int u, v, w;
};

int main() {
    int n, e, src;
    struct Edge edges[50];
    int dist[50];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    printf("Enter source node: ");
    scanf("%d", &src);

    // initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[src] = 0;

    // relax edges n-1 times
    for (int k = 1; k <= n - 1; k++)
        for (int i = 0; i < e; i++)
            if (dist[edges[i].u] != INF &&
                dist[edges[i].v] > dist[edges[i].u] + edges[i].w)
                dist[edges[i].v] = dist[edges[i].u] + edges[i].w;

    // check for negative cycle
    for (int i = 0; i < e; i++)
        if (dist[edges[i].u] != INF &&
            dist[edges[i].v] > dist[edges[i].u] + edges[i].w) {
            printf("\nNegative cycle detected!\n");
            return 0;
        }

    printf("\nShortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++)
        printf("Node %d : %d\n", i, dist[i]);

    return 0;
}
/*  
Enter number of nodes: 5
Enter number of edges: 7
Enter edges (u v weight):
0 1 6
0 2 7
1 2 8
1 3 5
1 4 -4
2 3 -3
3 4 9
Enter source node: 0
*/
