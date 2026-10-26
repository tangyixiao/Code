#include <bits/stdc++.h>
using namespace std;

string rep(int n) {
    string s;
    int first = 1;
    for (int k = 20; k >= 0; k--) {
        if ((n >> k) & 1) {
            string t;
            if (k == 0) {
                t = "2(0)";
            } else if (k == 1) {
                t = "2";
            } else {
                t = "2(" + rep(k) + ")";
            }
            if (!first) {
                s += "+";
            }
            s += t;
            first = 0;
        }
    }
    return s;
}

signed main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "0" << "\n";
    } else {
        cout << rep(n) << "\n";
    }
    return 0;
}
