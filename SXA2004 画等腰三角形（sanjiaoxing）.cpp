#include <bits/stdc++.h>
using namespace std;
int n, i, k, mode;
char c;
signed main() {
    cin >> n >> c >> mode;
    for (i = 1; i <= n; i++) {
        for (k = 0; k < 2 * n - 1; k++) {
            bool ink = false;
            if (mode == 1) {
                ink = (k >= n - i && k <= n + i - 2);
            } else if (i == n) {
                ink = (k >= n - i && k <= n + i - 2);
            } else if (i == 1) {
                ink = (k == n - 1);
            } else {
                ink = (k == n - i || k == n + i - 2);
            }
            if (ink) {
                cout << c;
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
