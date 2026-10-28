#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, x, best, cnt, c[1005];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        c[x]++;
    }
    for (int i = 0; i <= 1000; i++) {
        if (c[i] > cnt) {
            cnt = c[i], best = i;
        }
    }
    cout << best << "\n";
    return 0;
}
