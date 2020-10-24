#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;

int main() {
    int n, m;
    cin >> n >> m;
    int a[N];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int q[N], hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        if (i - m + 1 > 0) {
            q[++tt] = a[i];
        }
        while (hh - tt <= m) hh++;
        while (hh <= tt && q[i] >= a[i]) tt--;
    }
}