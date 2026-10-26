#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j > 1) {
                cout << " ";
            }
            cout << min(n - i + 1, n - j + 1);
        }
        cout << "\n";
    }
    return 0;
}
