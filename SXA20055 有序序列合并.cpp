#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int a[N], b[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int i = 0, j = 0, first = 1;
    for (; i < m || j < n;) {
        int x;
        if (j >= n || (i < m && a[i] <= b[j])) {
            x = a[i++];
        } else {
            x = b[j++];
        }
        if (!first) {
            cout << ' ';
        }
        first = 0;
        cout << x;
    }
    cout << "\n";
    return 0;
}
