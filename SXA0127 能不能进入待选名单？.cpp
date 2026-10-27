#include <bits/stdc++.h>
using namespace std;

int a, b, c, s;

signed main() {
    cin >> a >> b >> c;
    s = a + b + c;
    if (s >= 270 && a >= 86 && b >= 86 && c >= 86) {
        cout << "good\n";
    } else {
        cout << "sorry\n";
    }
    return 0;
}
