#include <bits/stdc++.h>
using namespace std;
string a, b;
int ca, cb, i, A, B;
int c1[10], c2[10];
signed main() {
    cin >> a >> b;
    ca = a.size();
    cb = b.size();
    for (i = 0; i < ca; i++) {
        if (a[i] == b[i]) {
            A++;
        } else {
            c1[a[i] - '0']++;
            c2[b[i] - '0']++;
        }
    }
    for (i = 0; i <= 9; i++) {
        B += min(c1[i], c2[i]);
    }
    if (A == ca) {
        cout << "OK\n";
    } else {
        cout << A << "A" << B << "B\n";
    }
    return 0;
}
