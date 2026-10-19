#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

long long a, b, n;
map<long long, int> p;
string s;

inline void input() {
    cin >> a >> b >> n;
}

inline void solve() {
    long long r = a % b, c = 0;
    int st = -1;
    p.clear();
    s.clear();
    while (r && c < n) {
        if (p.count(r)) {
            st = p[r];
            break;
        }
        p[r] = (int)c;
        s += char('0' + r * 10 / b);
        r = r * 10 % b;
        c++;
    }
    if (!r) {
        cout << (c <= n ? -1 : 0) << "\n";
        return;
    }
    if (st < 0) {
        cout << 0 << "\n";
        return;
    }
    cout << s.substr(st) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
