#include <bits/stdc++.h>
using namespace std;

int s[3];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    s[0] = s[1] = s[2] = 32;
    for (int g = 2; g >= 0; g--) {
        for (int i = 0; i < 3; i++) {
            if (i != g) {
                s[i] /= 2;
            }
        }
        s[g] = 96 - s[(g + 1) % 3] - s[(g + 2) % 3];
    }
    cout << s[0] << " " << s[1] << " " << s[2] << "\n";
    return 0;
}
