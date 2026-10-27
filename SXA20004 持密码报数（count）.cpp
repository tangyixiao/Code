#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, m, i, j, sz, cur, idx;
int pw[N], pe[N];

signed main() {
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> pw[i];
        pe[i] = i + 1;
    }
    cin >> m;
    sz = n;
    cur = 0;
    for (j = 1; j <= n; j++) {
        idx = (cur + m - 1) % sz;
        if (j > 1) {
            cout << " ";
        }
        cout << pe[idx];
        m = pw[idx];
        for (i = idx; i < sz - 1; i++) {
            pe[i] = pe[i + 1];
            pw[i] = pw[i + 1];
        }
        sz--;
        if (sz > 0) {
            cur = idx % sz;
        }
    }
    cout << "\n";
    return 0;
}
