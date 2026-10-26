#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int a[N], n, i;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
