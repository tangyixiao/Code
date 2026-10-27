#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int a[N];

signed main() {
    int m, n, k;
    cin >> m >> n >> k;
    int len = n - m + 1;
    for (int i = 0; i < len; i++) {
        a[i] = m + i;
    }
    for (int t = 0; t <= k; t++) {
        for (int i = 0; i < len; i++) {
            int p = (t + i) % len;
            if (i > 0) {
                cout << " ";
            }
            cout << a[p];
        }
        cout << "\n";
    }
    return 0;
}
