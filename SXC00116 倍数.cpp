#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n;
long long a[N], s[N];
int last[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        s[i] = ((s[i - 1] + a[i]) % n + n) % n;
    }
    for (int r = 0; r < n; r++) {
        last[r] = -1;
    }
    last[0] = 0;
    int bl = 0, bs = 0;
    for (int i = 1; i <= n; i++) {
        int r = (int)s[i];
        if (last[r] >= 0) {
            int st = last[r] + 1;
            int len = i - last[r];
            if (bl == 0 || len < bl || (len == bl && st < bs)) {
                bl = len;
                bs = st;
            }
        } else {
            last[r] = i;
        }
    }
    if (bl == 0) {
        cout << "0\n";
        return 0;
    }
    cout << bl << "\n";
    for (int i = bs; i < bs + bl; i++) {
        cout << a[i] << "\n";
    }
    return 0;
}
