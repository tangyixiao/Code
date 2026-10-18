#include <bits/stdc++.h>
using namespace std;

const int N = 200 + 5;
int M, n, w, c, f[N];

signed main() {
    cin >> M >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w >> c;
        for (int j = M; j >= w; j--) {
            f[j] = max(f[j], f[j - w] + c);
        }
    }
    cout << f[M] << "\n";
    return 0;
}