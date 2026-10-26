#include <bits/stdc++.h>
using namespace std;
long long lg(long long x) {
    long long k = 0, p = 1;
    while (p < x) {
        p *= 2, k++;
    }
    return k;
}
signed main() {
    int t, i;
    cin >> t;
    for (i = 1; i <= t; i++) {
        long long L, W, H;
        cin >> L >> W >> H;
        cout << L * W * H - 1 << " " << lg(L) + lg(W) + lg(H) << "\n";
    }
    return 0;
}
