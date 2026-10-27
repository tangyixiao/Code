#include <bits/stdc++.h>
using namespace std;
int a, b, c, cnt;
signed main() {
    for (a = 0; a <= 20; a++) {
        for (b = 0; b <= 150; b++) {
            c = 100 - 9 * a - b;
            if (c < 0) {
                continue;
            }
            if (9 * a + b + c == 100 && 2 * a + 2 * b + 4 * c == 100) {
                cout << a << " " << b << " " << c << "\n";
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
