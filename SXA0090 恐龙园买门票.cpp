#include <bits/stdc++.h>
using namespace std;

double h;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h;
    if (h < 1.3) {
        cout << 60 << "\n";
    } else {
        cout << 120 << "\n";
    }
    return 0;
}
