#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 1e6 + 5;

int n;
int p[MAXN];
long long fact[MAXN];
int bit[MAXN];

void add(int idx, int val) {
    while (idx <= n) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int sum(int idx) {
    int res = 0;
    while (idx > 0) {
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];

    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % MOD;

    for (int i = 1; i <= n; ++i)
        add(i, 1);

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x = p[i];
        int cnt = sum(x - 1);
        ans = (ans + cnt * fact[n - i]) % MOD;
        add(x, -1);
    }

    ans = (ans + 1) % MOD;
    cout << ans << '\n';

    return 0;
}