#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, h[N], st[N], top;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
}

inline void solve() {
    long long ans = 0;
    for (int i = n; i >= 1; i--) {
        while (top > 0 && h[st[top]] < h[i]) {
            top--;
        }
        ans += (top > 0 ? st[top] : n + 1) - i - 1;
        st[++top] = i;
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