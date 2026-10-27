#include <bits/stdc++.h>
using namespace std;

int occ[105];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c, f, t;
        cin >> c >> f >> t;
        for (int s = f; s < t; s++) {
            occ[s] += c;
        }
    }
    int c, f, t;
    cin >> c >> f >> t;
    bool ok = true;
    for (int s = f; s < t; s++) {
        if (occ[s] + c > 12) {
            ok = false;
        }
    }
    if (ok) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
    return 0;
}
