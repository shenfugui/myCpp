#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int l[N], r[N];
int n, m, k, p, x;

int main()
{
    l[1] = r[0] = 1;
    
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> k >> p;
        if (!p)
        {
            l[i] = l[k], r[i] = k;
            r[l[k]] = l[k] = i;
        }
        else
        {
            l[i] = k, r[i] = r[k];
            l[r[k]] = r[k] = i;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) 
    {
        cin >> x;
        l[r[x]] = l[x];
        r[l[x]] = r[x];
    }

    int i = 0;
    while (r[i] != 0) 
    {
        cout << r[i] << ' ';
        i++;
    }

    return 0;
}