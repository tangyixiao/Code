#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (i) {
            cout << ' ';
        }
        cout << a + b + c;
    }
    cout << "\n";
    return 0;
}
