#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 20010;

int n;
ll a[N], b[N], s[2 * N];
bool flag[2 * N];
ll ans = 0;

int find(int x)
{
    for (int i = 0; i < 2 * N; i++) if (x == s[i]) return i;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%lld %lld", &a[i], &b[i]);
    int m = 2 * n;
    for (int i = 0, j = 0; i < m;)
    {
        s[i++] = a[j];
        s[i++] = b[j++];
    }
    sort(s, s + m);
    for (int i = 0; i < n; i++)
    {
        a[i] = find(a[i]);
        b[i] = find(b[i]);
        for (int j = a[i]; j <= b[i]; j++)
        {
            flag[j] = true;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (flag[i]) ans += s[i + 1] - s[i];
    }

    cout << ans << endl;

    return 0;
}