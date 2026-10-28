#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, x, a[N];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
    sort(a + 1, a + n + 1, greater<int>());
    cout << a[x] << "\n";
    return 0;
}
