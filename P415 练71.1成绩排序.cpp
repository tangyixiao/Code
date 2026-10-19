#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

struct stu {
    char nm[N];
    int sc;
} a[N];

int n;

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].nm >> a[i].sc;
    }
}

inline void solve() {
    sort(a, a + n, [](stu &x, stu &y) {
        if (x.sc != y.sc) {
            return x.sc > y.sc;
        }
        return strcmp(x.nm, y.nm) < 0;
    });
    for (int i = 0; i < n; i++) {
        cout << a[i].nm << " " << a[i].sc << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}