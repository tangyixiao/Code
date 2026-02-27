#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5, mod = 998244353;
int q, ans[N], res;
char s;
struct edge {
    int cnt, to;
    char c;
};
vector<edge> v[N];
int cnt[N], pre[N], fail[N], len;
char c[N];

inline int F(int x) { return x * (x + 1) / 2ll % mod; }
void dfs(int x) {
    ans[x] = res;
    for (edge e : v[x])
        if (e.cnt == 0) {
            dfs(e.to);
        } else {
            int las = res;
            ++len, cnt[len] = e.cnt, c[len] = e.c, fail[len] = 0,
                   pre[len] = pre[len - 1] + cnt[len];
            if (len == 1) {
                res = (res + F(cnt[len] - 1)) % mod;
            } else {
                int now = 0, nxt;
                for (int i = fail[len - 1];;) {
                    if (i == 0) {
                        if (c[1] == c[len]) {
                            res = (res + F(min(cnt[1], cnt[len])) +
                                   max(0ll, cnt[len] - cnt[1]) * cnt[1] - F(min(cnt[1], now)) -
                                   max(0ll, now - cnt[1]) * cnt[1]) %
                                  mod;
                            if (cnt[1] <= cnt[len]) {
                                fail[len] = 1;
                                break;
                            }
                        }
                        break;
                    } else {
                        if (c[i + 1] == c[len]) {
                            nxt = min(cnt[i + 1], cnt[len]);
                            if (now < nxt) {
                                res = (F(pre[i] + nxt) - F(pre[i] + now) + res) % mod;
                                now = nxt;
                            }
                            if (cnt[i + 1] == cnt[len]) {
                                fail[len] = i + 1;
                                break;
                            }
                        }
                        i = fail[i];
                    }
                }
            }
            dfs(e.to);
            len--;
            res = las;
        }
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    for (int i = 1, op, x; i <= q; i++) {
        cin >> op >> x;
        if (op == 1) {
            cin >> s;
            v[i - 1].push_back(edge{x, i, s});
        } else {
            v[x].push_back(edge{0, i, '_'});
        }
    }
    dfs(0);
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
