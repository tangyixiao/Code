#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k, f[N];

void add(int x, int v) {
    for (; x <= n; x += x & -x) {
        f[x] += v;
    }
}

int kth(int k) {
    int pos = 0, step = 1;
    for (; (step << 1) <= n;) {
        step <<= 1;
    }
    for (; step; step >>= 1) {
        if (pos + step <= n && f[pos + step] < k) {
            pos += step;
            k -= f[pos];
        }
    }
    return pos + 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        add(i, 1);
    }
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur = (cur + k - 1) % (n - i + 1);
        int p = kth(cur + 1);
        cout << p << " ";
        add(p, -1);
    }
    cout << "\n";
    return 0;
}
