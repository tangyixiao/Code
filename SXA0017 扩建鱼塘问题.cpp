#include <bits/stdc++.h>
using namespace std;

int m, n;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    cout << max(m, n) * max(m, n) - m * n << "\n";
    return 0;
}
