#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 110;

int n;
ll a[N], b[N];

int main() 
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    int i = 1, cnt = 0;
    while (b[i] > 0)
    {
        b[i]--;
        cnt++;
        if (!b[i]) i++;
    }
    if (cnt % 2) puts("Alice");
    else puts("Bob");

    return 0;
}

