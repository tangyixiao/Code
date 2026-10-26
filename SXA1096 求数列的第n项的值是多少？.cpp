#include <bits/stdc++.h>
using namespace std;

int n, k;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (k = 1; (long long)k * (k + 1) / 2 < n; k++) {
    }
    cout << k << "\n";
    return 0;
}
