#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int a[N], s[N], w[N]; //编号 分数 实力值
int win[N], lose[N];

bool cmp(int x, int y) {
    if (s[x] == s[y]) return x < y;
    return s[x] > s[y];
}

void merge_sort() {
    int i, j;
    i = j = 1;
    a[0] = 0;

    while (i <= win[0] && j <= lose[0]) {
        if (cmp(win[i], lose[j])) a[++a[0]] = win[i++];
        else a[++a[0]] = lose[j++];
    }
    while (i <= win[0]) a[++a[0]] = win[i++];
    while (j <= lose[0]) a[++a[0]] = lose[j++];
}

int main() {
    int n, r, q;
    cin >> n >> r >> q;
    n *= 2;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) a[i] = i;

    sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= r; i++) {
        win[0] = lose[0] = 0;
        for (int j = 1; j <= n; j += 2) {
            if (w[a[j]] > w[a[j + 1]]) {
                s[a[j]]++;
                win[++win[0]] = a[j];
                lose[++lose[0]] = a[j + 1];
            } else {
                s[a[j + 1]]++;
                win[++win[0]] = a[j + 1];
                lose[++lose[0]] = a[j];
            }
        }

        merge_sort();
    }

    cout << a[q];

    return 0;
}