#include <bits/stdc++.h>
using namespace std;
string s;
signed main() {
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            cout << "T";
        } else if (s[i] == 'T') {
            cout << "A";
        } else if (s[i] == 'C') {
            cout << "G";
        } else if (s[i] == 'G') {
            cout << "C";
        }
    }
    return 0;
}