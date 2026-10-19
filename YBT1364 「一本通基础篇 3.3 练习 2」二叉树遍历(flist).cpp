#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
string in, lv;
int po[N], n;
bool us[N];

void dfs(int l, int r) {
    if (l > r) {
        return;
    }
    int k = 0;
    for (; k < n; ++k) {
        if (!us[k] && po[lv[k]] >= l && po[lv[k]] <= r) {
            break;
        }
    }
    us[k] = true;
    int m = po[lv[k]];
    cout << lv[k];
    dfs(l, m - 1);
    dfs(m + 1, r);
    return;
}

inline void input() {
    cin >> in >> lv;
    n = lv.size();
    for (int i = 0; i < in.size(); ++i) {
        po[in[i]] = i;
    }
}

inline void solve() {
    dfs(0, n - 1);
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}