#include <bits/stdc++.h>
using namespace std;

char c;

signed main() {
    cin >> c;
    if (c >= 'a' && c <= 'z') {
        cout << (char)(c - 'a' + 'A') << "\n";
    } else {
        cout << (char)(c - 'A' + 'a') << "\n";
    }
    return 0;
}
