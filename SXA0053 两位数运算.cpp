#include <bits/stdc++.h>
using namespace std;

int n;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cout << fixed << setprecision(1) << (n / 10) * 1.0 / (n % 10) << "\n";
    return 0;
}
