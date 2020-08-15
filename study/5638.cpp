#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int main()
{
    int n, k;
    cin >> n >> k;
    long long a[N], b[N];
    for (int i = 1; i < n; i++) 
    {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }

    long long len, max = 0, t;
    if (k != 0)
        for (int i = 1; i + k <= n; i++)
        {
            len = b[i + k - 1] - b[i - 1];
            max = max > len ? max : len;
        }
    t = b[n - 1] - max;
    cout << t;

    return 0;
}
