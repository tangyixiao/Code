#include <bits/stdc++.h>
using namespace std;

int a[10];

signed main() {
    for (int i = 1; i <= 5; i++) {
        cin >> a[i];
    }
    int mx = 0;
    for (int i = 1; i <= 5; i++) {
        if (a[i] > mx) {
            mx = a[i];
        }
    }
    cout << mx << "\n";
    return 0;
}
