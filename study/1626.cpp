#include <iostream>

using namespace std;

const int N = 100010;

long tmp[N];

void merge_sort(long a[], long l, long r) {
    if (l >= r) return;

    long mid = l + r >> 1;
    long i = l, j = mid+1, k = 1;
    
    merge_sort(a, l, mid), merge_sort(a, mid+1, r);
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];

    for (int i = l, j = 1; i <= r; i++, j++) a[i] = tmp[j];
}

int main() {
    long n, k, sum = 0;
    long a[N], b[N];

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    merge_sort(a, 1, n);
    for (int i = 1; i <= n-1; i++) b[i] = a[i+1] - a[i];
    merge_sort(b, 1, n-1);
    for (int i = 1; i <= k; i++) sum += b[i];

    cout << sum << endl;

    return 0;
}