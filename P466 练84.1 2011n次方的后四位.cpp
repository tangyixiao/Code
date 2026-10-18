#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int k;
char s[N];

signed main() {
    cin >> k;
    while (k--) {
        cin >> s;
        int m = 0;
        for (int i = 0; s[i]; i++) {
            m = (m * 10 + s[i] - '0') % 500;
        }
        int r = 1;
        for (int i = 0; i < m; i++) {
            r = r * 2011 % 10000;
        }
        cout << r << "\n";
    }
    return 0;
}
