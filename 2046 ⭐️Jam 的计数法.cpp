#include <bits/stdc++.h>
using namespace std;

const int N = 3e1 + 5;

int l, t, w;
string s;

inline void input() {
    cin >> l >> t >> w;
    cin >> s;
}

inline bool nxt() {
    for (int i = w - 1; i >= 0; i--) {
        if (s[i] - 'a' + 1 + w - i > t) {
            continue;
        }
        s[i]++;
        for (int j = i + 1; j < w; j++) {
            s[j] = s[j - 1] + 1;
        }
        return true;
    }
    return false;
}

inline void solve() {
    for (int i = 1; i <= 5; i++) {
        if (!nxt()) {
            break;
        }
        cout << s << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
