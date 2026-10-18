#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5;
int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++) {
        q.push(a[i]);
    }
    long long ans = 0;
    while (q.size() > 1) {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        ans += x + y, q.push(x + y);
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input(), solve();
    return 0;
}