#include <bits/stdc++.h>
using namespace std;
string s;
signed main() {
    getline(cin, s);
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (s[i] == 'a') {
                s[i] = 'z';
            } else {

                s[i] = s[i] - 1;
            }
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (s[i] == 'A') {
                s[i] = 'Z';
            } else {

                s[i] = s[i] - 1;
            }
        }
    }
    cout << s;
    return 0;
}