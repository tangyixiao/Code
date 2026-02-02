#include <bits/stdc++.h>
using namespace std;
int t, p;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> t; t--;) {
        cin >> p;
        if (p <= 10) {
            cout << "R\n";
        } else {
            if (p <= 20) {
                cout << "L\n";
            } else {
                cout << p << "\n";
            }
        }
    }
    return 0;
}