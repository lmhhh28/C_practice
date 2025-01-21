#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

int n;
int degree[MAXN];
int visited[MAXN];
int path[MAXN];
int pathIndex = 0;
int head[MAXN];
struct Edge {
    int to, next;
} edges[MAXN * 2];
int edgeCnt = 0;

void addEdge(int u, int v) {
    edges[edgeCnt] = (struct Edge){v, head[u]};
    head[u] = edgeCnt++;
    edges[edgeCnt] = (struct Edge){u, head[v]};
    head[v] = edgeCnt++;
    degree[u]++;
    degree[v]++;
}

void dfs(int u) {
    visited[u] = 1;
    for (int i = head[u]; i != -1; i = edges[i].next) {
        int v = edges[i].to;
        if (!visited[v]) {
            dfs(v);
        }
    }
    path[pathIndex++] = u;
}

int main() {
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    memset(degree, 0, sizeof(degree));

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    memset(visited, 0, sizeof(visited));
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("-1\n");
            return 0;
        }
    }
    int oddDegreeCount = 0, start = 1;
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 == 1) {
            oddDegreeCount++;
            start = i;
        }
    }

    if (oddDegreeCount != 0 && oddDegreeCount != 2) {
        printf("-1\n");
        return 0;
    }
    memset(visited, 0, sizeof(visited));
    pathIndex = 0;
    dfs(start);
    if (pathIndex != n) {
        printf("-1\n");
    } else {
        printf("%d %d\n", path[pathIndex - 1], path[0]);
    }

    return 0;
}