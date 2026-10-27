#include <bits/stdc++.h>
using namespace std;

int n, st[1005], len[1005];

signed main() {
    int i, j, x, k = 0;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> st[i] >> len[i];
    }
    cin >> x;
    k = n;
    int p = 0;
    for (i = 1; i <= k; i++) {
        if (st[i] + len[i] - 1 == x - 1) {
            p = i;
        }
    }
    int q = 0;
    for (i = 1; i <= k; i++) {
        if (st[i] == x + 1) {
            q = i;
        }
    }
    if (p != 0 && q != 0) {
        len[p] = len[p] + 1 + len[q];
        for (i = q; i < k; i++) {
            st[i] = st[i + 1], len[i] = len[i + 1];
        }
        k--;
    } else if (p != 0) {
        len[p]++;
    } else if (q != 0) {
        st[q] = x, len[q]++;
    } else {
        k++;
        st[k] = x, len[k] = 1;
        for (i = 1; i <= k; i++) {
            for (j = i + 1; j <= k; j++) {
                if (st[i] > st[j]) {
                    swap(st[i], st[j]), swap(len[i], len[j]);
                }
            }
        }
    }
    for (i = 1; i <= k; i++) {
        cout << st[i] << " " << len[i] << "\n";
    }
    return 0;
}
