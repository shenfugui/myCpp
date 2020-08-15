#include <iostream>

using namespace std;

const int N = 100010;

int n;
int a[N];

int main() {
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < i; j++)
            if (a[j] > a[i]) count++;

    cout << count << endl;

    return 0;
}