#include <bits/stdc++.h>
using namespace std;

int n;

signed main() {
    cin >> n;
    if (n < 10) {
        cout << "A" << "\n";
    } else if (n < 20) {
        cout << "B" << "\n";
    } else if (n < 40) {
        cout << "C" << "\n";
    } else if (n < 50) {
        cout << "D" << "\n";
    } else {
        cout << "E" << "\n";
    }
    return 0;
}
