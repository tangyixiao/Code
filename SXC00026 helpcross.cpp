#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int c, n, i, ans, t, p;
int ct[N], a[N], b[N], hp[N];

bool cmp(int x, int y) {
    return a[x] < a[y];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> n;
    for (i = 1; i <= c; i++) {
        cin >> ct[i];
    }
    for (i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        hp[i] = i;
    }
    sort(ct + 1, ct + c + 1);
    sort(hp + 1, hp + n + 1, cmp);
    priority_queue<int, vector<int>, greater<int>> pq;
    p = 1;
    for (i = 1; i <= c; i++) {
        t = ct[i];
        for (; p <= n && a[hp[p]] <= t; p++) {
            pq.push(b[hp[p]]);
        }
        for (; !pq.empty() && pq.top() < t;) {
            pq.pop();
        }
        if (!pq.empty()) {
            pq.pop();
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
