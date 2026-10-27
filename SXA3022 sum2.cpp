#include <bits/stdc++.h>
using namespace std;
int m, i;
long long s, a;
signed main() {
    cin >> m;
    s = 0, a = 1;
    for (i = 1;; i++) {
        s += a;
        if (s > m) {
            break;
        }
        a += i;
    }
    cout << i << "\n";
    return 0;
}
