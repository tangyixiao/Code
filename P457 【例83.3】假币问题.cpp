#include <bits/stdc++.h>
using namespace std;

int n, ans, pw = 1;

signed main() {
    while (cin >> n && n) {
        ans = 0, pw = 1;
        for (; pw < n; pw *= 3) {
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
