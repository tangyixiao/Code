#include <bits/stdc++.h>
using namespace std;

const int M = 5e6 + 5;
bool p[M];
int f[M];

signed main() {
    for (int i = 2; i * i < M; i++) {
        if (!p[i]) {
            for (int j = i * i; j < M; j += i) {
                p[j] = true;
            }
        }
    }
    for (int i = 1; i < M; i++) {
        int y = 0;
        for (int x = i; x; x /= 10) {
            y = y * 10 + x % 10;
        }
        f[i] = f[i - 1] + (!p[i] && i == y);
    }
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << f[n] - f[10] << "\n";
    }
    return 0;
}