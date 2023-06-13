//Khushi Desai
//21BC264

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 5000

typedef struct {
    int u;
    int v;
    int weight;
} Edge;

int num_vertices, num_edges;
Edge edges[MAX_EDGES];
int parent[MAX_VERTICES];
int rank[MAX_VERTICES];

void make_set(int x) {
    parent[x] = x;
    rank[x] = 0;
}

int find_set(int x) {
    if (x != parent[x])
        parent[x] = find_set(parent[x]);
    return parent[x];
}

void union_sets(int x, int y) {
    int px = find_set(x);
    int py = find_set(y);

    if (px == py)
        return;

    if (rank[px] > rank[py])
        parent[py] = px;
    else if (rank[px] < rank[py])
        parent[px] = py;
    else {
        parent[py] = px;
        rank[px]++;
    }
}

int compare_edges(const void* a, const void* b) {
    Edge* ea = (Edge*)a;
    Edge* eb = (Edge*)b;
    return ea->weight - eb->weight;
}

void kruskal() {
    int mst_weight = 0;

    for (int i = 0; i < num_vertices; i++)
        make_set(i);

    qsort(edges, num_edges, sizeof(Edge), compare_edges);

    for (int i = 0; i < num_edges; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (find_set(u) != find_set(v)) {
            union_sets(u, v);
            printf("Edge (%d, %d) with weight %d added to the MST\n", u, v, w);
            mst_weight += w;
        }
    }

    printf("The weight of the minimum spanning tree is %d\n", mst_weight);
}

int main() {
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &num_vertices, &num_edges);

    printf("Enter the edges and their weights: ");
    for (int i = 0; i < num_edges; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);

    kruskal();

    return 0;
}
