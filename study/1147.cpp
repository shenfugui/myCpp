#include <bits/stdc++.h>

using namespace std;

int m;

int main() 
{
    cin >> m;

    //(ai + aj) * (j - i + 1) / 2
    long long x;
    for (int i = 1, j = 2; j < m;) 
    {
        x = (i + j) * (j - i + 1) / 2;
        if (x == m) 
        {
            cout << i << ' ' << j << endl;
            i++;
        }
        else if (x > m) i++, j--;
        else j++;
    }

    return 0;
}