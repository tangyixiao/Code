#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;

char s1[N], s2[N];

inline void input() {
    cin >> s1 >> s2;
}

inline void solve() {
    string a = s1, b = s2;
    if (b.find(a) != string::npos) {
        cout << a << " is substring of " << b << "\n";
    } else if (a.find(b) != string::npos) {
        cout << b << " is substring of " << a << "\n";
    } else {
        cout << "No substring" << "\n";
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