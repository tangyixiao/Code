#include <bits/stdc++.h>
using namespace std;

signed main() {
    int a, b, w = 0, l = 0;
    for (int i = 1; i <= 3; i++) {
        cin >> a >> b;
        if (a > b) {
            w++;
        } else {
            l++;
        }
    }
    if (w > l) {
        cout << "yangguang" << "\n";
    } else {
        cout << "leiting" << "\n";
    }
    return 0;
}
