#pragma optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
int n;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    set<string> set;
    for (int i = 1; i <= n; ++i) {
        string s, dir = "";
        cin >> s;
        for (auto j : s) {
            if (j == '/') {
                set.insert(dir);
            }
            dir += j;
        }
        set.insert(dir);
        cout << set.size() - 1 << endl;
    }
    return 0;
}
