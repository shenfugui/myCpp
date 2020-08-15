#include <iostream>
#include <vector>
#define LL long long

using namespace std;

const int N = 100010;

int main() {
    int n, c;
    LL X[N];
    for (int i = 0; i < n; i++) cin >> X[i];
    //define B[i] = X[i+1] - X[i];

    LL b[N];
    for (int i = 0; i < n; i++) b[i] = X[i + 1] - X[i];
}