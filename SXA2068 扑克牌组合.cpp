#include <bits/stdc++.h>
using namespace std;

int a[60], c[30];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            c[a[i] + a[j]] = 1;
        }
    }
    int m = 0;
    for (int i = 0; i < 30; i++) {
        if (c[i]) {
            m++;
        }
    }
    cout << m << "\n";
    int f = 1;
    for (int i = 0; i < 30; i++) {
        if (c[i]) {
            if (!f) {
                cout << ' ';
            }
            f = 0;
            cout << i;
        }
    }
    cout << "\n";
    return 0;
}
