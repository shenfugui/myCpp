#include <bits/stdc++.h>

using namespace std;

const int N = 510, INF = 1e9;

int p, f, c;
int d[N][N];    //储存通过到达另外一个牧场所需要的时间
int idx[N];     //储存贝茜喜欢牧场的编号

/*
 * floyd的模板
 */

void floyd() {
    for (int k = 1; k <= p; k++) 
        for (int i = 1; i <= p; i++) 
            for (int j = 1; j <= p; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
    scanf("%d%d%d", &p, &f, &c);
    
    //初始化
    for (int i = 1; i <= p; i++) 
        for (int j = 1; j <= p; j++) 
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;

    for (int i = 1; i <= f; i++) scanf("%d", &idx[i]);

    
    for (int i = 1; i <= c; i++) {
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        d[a][b] = min(d[a][b], t);
        d[b][a] = d[a][b];
    }

    floyd();

    int sum = 0, res = INF, cnt;
    for (int i = 1; i <= p; i++) {
        sum = 0;
        for (int j = 1; j <= f; j++) {
            sum += d[i][idx[j]];
        }
        if (sum < res) res = sum, cnt = i;
    }

    printf("%d\n", cnt);

    return 0;
}