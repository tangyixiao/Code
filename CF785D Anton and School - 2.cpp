#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 200005;

int fac[MAXN], invfac[MAXN];

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = 1LL * fac[i - 1] * i % MOD;
    invfac[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i)
        invfac[i] = 1LL * invfac[i + 1] * (i + 1) % MOD;
}

int C(int n, int m) {
    if (m < 0 || m > n)
        return 0;
    return 1LL * fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    init(n);

    vector<int> pre(n + 1, 0), suf(n + 2, 0);

    for (int i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + (s[i - 1] == '(');

    for (int i = n; i >= 1; --i)
        suf[i] = suf[i + 1] + (s[i - 1] == ')'); 

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == '(') {
            int left = pre[i];
            int right = suf[i + 1];

            ans = (ans + C(left + right - 1, left)) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}