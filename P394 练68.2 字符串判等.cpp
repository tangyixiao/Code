#include <bits/stdc++.h>
using namespace std;

const int N = 105;
char s[N], t[N];

signed main() {
    cin.getline(s, N), cin.getline(t, N);
    int n = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] != ' ') {
            s[n++] = s[i] | 32;
        }
    }
    s[n] = 0;
    int m = 0;
    for (int i = 0; t[i]; i++) {
        if (t[i] != ' ') {
            t[m++] = t[i] | 32;
        }
    }
    t[m] = 0;
    cout << (strcmp(s, t) == 0 ? "YES" : "NO") << "\n";
    return 0;
}