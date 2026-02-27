#include <bits/stdc++.h>
using namespace std;
int n, a[114514], b[114514];
inline void SelectionSort(int l, int r) {
    for (int i = l; i <= r; i++) {
        int minIndex = i;
        for (int j = i + 1; j <= r; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
    return;
}
inline void BubbleSort(int l, int r) {
    for (int i = l; i <= r; i++) {
        for (int j = l; j < r - i + 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
    return;
}
inline void InsertionSort(int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        int temp = a[i];
        int j = i - 1;
        while (j >= l && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    return;
}
inline void MergeSort(int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        MergeSort(l, mid);
        MergeSort(mid + 1, r);
        int i = l, j = mid + 1, k = l;
        while (i <= mid && j <= r) {
            if (a[i] <= a[j]) {
                b[k++] = a[i++];
            } else {
                b[k++] = a[j++];
            }
        }
        while (i <= mid) {
            b[k++] = a[i++];
        }
        while (j <= r) {
            b[k++] = a[j++];
        }
        for (int i = l; i <= r; i++) {
            a[i] = b[i];
        }
    }
    return;
}
inline void QuickSort(int l, int r) {
    if (l < r) {
        int pivot = a[l];
        int i = l, j = r;
        while (i < j) {
            while (i < j && a[j] >= pivot) {
                j--;
            }
            a[i] = a[j];
            while (i < j && a[i] < pivot) {
                i++;
            }
            a[j] = a[i];
        }
        a[i] = pivot;
        QuickSort(l, i - 1);
        QuickSort(i + 1, r);
    }
    return;
}
inline void CountingSort(int l, int r) {
    int maxNum = *max_element(a + l, a + r + 1);
    int count[maxNum + 1] = {0};
    for (int i = l; i <= r; i++) {
        count[a[i]]++;
    }
    for (int i = 1; i <= maxNum; i++) {
        count[i] += count[i - 1];
    }
    int b[r - l + 1];
    for (int i = r; i >= l; i--) {
        b[--count[a[i]]] = a[i];
    }
    for (int i = l; i <= r; i++) {
        a[i] = b[i - l];
    }
    return;
}
inline void RadixSort(int l, int r) {
    int maxNum = *max_element(a + l, a + r + 1);
    int Exp_ = 1;
	
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}