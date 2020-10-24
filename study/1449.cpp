#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str[1010];
    gets(str);
    int a[1010], b[1010];

    int i = 0, cnt = 0;
    while (str[i] != '@')
    {
        if (str[i] >= 0 && str[i] <= 9)
        {
            if (!(cnt % 2)) a[cnt] = str[i] - '0';
            else b[cnt] = str[i] - '0';
        }
        else if (str[i] == '-' || str[i] == '+' || str[i] == '*' || str[i] == '/')
        {
            int ans;
            if (str[i] == '-') ans = a[cnt] - b[cnt];
            else if (str[i] == '+') ans = a[cnt] + b[cnt];
            else if (str[i] == '*') ans = a[cnt] * b[cnt];
            // else if (str[i] == '/') ans = a[cnt] / b[cnt];
            b[cnt] = ans;
            
        }
    }

 
}