#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t;
bool v[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    for (int n, m; t--;) {
        memset(v, 0, sizeof(v));
        cin >> n >> m;
        for (int a, b, c; m--;) {
            cin >> a >> b >> c;
            v[b] = true;
        }
        int id = 1;
        for (; v[id];) {
            id++;
        }

        for (int i = 1; i <= n; i++) {
            if (i != id) {
                cout << id << " " << i << "\n";
            }
        }
    }
    return 0;
}