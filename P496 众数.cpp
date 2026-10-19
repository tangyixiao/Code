#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k, a, cnt[N], freq[N], cstar, res;
long long g[N], s[N], num, sum;

signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        cnt[a]++;
    }
    for (int v = 1; v <= n; v++) {
        if (cnt[v]) {
            freq[cnt[v]]++;
        }
    }
    for (int c = n; c >= 0; c--) {
        g[c] = sum - (long long)c * num;
        s[c] = g[c] + c;
        if (freq[c]) {
            num += freq[c];
            sum += (long long)c * freq[c];
        }
    }
    cstar = 0;
    for (int c = 1; c <= n; c++) {
        if (s[c] < s[cstar]) {
            cstar = c;
        }
    }
    for (int c = 0; c <= n; c++) {
        if (s[c] <= k) {
            cout << "pigstd\n";
            return 0;
        }
    }
    for (int v = 1; v <= n; v++) {
        int m = cnt[v], c = max(m, cstar);
        if (s[c] <= k + m) {
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}