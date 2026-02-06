#include <bits/stdc++.h>
using namespace std;
string s, t;
signed main() {
    for (; cin >> s;) {
        t += to_string(s.size()) + ",";
    }
    cout << t.substr(0, t.size() - 1);
    return 0;
}