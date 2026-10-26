#include <bits/stdc++.h>
using namespace std;

int n, x, odd, even;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x % 2 != 0) {
            odd++;
        } else {
            even++;
        }
    }
    cout << odd << " " << even << "\n";
    return 0;
}
