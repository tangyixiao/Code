#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int p[4] = {2, 3, 5, 7};
    for (int i = 0; i < 4; i++) {
        if (n % p[i] == 0) {
            cout << p[i] << "\n";
        }
    }
    return 0;
}
