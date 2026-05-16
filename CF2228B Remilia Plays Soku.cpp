#include <bits/stdc++.h>

using namespace std;

int t;
long long n, x1, x2, k, d;
main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> x1 >> x2 >> k;

        if (n <= 3) {
            cout << 1 << '\n';
        } else {
            cout << min(abs(x1 - x2), n - abs(x1 - x2)) + k << '\n';
        }
    }
    return 0;
}