#include <bits/stdc++.h>
using namespace std;

signed main() {
    string s, t, best;
    getline(cin, s);
    if (!s.empty() && s[s.size() - 1] == '.') {
        s[s.size() - 1] = ' ';
    }
    stringstream ss(s);
    for (; ss >> t;) {
        if (t.size() > best.size()) {
            best = t;
        }
    }
    cout << best << "\n";
    return 0;
}
