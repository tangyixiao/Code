#include <bits/stdc++.h>
using namespace std;

double s;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    if (s >= 92.8) {
        cout << "jin" << "\n";
    } else if (s >= 85.6) {
        cout << "yin" << "\n";
    } else if (s >= 82.1) {
        cout << "tong" << "\n";
    } else {
        cout << "sorry" << "\n";
    }
    return 0;
}
