#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

struct node {
    int a, b;
} c[N];

int n, la, lb;
string s;

inline string mul(string x, int y) {
    string r;
    int t = 0;
    for (int i = x.size() - 1; i >= 0; i--) {
        int v = (x[i] - '0') * y + t;
        r = char(v % 10 + '0') + r, t = v / 10;
    }
    while (t) {
        r = char(t % 10 + '0') + r, t /= 10;
    }
    return r;
}

inline string div(string x, int y) {
    string r;
    int t = 0;
    for (int i = 0; i < x.size(); i++) {
        t = t * 10 + x[i] - '0';
        if (t >= y || r.size()) {
            r += char(t / y + '0'), t = t % y;
        }
    }
    while (r.size() > 1 && r[0] == '0') {
        r.erase(0, 1);
    }
    return r;
}

inline bool ge(string x, string y) {
    if (x.size() != y.size()) {
        return x.size() > y.size();
    }
    return x >= y;
}

inline void input() {
    cin >> n;
    cin >> la >> lb;
    for (int i = 1; i <= n; i++) {
        cin >> c[i].a >> c[i].b;
    }
}

inline void solve() {
    sort(c + 1, c + n + 1, [](node x, node y) {
        return (long long)x.a * x.b < (long long)y.a * y.b;
    });
    string ans = "0";
    s = mul("1", la);
    for (int i = 1; i <= n; i++) {
        string t = div(s, c[i].b);
        if (ge(t, ans)) {
            ans = t;
        }
        s = mul(s, c[i].a);
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}