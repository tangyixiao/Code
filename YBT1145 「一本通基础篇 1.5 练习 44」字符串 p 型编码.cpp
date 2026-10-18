#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
char s[N];

inline void input() {
    cin >> s;
    return;
}

inline void solve() {
    int n = strlen(s);
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && s[j] == s[i]) {
            j++;
        }
        cout << j - i << s[i], i = j;
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}