#include <bits/stdc++.h>
using namespace std;

string s;
char c;
int i;

signed main() {
    cin >> s;
    cin >> c;
    for (i = 0; i < (int)s.size(); i++) {
        if (s[i] != c) {
            cout << s[i];
        }
    }
    cout << "\n";
    return 0;
}
