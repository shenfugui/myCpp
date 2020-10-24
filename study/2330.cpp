#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;

int n, m;
int p[N];
int res = 0, cnt = 0;

struct Edge {
    int u, v, c;

    bool operator< (const Edge &C) const { return c < C.c; }
} edges[M];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal() {
    sort(edges, edges + m);

    for (int i = 1; i <= n; i++) p[i] = i;

    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, c = edges[i].c;

        u = find(u), v = find(v);

        if (u != v) {
            p[u] = v;
            res = res > c ? res : c;
            cnt++;
        }
    }

    if (cnt < n - 1) return INF;
    return res;
}

int main() {
    int u, v, c;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &c);
        edges[i] = {u, v, c};
    }

    int t = kruskal();
    if (t != INF)
        printf("%d %d", cnt, res);

    return 0;
}