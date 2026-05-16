#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ull a;
        int n;
        cin >> a >> n;
        bool h[10] = {};
        int mn = 10, mx = -1, nz = -1;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            h[x] = 1;
            if (x < mn)
                mn = x;
            if (x > mx)
                mx = x;
            if (x && (nz == -1 || x < nz))
                nz = x;
        }
        string s = to_string(a);
        int L = s.size();
        ull ans = ULLONG_MAX;

        string g(L, '0');
        bool ok = 1;
        int i = 0;
        while (i < L) {
            int c = s[i] - '0', f = -1;
            for (int d = c; d <= 9; ++d)
                if (h[d]) {
                    f = d;
                    break;
                }
            if (f == -1) {
                int j = i - 1;
                while (j >= 0) {
                    int u = g[j] - '0', x = -1;
                    for (int d = u + 1; d <= 9; ++d)
                        if (h[d]) {
                            x = d;
                            break;
                        }
                    if (x != -1) {
                        g[j] = '0' + x;
                        for (int k = j + 1; k < L; ++k)
                            g[k] = '0' + mn;
                        i = L;
                        break;
                    }
                    --j;
                }
                if (j == -1) {
                    ok = 0;
                    break;
                }
            } else {
                g[i] = '0' + f;
                if (f > c) {
                    for (int k = i + 1; k < L; ++k)
                        g[k] = '0' + mn;
                    break;
                }
                ++i;
            }
        }
        if (ok) {
            ull v = stoull(g);
            ull d = a > v ? a - v : v - a;
            if (d < ans)
                ans = d;
        }

        string e(L, '0');
        ok = 1;
        i = 0;
        while (i < L) {
            int c = s[i] - '0', f = -1;
            for (int d = c; d >= 0; --d)
                if (h[d]) {
                    f = d;
                    break;
                }
            if (f == -1) {
                int j = i - 1;
                while (j >= 0) {
                    int u = e[j] - '0', x = -1;
                    for (int d = u - 1; d >= 0; --d)
                        if (h[d]) {
                            x = d;
                            break;
                        }
                    if (x != -1) {
                        e[j] = '0' + x;
                        for (int k = j + 1; k < L; ++k)
                            e[k] = '0' + mx;
                        i = L;
                        break;
                    }
                    --j;
                }
                if (j == -1) {
                    ok = 0;
                    break;
                }
            } else {
                e[i] = '0' + f;
                if (f < c) {
                    for (int k = i + 1; k < L; ++k)
                        e[k] = '0' + mx;
                    break;
                }
                ++i;
            }
        }
        if (ok) {
            ull v = stoull(e);
            ull d = a > v ? a - v : v - a;
            if (d < ans)
                ans = d;
        }

        if (nz != -1) {
            string lg = string(1, '0' + nz) + string(L, '0' + mn);
            ull v = stoull(lg);
            ull d = a > v ? a - v : v - a;
            if (d < ans)
                ans = d;
        }

        if (L > 1 && mx != 0) {
            string sh = string(L - 1, '0' + mx);
            ull v = stoull(sh);
            ull d = a > v ? a - v : v - a;
            if (d < ans)
                ans = d;
        }

        cout << ans << '\n';
    }
    return 0;
}