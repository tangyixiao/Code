#include <bits/stdc++.h>
using namespace std;
const int N = 2e1 + 5;
int a[N], b[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l1, r1, l2, r2;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    cin >> l1 >> r1 >> l2 >> r2;
    for (int i = 0; i <= r1 - l1; i++) {
        a[l1 + i] = b[l2 + i];
        a[l2 + i] = b[l1 + i];
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
