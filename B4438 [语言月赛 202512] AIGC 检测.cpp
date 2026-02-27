#include <bits/stdc++.h>
using namespace std;
int a, b, c, ans = 1e9;
signed main() {
    cin >> a >> b >> c;
    if (a >= 30 && a <= 70) {
        cout << a;
    } else {
        if (b >= 30 && b <= 70) {
            ans = min(ans, b);
        }
        if (c >= 30 && c <= 70) {
            ans = min(ans, c);
        }
        cout << (ans == 1e9 ? 0 : ans);
    }
    return 0;
}