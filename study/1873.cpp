#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e9 + 10;

int h, m, n;
int a[N];

int main() 
{
    int sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];    
    
    sort(a, a + n);
    for (int i = 0; i < n; i++) 
    {
        int j = 0;
        h = a[j];
        if (a[i] - h > 0) sum += a[i] - h;
        if (i == n - 1 && sum > m)
        {
            i = 0;
            sum = 0;
            h = a[j++];
        }
        if (i == n - 1 && sum < m) 
        {
            h = a[j - 1];
            break;
        }
    }
    
    cout << h << endl;
    
    return 0;
}
