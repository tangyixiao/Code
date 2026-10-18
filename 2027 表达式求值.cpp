#include <bits/stdc++.h>
using namespace std;

const int M = 1e4;

string s;

inline void input() {
    cin >> s;
}

inline void solve() {
    long long ans = 0, mul = 1, num = 0;
    int n = s.size();
    for (int i = 0; i <= n; i++) {
        if (i < n && s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + s[i] - '0';
        } else {
            mul = mul * (num % M) % M;
            num = 0;
            if (i == n || s[i] == '+') {
                ans = (ans + mul) % M, mul = 1;
            }
        }
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
