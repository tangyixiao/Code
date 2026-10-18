#include <bits/stdc++.h>
using namespace std;

const int N = 6e2 + 5;

int n, w, c[N];

signed main() {
    cin >> n >> w;
    for (int p = 1; p <= n; p++) {
        int x;
        cin >> x;
        c[x]++;
        int k = max(1, p * w / 100), s = 0;
        for (int i = 600; i >= 0; i--) {
            s += c[i];
            if (s >= k) {
                cout << i << (p == n ? "\n" : " ");
                break;
            }
        }
    }
    return 0;
}
