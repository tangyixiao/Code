#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    for (int t = 1; t <= n; t++) {
        for (int s = 1; s <= 5 * (t - 1); s++) {
            cout << " ";
        }
        int c = n - t + 1;
        for (int j = 1; j <= c; j++) {
            cout << setw(5) << j;
        }
        cout << "\n";
    }
    return 0;
}
