#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, a[N];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int mn = a[1];
    for (int i = 1; i <= n; i++) {
        if (a[i] > mn) {
            cout << a[i] << "\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
