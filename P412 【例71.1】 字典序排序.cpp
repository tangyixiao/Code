#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
string s;
int id[N];

inline void input() {
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        id[i] = i;
    }
    stable_sort(id, id + s.size(), [](int a, int b) { return s[a] < s[b]; });
    return;
}

inline void solve() {
    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        ans += abs(id[i] - i);
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
