#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    int sz = 2 * n + 1;
    for (int i = 1; i <= sz; i++) {
        for (int j = 1; j <= sz; j++) {
            int v = n - min(min(i - 1, j - 1), min(sz - i, sz - j));
            if (j > 1) {
                cout << " ";
            }
            cout << v;
        }
        cout << "\n";
    }
    return 0;
}
