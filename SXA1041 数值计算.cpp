#include <bits/stdc++.h>
using namespace std;

int d[10];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        d[i] = s[i] - '0';
    }
    cout << s.size() << "\n";
    for (int i = 0; i < (int)s.size(); i++) {
        if (i) {
            cout << " ";
        }
        cout << d[i];
    }
    cout << "\n";
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        cout << d[i];
    }
    cout << "\n";
    return 0;
}
