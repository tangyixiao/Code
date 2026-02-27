#include <bits/stdc++.h>
#define int long long
using namespace std;
int T, n;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                cout << i << " ";
                n /= i;
            }
        }
        if (n > 1)
            cout << n << " ";
        cout << "\n";
    }
    return 0;
}