#include <bits/stdc++.h>
using namespace std;

char s[30], h[] = "0123456789X";
int s1;

signed main() {
    cin >> s;
    int c = 0;
    for (int i = 0, j = 1; i < 12; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            c += (s[i] - '0') * j, j++;
        }
    }
    if (s[12] == h[c % 11]) {
        cout << "Right\n";
    } else {
        s[12] = h[c % 11];
        cout << s << "\n";
    }
    return 0;
}