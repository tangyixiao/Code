#include <bits/stdc++.h>
using namespace std;
int n, x, y;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x >> y;
    cout << n - ceil(y * 1.0 / x);
    return 0;
}