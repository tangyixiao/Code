#include <bits/stdc++.h>
using namespace std;

int cnt[15], t[3];

signed main() {
    for (int a = 123; a <= 333; a++) {
        t[0] = a, t[1] = a * 2, t[2] = a * 3;
        for (int i = 0; i <= 9; i++) {
            cnt[i] = 0;
        }
        for (int k = 0; k < 3; k++) {
            int x = t[k];
            while (x > 0) {
                cnt[x % 10]++;
                x /= 10;
            }
        }
        bool ok = true;
        for (int i = 1; i <= 9; i++) {
            if (cnt[i] != 1) {
                ok = false;
            }
        }
        if (cnt[0] != 0) {
            ok = false;
        }
        if (ok) {
            cout << t[0] << " " << t[1] << " " << t[2] << "\n";
        }
    }
    return 0;
}
