#include <bits/stdc++.h>
using namespace std;

char s[1005];
int c[30];

signed main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        c[s[i] - 'a']++;
    }
    int mx = 0, p = 0;
    for (int i = 0; i < 26; i++) {
        if (c[i] > mx) {
            mx = c[i];
            p = i;
        }
    }
    cout << (char)('a' + p) << " " << mx << "\n";
    return 0;
}
