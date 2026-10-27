#include <bits/stdc++.h>
using namespace std;
const int N = 3e1 + 5;
char s[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    int n = strlen(s), f = 1;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (!(c == '_' || isalpha(c) || (i > 0 && isdigit(c)))) {
            f = 0;
        }
    }
    if (f) {
        if (!strcmp(s, "int") || !strcmp(s, "double") || !strcmp(s, "cout") || !strcmp(s, "cin")) {
            f = 0;
        }
    }
    if (f) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
    return 0;
}
