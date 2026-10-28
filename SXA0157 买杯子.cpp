#include <bits/stdc++.h>
using namespace std;
int i, x, cnt, sum;
signed main() {
    for (i = 1; i <= 3; i++) {
        cin >> x;
        if (x >= 10 && x <= 20) {
            cnt++, sum += x;
        }
    }
    cout << cnt << " " << sum << "\n";
    return 0;
}
