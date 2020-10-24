#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[10010];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i] = i;

    int hh = 1, tt = n;
    int cnt = 1;
    while (hh <= tt)
    {
        if (cnt == m)
        {
            cout << a[hh] << ' ';
            hh++;
            cnt = 1;
        }
        else 
        {
            cnt++;
            a[++tt] = a[hh];
            hh++;
        }
    }

    return 0;
}