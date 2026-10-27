#include <bits/stdc++.h>
using namespace std;

int L, a, b, c, cnt;

signed main() {
    cin >> L;
    cnt = 0;
    for (a = 1; 3 * a <= L; a++) {
        for (b = a; 2 * b <= L - a; b++) {
            c = L - a - b;
            if (c < b) {
                break;
            }
            if (a + b > c) {
                if (!(a == b && b == c)) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
