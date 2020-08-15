#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int a[N];

int main() 
{
    int count = 0;
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a+n);

    for (int i = 0; i < n - 1; i++)
    {
        int l = i, r = n - 1;

        while (l < r) 
        {
            int mid = l + r >> 1;
            if (a[mid] - a[i] >= c) r = mid;
            else l = mid + 1;
        }
        if (a[l] - a[i] == c) 
        {
            count++;
            int j = l + 1;
            while (a[j++] == a[l]) count++;
        }
    }

    cout << count << endl;

    return 0;
}