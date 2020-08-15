#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;
    int a[n];
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        r += a[i];
        l = l > a[i] ? l : a[i];
    }

    while (l < r) 
    {
        int mid = l + r >> 1;
        if (check(mid)) 
    }
}