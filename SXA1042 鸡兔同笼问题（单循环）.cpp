#include <bits/stdc++.h>
using namespace std;
signed main() {
    int i, j = 0;
    for (i = 1; i <= 50; i++) {
        j = 50 - i;
        if (2 * i + 4 * j == 160) {
            break;
        }
    }
    cout << i << " " << j << "\n";
    return 0;
}
