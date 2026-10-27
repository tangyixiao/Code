#include <bits/stdc++.h>
using namespace std;

signed main() {
    string s, l, r;
    cin >> s;
    int p = s.find('='), f = 0;
    l = s.substr(0, p);
    r = s.substr(p + 1);
    long long b = 0;
    for (int i = 0; i < (int)r.size(); i++) {
        b = b * 10 + (r[i] - '0');
    }
    for (int i = 1; i < (int)l.size(); i++) {
        long long x = 0, y = 0;
        for (int j = 0; j < i; j++) {
            x = x * 10 + (l[j] - '0');
        }
        for (int j = i; j < (int)l.size(); j++) {
            y = y * 10 + (l[j] - '0');
        }
        if (x + y == b) {
            cout << l.substr(0, i) << "+" << l.substr(i) << "=" << r << "\n";
            f = 1;
        }
    }
    if (!f) {
        cout << "Impossible!" << "\n";
    }
    return 0;
}
