#include <iostream>
#include <stdio.h>

using namespace std;

const int N = 500010;

int n, a[N], tmp[N];

long long merge_sort(int a[], int l, int r) {
    if (l >= r) return 0;
    
    int mid = l + r >> 1;
    
    long long count = merge_sort(a, l, mid) + merge_sort(a, mid+1, r);
    
    int i = l, j = mid+1, k = 0;
    
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else {
            count += mid - i + 1;
            tmp[k++] = a[j++];
        }
    }
    
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    
    for (int i = l, j = 0; i <= r; i++, j++) a[i] = tmp[j];
    
    return count;
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    long long count = merge_sort(a, 0, n-1);
    
    cout << count << endl;
    
    return 0;
}