#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, tot;
char op[N];

inline void input() { cin >> n; }

inline long long cal() {
    long long x = 0, cur = 0;
    char sg = '+';
    for (int i = 1; i <= n; ++i) {
        if (i == 1 || op[i - 1] == '.') {
            cur = cur * 10 + i;
        } else {
            x += sg == '+' ? cur : -cur;
            cur = i, sg = op[i - 1];
        }
    }
    return x + (sg == '+' ? cur : -cur);
}

inline void solve() {
    int len = n - 1;
    for (int st = 0; st < (int)pow(3, len); ++st) {
        int v = st;
        for (int i = len; i >= 1; --i) {
            op[i] = "+-."[v % 3];
            v /= 3;
        }
        if (cal()) {
            continue;
        }
        ++tot;
        for (int i = 1; i <= n; ++i) {
            cout << i;
            if (i < n) {
                cout << " " << op[i] << " ";
            }
        }
        cout << "\n";
    }
    cout << tot << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}