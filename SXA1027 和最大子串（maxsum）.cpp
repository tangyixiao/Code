#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) {
        return 0;
    }
    string line, all;
    while (getline(cin, line)) {
        all += line;
        all += ' ';
    }
    for (size_t i = 0; i < all.size(); i++) {
        if (all[i] == ',') {
            all[i] = ' ';
        }
    }
    stringstream ss(all);
    long long x, cur = 0, best = LLONG_MIN;
    for (; ss >> x;) {
        if (cur < 0) {
            cur = 0;
        }
        cur += x;
        if (cur > best) {
            best = cur;
        }
    }
    cout << best << "\n";
    return 0;
}
