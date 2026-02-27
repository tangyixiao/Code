#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N = 1e6 + 5, base = 13331;
int a[N], power[N];
int get_hash(int l, int r) {
    return a[r] - a[l] * power[r - l];
}
string x;
int n, m;
signed main() {
    cin >> x >> n;
    m = x.size(), x = " " + x, power[0] = 1;
    for (int i = 1; i <= m; i++) {
        a[i] = a[i - 1] * base + x[i], power[i] = power[i - 1] * base;
    }
    for (int i = 1, l1, r1, l2, r2; i <= n; i++) {
        cin >> l1 >> r1 >> l2 >> r2;
        if (get_hash(l1, r1) == get_hash(l2, r2)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
