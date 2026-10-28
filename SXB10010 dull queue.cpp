#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, k, a[N], q[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int h = 0, t = 0, f = 0;
    for (int i = 1; i <= n; i++) {
        for (; h < t && a[q[t - 1]] <= a[i];) {
            t--;
        }
        q[t++] = i;
        for (; q[h] <= i - k;) {
            h++;
        }
        if (i >= k) {
            if (f) {
                cout << " ";
            }
            cout << a[q[h]];
            f = 1;
        }
    }
    cout << "\n";
    return 0;
}
