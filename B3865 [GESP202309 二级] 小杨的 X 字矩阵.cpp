#include <bits/stdc++.h>
using namespace std;
int n;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == i || j == n - i + 1) {
                cout << "+";
            } else {
                cout << "-";
            }
        }
        cout << "\n";
    }
    return 0;
}