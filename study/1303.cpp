#include <iostream>
#include <vector>

using namespace std;

int main() {
    int c[50001];
    string a, b;
    cin >> a >> b;
    vector<int> A, B, C;

    for (int i = 0; i < a.size(); i++) A.push_back(a[i] - '0');
    for (int i = 0; i < b.size(); i++) B.push_back(b[i] - '0');

    for (int i = 0; i < A.size(); i++) 
        for (int j = 0; j < B.size(); j++) 
            c[i + j] += A[i] * B[j];

    for (int i = 0; i < (A.size() + B.size() - 1) / 2; i++) swap(c[i], c[A.size() + B.size() - 2 - i]);

    for (int i = 0; i < A.size() + B.size() - 1; i++) {
        if (c[i] / 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }

    for (int i = 0; i < A.size() + B.size() - 1; i++) C.push_back(c[i]);

    if (a == "0" || b == "0") cout << 0 << endl;
    else for (int i = C.size() - 1; i >= 0; i--) cout << C[i];

    return 0;
}

