#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 10000;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int i = 0, n = s.size();
    ll sum = 0, term = 0;
    char op = 0;
    while (i < n) {
        ll x = 0;
        for (; i < n && s[i] >= '0' && s[i] <= '9'; i++) {
            x = (x * 10 + (s[i] - '0')) % MOD;
        }
        if (op == '*') {
            term = term * x % MOD;
        } else if (op == '+') {
            sum = (sum + term) % MOD;
            term = x;
        } else {
            term = x;
        }
        if (i < n) {
            op = s[i];
            i++;
        }
    }
    sum = (sum + term) % MOD;
    cout << sum << "\n";
    return 0;
}
