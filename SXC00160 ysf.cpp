#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, f[N], lg[N];
long long k;

void add(int x, int v) {
    for (; x <= n; x += x & -x) {
        f[x] += v;
    }
}

int kth(int x) {
    int p = 0, s = 0;
    for (int i = lg[n]; i >= 0; i--) {
        if (p + (1 << i) <= n && s + f[p + (1 << i)] < x) {
            p += (1 << i), s += f[p];
        }
    }
    return p + 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 1; i <= n; i++) {
        add(i, 1);
    }
    int cur = 0, sz = n;
    for (int i = 1; i <= n; i++) {
        cur = (int)((cur + k - 1) % sz);
        int p = kth(cur + 1);
        cout << p << " ";
        add(p, -1), sz--;
    }
    cout << "\n";
    return 0;
}
