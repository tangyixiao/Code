#include <bits/stdc++.h>
using namespace std;

signed main() {
    int b, g;
    cin >> b >> g;
    if (b + g < 10) {
        cout << "water" << "\n";
    } else if (b > g) {
        cout << "tree" << "\n";
    } else {
        cout << "tea" << "\n";
    }
    return 0;
}
