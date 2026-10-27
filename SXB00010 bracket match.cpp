#include <bits/stdc++.h>
using namespace std;

string s;
int cnt;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(') {
            cnt++;
        } else if (s[i] == ')') {
            cnt--;
        }
        if (cnt < 0) {
            break;
        }
    }
    cout << (cnt == 0 ? "yes" : "no") << "\n";
    return 0;
}
