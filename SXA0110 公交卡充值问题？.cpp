#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    int ans;
    if (n < 200) {
        ans = n;
    } else if (n < 300) {
        ans = n + 50;
    } else if (n < 500) {
        ans = n + 100;
    } else {
        ans = n + 200;
    }
    cout << ans << "\n";
    return 0;
}
