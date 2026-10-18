#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;

int b;
char s1[N], s2[N], r[N];

inline int val(char c) {
    return (c <= '9' ? c - '0' : c - 'A' + 10);
}

inline char ch(int v) {
    return (v < 10 ? char('0' + v) : char('A' + v - 10));
}

inline void input() {
    cin >> b >> s1 >> s2;
}

inline void solve() {
    int n1 = strlen(s1), n2 = strlen(s2), n = max(n1, n2) + 2, c = 0, l = 0;
    for (int i = 0; i < n; i++) {
        int a = i < n1 ? val(s1[n1 - 1 - i]) : 0;
        int d = i < n2 ? val(s2[n2 - 1 - i]) : 0;
        int t = a + d + c;
        r[l] = ch(t % b), l++;
        c = t / b;
    }
    if (c) {
        r[l] = ch(c), l++;
    }
    while (l > 1 && r[l - 1] == '0') {
        l--;
    }
    for (int i = l - 1; i >= 0; i--) {
        cout << r[i];
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}