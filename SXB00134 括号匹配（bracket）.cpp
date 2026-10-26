#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
char s[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int op = 0, cl = 0;
    for (char c; cin.get(c);) {
        if (c == '\n' || c == '\r' || c == EOF) {
            break;
        }
        if (c == '(') {
            op++;
        }
        if (c == ')') {
            if (op > 0) {
                op--;
            } else {
                cl++;
            }
        }
    }
    cout << (op + 1) / 2 + (cl + 1) / 2 << "\n";
    return 0;
}
