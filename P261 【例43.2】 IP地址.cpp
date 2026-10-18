#include <bits/stdc++.h>
using namespace std;

const int N = 30 + 5;
char s[N];
int a[4];
char h[] = "0123456789abcdef";

signed main() {
    while (cin >> s) {
        int j = 0;
        for (int i = 0; i < 4; i++) {
            a[i] = 0;
        }
        for (int i = 0; s[i]; i++) {
            if (s[i] == '.') {
                j++;
            } else {
                a[j] = a[j] * 10 + s[i] - '0';
            }
        }
        for (int i = 0; i < 4; i++) {
            cout << h[a[i] >> 4 & 15] << h[a[i] & 15];
        }
        cout << "\n";
    }
    return 0;
}
