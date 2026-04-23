#include <bits/stdc++.h>
#define int long long
using namespace std;
void print(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<vector<int>> val(n + 2, vector<int>(n + 2, 0));

    for (int l = 1; l <= n; ++l) {
        int cur_pos = 0;
        int cur_neg = 0;
        int best_pos = 0;
        int best_neg = 0;
        for (int r = l; r <= n; ++r) {
            cur_pos = max((int)a[r], cur_pos + a[r]);
            cur_neg = min((int)a[r], cur_neg + a[r]);
            best_pos = max(best_pos, cur_pos);
            best_neg = min(best_neg, cur_neg);
            val[l][r] = max(best_pos, -best_neg);
        }
    }

    vector<vector<int>> sum(n + 2, vector<int>(n + 2, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + val[i][j];
        }

    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int ans = sum[r1][r2] - sum[l1 - 1][r2] - sum[r1][l2 - 1] + sum[l1 - 1][l2 - 1];
        print(ans);
        putchar('\n');
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}