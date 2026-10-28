#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a[N];
long long k, s;

void rd() {
    freopen("xmul.in", "r", stdin);
}

void wr() {
    freopen("xmul.out", "w", stdout);
}

signed main() {
    rd(), wr();
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s ^= a[i];
        }
        bool same = (n % 2 == 0 && k % 2 == 0);
        for (int i = 0; i < n; i++) {
            long long v;
            if (same) {
                v = a[i];
            } else {
                v = s ^ a[i];
            }
            cout << v;
            if (i + 1 < n) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
