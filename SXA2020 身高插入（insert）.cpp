#include <bits/stdc++.h>
using namespace std;

int n, h, a[105];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> h;
    int p = n + 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > h) {
            p = i;
            break;
        }
    }
    for (int i = 1; i <= n + 1; i++) {
        int v;
        if (i == p) {
            v = h;
        } else if (i < p) {
            v = a[i];
        } else {
            v = a[i - 1];
        }
        cout << v;
        if (i != n + 1) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
