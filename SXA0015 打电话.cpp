#include <bits/stdc++.h>
using namespace std;

int n;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cout << fixed << setprecision(1) << (n <= 9 ? n * 1.5 : n * 1.2) << "\n";
    return 0;
}
