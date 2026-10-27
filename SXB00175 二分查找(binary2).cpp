#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, x, a[N];

int find(int l, int r) {
    if (l > r) {
        return -1;
    }
    int mid = (l + r) / 2;
    if (a[mid] == x) {
        return mid;
    }
    if (a[mid] > x) {
        return find(l, mid - 1);
    }
    return find(mid + 1, r);
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
    cout << find(1, n) << "\n";
    return 0;
}
