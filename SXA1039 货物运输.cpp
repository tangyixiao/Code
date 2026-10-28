#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, a[N];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int c = 1, s = 0;
    for (int i = 1; i <= n; i++) {
        if (s + a[i] > m) {
            c++;
            s = a[i];
        } else {
            s += a[i];
        }
    }
    cout << c << "\n";
    return 0;
}
