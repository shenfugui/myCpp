#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int n, k;
long long int len, sum = 0;
long long int ll[N];

bool check(int x)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += ll[i] / x;
    }
    return s >= k;
}

int main() 
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) 
    {
        float m;
        scanf("%f", &m);
        ll[i] = m * 100;
        sum += ll[i];
    }

    long long int l = 0, r = sum;
    while (l < r)
    {
        long long int mid = (l + r) / 2;
        if (mid == 0) break;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }

    len = l;

    cout << fixed << setprecision(2) << (len / 1.0 / 100) << endl;

    return 0;
}