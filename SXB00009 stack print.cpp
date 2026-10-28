#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];

signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i += m) {
        int r = min(n, i + m - 1);
        for (int j = r; j >= i; j--) {
            if (i > 1 || j < r) {
                cout << " ";
            }
            cout << a[j];
        }
    }
    cout << "\n";
    return 0;
}
