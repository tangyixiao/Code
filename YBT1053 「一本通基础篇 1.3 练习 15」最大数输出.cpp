#include <bits/stdc++.h>
using namespace std;
int a, b, c, mx;
signed main() {
    cin >> a >> b >> c;
    mx = a;
    if (b > mx) {
        mx = b;
    }
    if (c > mx) {
        mx = c;
    }
    cout << mx << "\n";
    return 0;
}
