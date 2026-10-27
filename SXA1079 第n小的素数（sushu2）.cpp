#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int f[N], p[10005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, c = 0;
    for (int i = 2; i < N; i++) {
        if (!f[i]) {
            p[++c] = i;
            for (int j = i + i; j < N; j += i) {
                f[j] = 1;
            }
        }
    }
    cin >> n;
    cout << p[n] << "\n";
    return 0;
}
