#include <bits/stdc++.h>
using namespace std;
string s, t;
signed main() {
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());
    if (t == s) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
    return 0;
}
