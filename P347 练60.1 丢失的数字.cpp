#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, a;
bool v[N];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a;
        v[a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            cout << i << "\n";
        }
    }
    return 0;
}
