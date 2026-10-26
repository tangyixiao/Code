#include <bits/stdc++.h>
using namespace std;

const int N = 30;
long long n, m, a[N], s1[5000], s2[5000];
int c1, c2;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    int h = n / 2;
    c1 = 0;
    for (int i = 0; i < (1 << h); i++) {
        long long s = 0;
        for (int j = 0; j < h; j++) {
            if (i >> j & 1) {
                s += a[j + 1];
            }
        }
        s1[c1++] = s;
    }
    int r = n - h;
    c2 = 0;
    for (int i = 0; i < (1 << r); i++) {
        long long s = 0;
        for (int j = 0; j < r; j++) {
            if (i >> j & 1) {
                s += a[h + j + 1];
            }
        }
        s2[c2++] = s;
    }
    sort(s2, s2 + c2);
    for (int i = 0; i < c1; i++) {
        long long need = m - s1[i];
        int p = lower_bound(s2, s2 + c2, need) - s2;
        if (p < c2 && s2[p] == need) {
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
    return 0;
}
