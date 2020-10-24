#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int n, k;
int a[N], path[N];
bool st[N];
int sum, cnt;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) 
        if (!(n % i)) return false;

    return true;
}

void dfs(int u) {
    if (u == k) {
        if (isPrime(sum)) cnt++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!st[i] && path[u - 1] < i) {
            path[u] = i;
            st[i] = true;
            sum += a[i];
            dfs(u + 1);
            sum -= a[i];
            st[i] = false;
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    dfs(0);
    cout << cnt << endl;

    return 0;
}