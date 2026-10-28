#include <bits/stdc++.h>
using namespace std;
long long a, t;
int i, len, d;
signed main() {
    cin >> a;
    d = 0;
    for (t = a; t; t /= 10) {
        d++;
    }
    len = 24 + d;
    for (i = 1; i <= len; i++) {
        cout << "*";
    }
    cout << "\n";
    cout << "*Welcome,ContestantNo." << a << "!*\n";
    for (i = 1; i <= len; i++) {
        cout << "*";
    }
    cout << "\n";
    return 0;
}
