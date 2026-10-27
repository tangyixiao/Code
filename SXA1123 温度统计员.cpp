#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, i, t, best, cur;
int a[N];

signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    best = 1;
    cur = 1;
    for (i = 2; i <= n; i++) {
        if (a[i] >= a[i - 1]) {
            cur++;
        } else {
            cur = 1;
        }
        if (cur > best) {
            best = cur;
        }
    }
    cout << best << "\n";
    return 0;
}
