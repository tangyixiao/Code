#include <bits/stdc++.h>
using namespace std;
int k, l, r, cnt;
signed main() {
    cin >> k >> l >> r;
    for (int i = l; i <= r; i++) {
        cnt += (((!(i % k)) || (!(i % 10 - k))) ? i : 0);
    }
    cout << cnt;
    return 0;
}