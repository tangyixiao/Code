#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int a[N], n, m;

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    int c = 0;
    for (int i = 0; i < n; i++) {
        c += a[i] == m;
    }
    cout << c << "\n";
    return 0;
}
