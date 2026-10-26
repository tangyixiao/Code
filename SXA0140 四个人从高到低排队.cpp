#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a + 4);
    for (int i = 3; i >= 0; i--) {
        cout << a[i];
        if (i) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
