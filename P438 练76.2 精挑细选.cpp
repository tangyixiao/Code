#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, L, D, C, ans;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, d, c;
        cin >> l >> d >> c;
        if (l > L || (l == L && d < D) || (l == L && d == D && c > C)) {
            L = l, D = d, C = c;
        }
    }
    cout << C << "\n";
    return 0;
}
