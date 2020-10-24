#include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = 1010;

struct Edge {
    int u, v;
    double w;

    bool operator< (const Edge &W) const { return w < W.w; }
} edges[N * N];

int n, m;
int p[N];
double res = 0;
int cnt = 0;

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

double kruskal() {
    sort(edges + 1, edges + cnt + 1);

    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= cnt; i++) {
        int u = edges[i].u, v = edges[i].v;
        double w = edges[i].w;
        u = find(u), v = find(v);

        if (u != v) {
            p[u] = v;
            res += w;
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    int x[N], y[N];
    for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
    for (int i = 1; i <= n; i++) 
        for (int j = i + 1; j <= n; j++) {
            double w = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            edges[++cnt] = {i, j, w};
        }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[++cnt] = {u, v, 0};
    }

    printf("%.2lf", kruskal());

    return 0;

}