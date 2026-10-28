#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5, M = 1e3 + 5;
int n, x, mx, cnt[M];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cnt[x]++;
        mx = max(mx, cnt[x]);
    }
    int f = 0;
    for (int i = 1; i <= 1000; i++) {
        if (cnt[i] == mx) {
            if (f) {
                cout << " ";
            }
            cout << i;
            f = 1;
        }
    }
    cout << "\n";
    return 0;
}
