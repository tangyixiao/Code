#include <bits/stdc++.h>
using namespace std;

int s;

signed main() {
    cin >> s;
    if (s >= 90) {
        cout << "Excellent" << "\n";
    } else if (s >= 80) {
        cout << "Good" << "\n";
    } else if (s >= 60) {
        cout << "Pass" << "\n";
    } else {
        cout << "Fail" << "\n";
    }
    return 0;
}
