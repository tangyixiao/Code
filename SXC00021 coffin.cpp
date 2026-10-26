#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, k;
long long a, b;

int f(long long x) {
    int s = 0;
    for (; x > 0; x /= 10) {
        s += (x % 10) * (x % 10);
    }
    return s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> a >> b;
    long long ans = 0;
    for (int s = 1; s <= 1700; s++) {
        long long x = 1LL * k * s;
        if (x >= a && x <= b && f(x) == s) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
