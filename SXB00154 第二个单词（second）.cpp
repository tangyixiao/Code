#include <bits/stdc++.h>
using namespace std;

signed main() {
    string s;
    getline(cin, s);
    int p = s.find(' ');
    if (p < 0) {
        cout << "no" << "\n";
        return 0;
    }
    int q = s.find(' ', p + 1);
    while (p + 1 < (int)s.size() && s[p + 1] == ' ') {
        p++;
    }
    q = s.find(' ', p + 1);
    if (p + 1 >= (int)s.size()) {
        cout << "no" << "\n";
        return 0;
    }
    if (q < 0) {
        cout << s.substr(p + 1) << "\n";
    } else {
        cout << s.substr(p + 1, q - p - 1) << "\n";
    }
    return 0;
}
