#include <bits/stdc++.h>
using namespace std;

signed main() {
    string s, a, b;
    getline(cin, s);
    getline(cin, a);
    getline(cin, b);
    string r, w;
    for (int i = 0; i <= (int)s.size(); i++) {
        if (i == (int)s.size() || s[i] == ' ') {
            if (!r.empty()) {
                r += " ";
            }
            if (w == a) {
                r += b;
            } else {
                r += w;
            }
            w.clear();
        } else {
            w += s[i];
        }
    }
    cout << r << "\n";
    return 0;
}
