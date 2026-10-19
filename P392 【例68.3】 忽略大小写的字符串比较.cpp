#include <bits/stdc++.h>
using namespace std;

const int N = 85;
char s[N], t[N];

signed main() {
    cin >> s >> t;
    for (int i = 0; s[i]; i++) {
        s[i] |= 32;
    }
    for (int i = 0; t[i]; i++) {
        t[i] |= 32;
    }
    cout << (strcmp(s, t) < 0 ? "<" : strcmp(s, t) > 0 ? ">"
                                                       : "=")
         << "\n";
    return 0;
}