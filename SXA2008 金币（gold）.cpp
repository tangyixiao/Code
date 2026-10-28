#include <bits/stdc++.h>
using namespace std;

int n, d, k, s;

signed main() {
    cin >> n;
    for (k = 1; d < n; k++) {
        for (int i = 1; i <= k && d < n; i++) {
            s += k, d++;
        }
    }
    cout << s << "\n";
    return 0;
}
