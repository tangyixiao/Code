#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
string s, a, b, w[N];
int cnt;

signed main() {
    getline(cin, s);
    getline(cin, a);
    getline(cin, b);
    int n = s.size();
    string t;
    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] == ' ') {
            if (t.size()) {
                w[++cnt] = t;
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    for (int i = 1; i <= cnt; i++) {
        if (i > 1) {
            cout << " ";
        }
        if (w[i] == a) {
            cout << b;
        } else {
            cout << w[i];
        }
    }
    cout << "\n";
    return 0;
}
