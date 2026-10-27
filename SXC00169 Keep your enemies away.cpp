#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, i, j, l, r, mid, q, x, ans, last;
long long h, s, v;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> n;
    s = 0;
    for (i = 1; i <= n; i++) {
        cin >> v;
        s += v;
    }
    if (s >= h) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
