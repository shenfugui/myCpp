#include <bits/stdc++.h>

using namespace std;

const int N = 50010;

int z[N][30];
char s[N], ce;
int n, a, b, c, d, len;

int main()
{
    while (1)
    {
        ce = getchar();
        if (ce == '\n')
            break;
        s[++len] = ce;
    } 
    for (int i = 1; i <= len; i++)
    {
        for (int j = 0; j <= 25; j++)
        {
            if (s[i] == 'a' + j)
                z[i][j] = z[i - 1][j] + 1;
            else
                z[i][j] = z[i - 1][j];
        }
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        bool flag = false;
        cin >> a >> b >> c >> d;
        for (int j = 0; j <= 25; j++)
        {
            if (z[b][j] - z[a - 1][j] != z[d][j] - z[c - 1][j])
            {
                cout << "NE" << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "DA" << endl;
    }

    return 0;
}