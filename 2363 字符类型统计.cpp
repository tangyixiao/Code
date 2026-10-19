#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

char s[N];

inline void input() {
    cin.getline(s, sizeof(s));
}

inline void solve() {
    input();
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            a++;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            b++;
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            c++;
        } else if (s[i] == ' ') {
            d++;
        } else {
            e++;
        }
    }
    cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}