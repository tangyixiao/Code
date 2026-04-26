#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, a[N], b[N];
bool flag;
inline int step() {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        ret += (abs(a[i] - a[i + 1]) == 1 ? 0 : 1);
    }
    return ret;
}
inline void dfs(int s, int f, int pre) {
    if (flag) {
        return;
    }
    int num = step();
    if (num == 0) {
        flag = 1;
        return;
    }
    if (s + num > f)
        return;
    for (int i = 1; i <= n; i++) {
        if (i == pre)
            continue;
        reverse(a + 1, a + i + 1);
        dfs(s + 1, f, i);
        reverse(a + 1, a + i + 1);
    }
    return;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
    }
    a[n + 1] = n + 1;
    for (int i = 0;; i++) {
        dfs(0, i, 0);
        if (flag) {
            cout << i << "\n";
            exit(0);
        }
    }
    return 0;
}
