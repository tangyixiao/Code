#include <bits/stdc++.h>
using namespace std;

const int N = 35 + 5;
char s[N];

inline void input() {
    cin >> s;
    return;
}

inline void solve() {
    int n = strlen(s);
    const char *b[3] = {"er", "ly", "ing"};
    for (int i = 0; i < 3; i++) {
        int l = strlen(b[i]);
        if (n > l && strcmp(s + n - l, b[i]) == 0) {
            s[n - l] = 0;
            break;
        }
    }
    cout << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}