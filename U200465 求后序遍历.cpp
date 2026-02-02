#include <bits/stdc++.h>
using namespace std;
string pre, mid, suf = "";
map<char, int> mp;
inline void dfs(int ps, int pe, int is, int ie) {
    if (ps > pe || is > ie) {
        return;
    }
    char rt = pre[ps];
    int rp = mp[rt], ls = rp - is;
    dfs(ps + 1, ps + ls, is, rp - 1);
    dfs(ps + ls + 1, pe, rp + 1, ie);
    suf += rt;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("suf.in", "r", stdin);
    // freopen("suf.out", "w", stdout);
    cin >> pre >> mid;
    for (int i = 0; i < mid.size(); i++) {
        mp[mid[i]] = i;
    }
    dfs(0, pre.size() - 1, 0, mid.size() - 1);
    cout << suf;
    return 0;
}