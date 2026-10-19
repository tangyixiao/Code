#include <bits/stdc++.h>
using namespace std;

const int N = 25;
string s[N];
int n;

inline bool cmp(const string &a, const string &b) { return a + b > b + a; }

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n, cmp);
    return;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
