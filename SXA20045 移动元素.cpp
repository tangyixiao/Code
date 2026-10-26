#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, i, a[N];
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 2; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << a[1] << "\n";
    return 0;
}
