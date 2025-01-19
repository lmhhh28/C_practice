#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

#define ll long long

using namespace std;

inline int read() {
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}

const int N = 50005, M = 200003;

struct Edge {
    int next, to;
    double weight;
};

struct Graph {
    int total, head[N];
    Edge edges[M];

    void add(int x, int y, double z) {
        edges[++total] = {head[x], y, z};
        head[x] = total;
    }
} G, R;

int n, m, result = 0;
double energy;

struct Node {
    int id;
    double distance;
    bool operator<(const Node &other) const {
        return distance > other.distance;
    }
};

int visited[N], parent[N];
double distances[N];

void dijkstra() {
    priority_queue<Node> pq;
    pq.push({n, 0});
    memset(distances, 127, sizeof(distances));
    distances[n] = 0;

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (visited[current.id]) continue;
        visited[current.id] = 1;

        for (int i = R.head[current.id]; i; i = R.edges[i].next) {
            Node next = {R.edges[i].to, current.distance + R.edges[i].weight};
            if (distances[next.id] > next.distance) {
                distances[next.id] = next.distance;
                parent[next.id] = i;
                pq.push(next);
            }
        }
    }
}

int sequence[N], root[N];

bool compare(const int x, const int y) {
    return distances[x] < distances[y];
}

struct HeapNode {
    int left, right, distance, parent;
    double key;
} heap[21 * N];

int heapCount = 0;

int createHeapNode(int parent, double value) {
    int index = ++heapCount;
    heap[index] = {0, 0, 0, parent, value};
    return index;
}

int mergeHeaps(int x, int y) {
    if (!x || !y) return x + y;
    if (heap[x].key > heap[y].key) swap(x, y);

    int index = ++heapCount;
    heap[index] = heap[x];
    heap[index].right = mergeHeaps(heap[index].right, y);

    if (heap[heap[index].left].distance < heap[heap[index].right].distance)
        swap(heap[index].left, heap[index].right);

    heap[index].distance = heap[heap[index].right].distance + 1;
    return index;
}

struct Path {
    int node;
    double cost;
    bool operator<(const Path &other) const {
        return cost > other.cost;
    }
};

int main() {
    n = read();
    m = read();
    scanf("%lf", &energy);

    for (int i = 1; i <= m; i++) {
        int x = read(), y = read();
        double z;
        scanf("%lf", &z);

        if (x == n) {
            i--;
            m--;
            continue;
        }

        G.add(x, y, z);
        R.add(y, x, z);
    }

    dijkstra();

    for (int i = 1; i <= n; i++) sequence[i] = i;
    sort(sequence + 1, sequence + n + 1, compare);

    heap[0].distance = -1;

    for (int i = 1; i <= n; i++) {
        int u = sequence[i];
        for (int j = G.head[u]; j; j = G.edges[j].next) {
            if (parent[u] != j)
                root[u] = mergeHeaps(root[u], createHeapNode(G.edges[j].to, G.edges[j].weight + distances[G.edges[j].to] - distances[u]));
        }
        root[u] = mergeHeaps(root[u], root[G.edges[parent[u]].to]);
    }

    priority_queue<Path> pq;

    if (energy - distances[1] < 0) {
        printf("0\n");
        return 0;
    }

    energy -= distances[1];
    result++;

    if (root[1]) pq.push({root[1], heap[root[1]].key});

    while (!pq.empty()) {
        Path current = pq.top();
        pq.pop();

        if (energy - (current.cost + distances[1]) < 0) break;

        energy -= current.cost + distances[1];
        result++;

        if (heap[current.node].left)
            pq.push({heap[current.node].left, current.cost - heap[current.node].key + heap[heap[current.node].left].key});

        if (heap[current.node].right)
            pq.push({heap[current.node].right, current.cost - heap[current.node].key + heap[heap[current.node].right].key});

        if (root[heap[current.node].parent])
            pq.push({root[heap[current.node].parent], current.cost + heap[root[heap[current.node].parent]].key});
    }

    printf("%d\n", result);
    return 0;
}
