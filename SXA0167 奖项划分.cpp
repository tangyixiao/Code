#include <bits/stdc++.h>
using namespace std;

int n, m, s;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    s = n + m;
    if (n > 100 || m > 100) {
        cout << "-1" << "\n";
    } else if (n == 100 && m == 100) {
        cout << "Top1" << "\n";
    } else if (n >= 90 && m >= 90) {
        cout << "Gold" << "\n";
    } else if (n >= 80 && n < 90 && m >= 80 && m < 90) {
        cout << "Silver" << "\n";
    } else if (s >= 140 && s < 160 && n >= 60 && m >= 60) {
        cout << "Bronze" << "\n";
    } else {
        cout << "-1" << "\n";
    }
    return 0;
}
