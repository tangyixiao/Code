#include <bits/stdc++.h>
using namespace std;
int n, id = 1;
string s;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        s += (char)(x);
    }
    s = " " + s + s;
    for (int i = 2, j; i <= n;) {
        for (j = 0; j < n && s[id + j] == s[i + j]; j++)
            ;
        if (j == n) {
            break;
        }
        if (s[id + j] > s[i + j]) {
            int tmp = id;
            id = i;
            i = max(i + 1, tmp + j + 1);
        } else {
            i += (j + 1);
        }
    }
    for (int i = id; i <= id + n - 1; i++) {
        cout << (int)(s[i]) << " ";
    }
    return 0;
}