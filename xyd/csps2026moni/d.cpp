#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], nxt[N], pos[N], q[N], tp, tag[8192], val[8192], p;
long long cnt;
unsigned long long r[N], key[8192];
pair<int, int> pl[11], pr[11];
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("tuple.in", "r", stdin), freopen("tuple.out", "w", stdout);
    mt19937_64 rng(20260926);
    for (int i = 1; i < N; i++) {
        r[i] = rng();
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n <= 2000) {
        for (int i = n; i >= 1; i--) {
            nxt[i] = pos[a[i]] ? pos[a[i]] : n + 1, pos[a[i]] = i;
        }
        memset(pos, 0, sizeof pos);
        for (int i = 1; i <= n; i++) {
            q[i] = pos[a[i]], pos[a[i]] = i;
        }
        for (int j = 1; j <= n; j++) {
            tp++;
            for (int i = j, h = 0; i >= 1; i--) {
                if (nxt[i] > j) {
                    h ^= r[a[i]];
                }
                for (p = h & 8191; tag[p] == tp && key[p] != h; p = p + 1 & 8191) {
                }
                if (tag[p] == tp) {
                    val[p]++;
                } else {
                    tag[p] = tp, key[p] = h, val[p] = 1;
                }
            }
            for (int kk = j + 1, h = 0; kk <= n; kk++) {
                if (q[kk] <= j) {
                    h ^= r[a[kk]];
                }
                for (p = h & 8191; tag[p] == tp && key[p] != h; p = p + 1 & 8191) {
                }
                if (tag[p] == tp) {
                    cnt += val[p];
                }
            }
        }
        cout << cnt << "\n";
        return 0;
    }
    for (int i = n; i >= 1; i--) {
        nxt[i] = pos[a[i]] ? pos[a[i]] : n + 1, pos[a[i]] = i;
    }
    for (int v = 1; v <= 10; v++) {
        q[v] = pos[v] ? pos[v] : n + 1;
    }
    memset(pos, 0, sizeof pos);
    for (int j = 1; j <= n; j++) {
        pos[a[j]] = j;
        if (q[a[j]] == j) {
            q[a[j]] = nxt[j];
        }
        int dl = 0, dr = 0;
        for (int v = 1; v <= 10; v++) {
            if (pos[v]) {
                pl[dl++] = {pos[v], v};
            }
            if (q[v] <= n) {
                pr[dr++] = {q[v], v};
            }
        }
        sort(pl, pl + dl, greater<pair<int, int>>());
        sort(pr, pr + dr);
        int lm = 0;
        for (int x = 0; x < dl; x++) {
            lm |= 1 << pl[x].second;
            int lc = pl[x].first - (x + 1 < dl ? pl[x + 1].first : 0);
            int rm = 0;
            for (int y = 0; y < dr; y++) {
                rm |= 1 << pr[y].second;
                if (rm == lm) {
                    cnt += (long long)lc * ((y + 1 < dr ? pr[y + 1].first : n + 1) - pr[y].first);
                }
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
