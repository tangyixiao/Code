#include <bits/stdc++.h>
using namespace std;

int X, A, B, ans;

signed main() {
    cin >> X >> A >> B;
    for (int a = 1; a * A < X; a++) {
        int t = X - a * A;
        if (t % B == 0 && t / B >= 1) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
