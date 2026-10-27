#include <bits/stdc++.h>
using namespace std;

long long n, a, q, ans;

signed main() {
    cin >> n;
    a = n / 10;
    q = n / 5;
    ans = (a + 1) * (q + 1 - a);
    cout << ans << "\n";
    return 0;
}
