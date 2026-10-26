#include <bits/stdc++.h>
using namespace std;

int n, r, a[20];

inline void dfs(int x, int y) {
    if (y > r) {
        for (int i = 1; i <= r; i++) {
            if (i > 1) {
                cout << " ";
            }
            cout << a[i];
        }
        cout << "\n";
        return;
    }
    for (int i = x; i <= n - (r - y); i++) {
        a[y] = i;
        dfs(i + 1, y + 1);
    }
}

signed main() {
    cin >> n >> r;
    dfs(1, 1);
    return 0;
}
