#include <bits/stdc++.h>
using namespace std;
string s;
int l, r;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            l++;
        }
        if (s[i] == ')') {
            r++;
        }
        if (l < r) {
            cout << "NO";
            return 0;
        }
    }
    if (l != r) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    return 0;
}