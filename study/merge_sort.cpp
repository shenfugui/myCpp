#include <bits/stdc++.h>

using namespace std;

const int N = 10e6+10;

int n;

int arr[N], tmp[N];

void merge_sort(int arr[], int l, int r);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    merge_sort(arr, 0, n-1);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}

void merge_sort(int arr[], int l, int r) {
    if (l >= r) return;
    int mid = (l+r)/2;
    int i = l, j = mid+1, k = 0;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, r);
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= r) tmp[k++] = arr[j++];
    for (int i = l, j = 0; i <= r; i++, j++) arr[i] = tmp[j];
}