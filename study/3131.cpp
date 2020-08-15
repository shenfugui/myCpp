#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 50010;

int n;
int a[N];
ll s[N];


int main() 
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    //x = s[r] - s[l - 1];
    int max = 0;
    for (int i = 1, j = 1; ;)
    {
        ll x = s[j] - s[i -1];
        if (!(x % 7)) 
        {
            max = max > j - i + 1 ? max : j - i + 1;
            j++;
        }
        else j++;
        if (max >= n - i + 1 || i >= n - i + 1) break;
        if (j >= n) i++, j = i;
    }

    cout << max << endl;
    
    return 0;
}