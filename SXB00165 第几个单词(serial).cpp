#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int cnt;
string s, w, wd[N];

signed main() {
    getline(cin, s);
    cin >> w;
    string t;
    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        if (c == ' ' || c == '.') {
            if (t.size()) {
                wd[++cnt] = t;
                t = "";
            }
        } else {
            t += c;
        }
    }
    if (t.size()) {
        wd[++cnt] = t;
    }
    int ans = 0;
    for (int i = 1; i <= cnt; i++) {
        if (wd[i] == w && !ans) {
            ans = i;
        }
    }
    if (!ans) {
        for (int i = 1; i <= cnt; i++) {
            ans += wd[i].size();
        }
    }
    cout << ans << "\n";
    return 0;
}
