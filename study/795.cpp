#include <iostream>

using namespace std;

const int N = 10e5+10;
int n, m;
int a[N], s[N];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l-1] << endl;
    }

    return 0;
}