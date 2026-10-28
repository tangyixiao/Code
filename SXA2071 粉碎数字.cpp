#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, v, c[11];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v;
        if (v == 0) {
            c[0]++;
        }
        while (v > 0) {
            c[v % 10]++;
            v /= 10;
        }
    }
    for (int d = 9; d >= 0; d--) {
        for (int t = 0; t < c[d]; t++) {
            cout << d;
        }
    }
    cout << "\n";
    return 0;
}
