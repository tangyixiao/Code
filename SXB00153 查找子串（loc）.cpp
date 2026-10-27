#include <bits/stdc++.h>
using namespace std;

string s, t;

signed main() {
    getline(cin, s);
    getline(cin, t);
    size_t p = s.find(t);
    if (p == string::npos) {
        cout << "no" << "\n";
    } else {
        cout << (int)p << "\n";
    }
    return 0;
}
