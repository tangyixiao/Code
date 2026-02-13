#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 987654321;
const int MAXN = 50010;
int n, m, c;
int allow[MAXN];
int flip[MAXN];
int parent[MAXN];
int group_allow[MAXN];

int find(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
void unite(int x, int y) {
    parent[find(y)] = find(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> c;
    int full_mask = (1 << c) - 1;
    for (int i = 1; i <= n; ++i)
        allow[i] = full_mask;
    memset(flip, 0, sizeof(flip));

    bool conflict = false;
    while (m--) {
        int op, x, y, p;
        cin >> op;
        if (op == 1) {
            cin >> x >> p;
            int mask = 1 << (p - 1);
            if (!(allow[x] & mask))
                conflict = true;
            else
                allow[x] = mask;
        } else if (op == 2) {
            cin >> x >> p;
            int mask = 1 << (p - 1);
            if (allow[x] == mask)
                conflict = true;
            else
                allow[x] &= ~mask;
            if (allow[x] == 0)
                conflict = true;
        } else {
            cin >> x >> y;
            int e = min(x, y);
            flip[e]++;
        }
        if (conflict)
            break;
    }
    if (conflict) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 1; i <= n; ++i)
        parent[i] = i;

    for (int i = 2; i <= n - 2; ++i) {
        if (flip[i] & 1)
            unite(i, i + 1);
    }

    for (int i = 1; i <= n; ++i)
        group_allow[i] = full_mask;
    for (int i = 1; i <= n; ++i) {
        int r = find(i);
        group_allow[r] &= allow[i];
        if (group_allow[r] == 0) {
            conflict = true;
            break;
        }
    }
    if (conflict) {
        cout << 0 << '\n';
        return 0;
    }

    if (find(1) == find(2) || find(n - 1) == find(n) || find(n) == find(1)) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 2; i <= n - 2; ++i) {
        if (!(flip[i] & 1)) {
            if (find(i) == find(i + 1)) {
                conflict = true;
                break;
            }
        }
    }
    if (conflict) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> seq;
    int last = -1;
    for (int i = 1; i <= n; ++i) {
        int r = find(i);
        if (r != last) {
            seq.push_back(r);
            last = r;
        }
    }

    int k = seq.size();
    if (k == 1) {
        cout << 0 << '\n';
        return 0;
    }

    long long ans = 0;
    vector<long long> dp(c, 0), ndp(c, 0);
    for (int first_col = 0; first_col < c; ++first_col) {
        int mask0 = group_allow[seq[0]];
        if (!(mask0 & (1 << first_col)))
            continue;

        fill(dp.begin(), dp.end(), 0);
        dp[first_col] = 1;

        for (int i = 1; i < k; ++i) {
            int cur_mask = group_allow[seq[i]];
            long long sum = 0;
            for (int col = 0; col < c; ++col)
                sum = (sum + dp[col]) % MOD;

            fill(ndp.begin(), ndp.end(), 0);
            for (int col = 0; col < c; ++col) {
                if (cur_mask & (1 << col)) {
                    ndp[col] = (sum - dp[col] + MOD) % MOD;
                }
            }
            dp.swap(ndp);
        }

        for (int col = 0; col < c; ++col) {
            if (col != first_col) {
                ans = (ans + dp[col]) % MOD;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}