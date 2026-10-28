#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, c[N], d[N];
long long best, val[N];
int bk;

void rd() {
    freopen("launch.in", "r", stdin);
}

void wr() {
    freopen("launch.out", "w", stdout);
}

signed main() {
    rd(), wr();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    best = -1;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            val[i] = c[i] - (long long)(k - 1) * d[i];
        }
        sort(val + 1, val + n + 1, greater<long long>());
        long long s = 0;
        for (int i = 1; i <= k; i++) {
            s += val[i];
        }
        if (s >= best) {
            best = s, bk = k;
        }
    }
    cout << best << "\n"
         << bk << "\n";
    return 0;
}
