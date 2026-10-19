#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n;
int a[N], st[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    int t = 0, p = 1, i = 1;
    while (p <= n || t > 0) {
        if (t == 0 && i <= n) {
            st[++t] = p++;
            continue;
        }
        if (i > n && st[t] != a[i]) {
            cout << "NO\n";
            return 0;
        }
        while (t > 0 && st[t] == a[i]) {
            t--, i++;
        }
        if (i > n && t == 0) {
            break;
        }
        if (t > 0 && st[t] != a[i] && p <= n) {
            st[++t] = p++;
        }
    }
    cout << "YES\n";
    return 0;
}