#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, x[N], y[N];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    int mx = -1, id = 0;
    for (int i = 1; i <= n; i++) {
        int c = 0;
        for (int j = 1; j <= n; j++) {
            if (x[j] < x[i] && y[j] < y[i]) {
                c++;
            }
        }
        cout << c << "\n";
        if (c >= mx) {
            mx = c, id = i;
        }
    }
    cout << id << "\n";
    return 0;
}
