#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int n, m, c;
int s[N], d[N], q[N];
int e[N], h[N], ne[N], idx;

void add(int a, int b, int x) {
    e[idx] = x;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool topsort() {
    int hh = 0, tt = -1;

    for (int i = 1; i <= n; i++) if(!d[i]) q[++tt] = i;

    while (hh <= tt) {
        int t = q[hh++];

        for (int i = h[t]; i != -1; i = ne[i]) {
            if ()
        }
    }
}

int main() {
    cin >> n >> m >> c;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
    q[1] = s[1];
    for (int i = 2; i <= n; i++) {
        int a, b, x;
        scanf("%d%d%d", &a, &b, &x);
        if (s[i] >= q[a])
    }
}