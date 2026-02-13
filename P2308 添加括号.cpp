#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int INF = 1e9;
int n;
vector<int> a;
vector<int> pref;
vector<vector<int>> dp;
vector<vector<int>> cut;
vector<int> mids;

int sum(int l, int r) {
    return pref[r] - pref[l - 1];
}

string build(int l, int r) {
    if (l == r)
        return to_string(a[l]);
    int k = cut[l][r];
    string left = build(l, k);
    string right = build(k + 1, r);
    return "(" + left + "+" + right + ")";
}

void collect(int l, int r) {
    if (l == r)
        return;
    int k = cut[l][r];
    collect(l, k);
    collect(k + 1, r);
    mids.push_back(sum(l, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n + 1);
    pref.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    if (n == 1) {
        cout << a[1] << "\n0\n\n";
        return 0;
    }

    dp.assign(n + 1, vector<int>(n + 1, INF));
    cut.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
        dp[i][i] = 0;

    for (int len = 2; len <= n; ++len) {
        for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;
            for (int k = l; k < r; ++k) {
                int val = dp[l][k] + dp[k + 1][r] + sum(l, r);
                if (val < dp[l][r]) {
                    dp[l][r] = val;
                    cut[l][r] = k;
                }
            }
        }
    }

    string expr = build(1, n);
    cout << expr << '\n';

    cout << dp[1][n] << '\n';

    collect(1, n);
    for (size_t i = 0; i < mids.size(); ++i) {
        if (i)
            cout << ' ';
        cout << mids[i];
    }
    cout << '\n';

    return 0;
}