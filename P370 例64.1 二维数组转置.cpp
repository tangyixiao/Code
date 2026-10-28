#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
int a[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i * m + j];
        }
    }
    cout << m << " " << n << "\n";
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (i) {
                cout << " ";
            }
            cout << a[i * m + j];
        }
        cout << "\n";
    }
    return 0;
}
