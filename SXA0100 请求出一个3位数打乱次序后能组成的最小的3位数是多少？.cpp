#include <bits/stdc++.h>
using namespace std;

int d[3];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    d[0] = n / 100;
    d[1] = n / 10 % 10;
    d[2] = n % 10;
    int best = 1e9;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i == j || j == k || i == k) {
                    continue;
                }
                if (d[i] == 0) {
                    continue;
                }
                int v = d[i] * 100 + d[j] * 10 + d[k];
                if (v < best) {
                    best = v;
                }
            }
        }
    }
    cout << best << "\n";
    return 0;
}
