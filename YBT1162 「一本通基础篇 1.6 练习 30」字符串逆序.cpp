#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char s[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 0;
    for (char c; cin.get(c);) {
        if (c == '!') {
            break;
        }
        if (c != '\n' && c != '\r') {
            s[n++] = c;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << s[i];
    }
    cout << "\n";
    return 0;
}
