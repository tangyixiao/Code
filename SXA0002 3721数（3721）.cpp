#include <bits/stdc++.h>
using namespace std;

signed main() {
    for (int i = 1; i <= 200; i++) {
        if (i % 3 == 2 && i % 7 == 1) {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}
