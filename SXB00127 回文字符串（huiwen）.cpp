#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, i, c, r, ans;
int p[N];
string s, t;
signed main() {
    cin >> s;
    n = (int)s.size();
    t = "^";
    for (i = 0; i < n; i++) {
        t += "#";
        t += s[i];
    }
    t += "#$";
    m = (int)t.size();
    c = 0, r = 0;
    for (i = 1; i < m - 1; i++) {
        if (r > i) {
            p[i] = min(r - i, p[2 * c - i]);
        } else {
            p[i] = 1;
        }
        for (; t[i + p[i]] == t[i - p[i]];) {
            p[i]++;
        }
        if (i + p[i] > r) {
            c = i, r = i + p[i];
        }
        if (p[i] - 1 > ans) {
            ans = p[i] - 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
