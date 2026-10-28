#include <bits/stdc++.h>
using namespace std;

int a, c;

signed main() {
    for (int i = 1; i <= 4; i++) {
        cin >> a;
        if (a >= 90) {
            c++;
        }
    }
    if (c == 4) {
        cout << "A" << "\n";
    } else if (c >= 2) {
        cout << "B" << "\n";
    } else if (c == 1) {
        cout << "C" << "\n";
    } else {
        cout << "D" << "\n";
    }
    return 0;
}
