#include <bits/stdc++.h>
using namespace std;
int x, n, cnt, id;
signed main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        id = i;
        for (; id; id /= 10) {
            if (id % 10 == x) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}