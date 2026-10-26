#include <bits/stdc++.h>
using namespace std;

int s;

signed main() {
    cin >> s;
    if (s >= 90) {
        cout << "excellent" << "\n";
    } else if (s >= 80) {
        cout << "good" << "\n";
    } else if (s >= 60) {
        cout << "pass" << "\n";
    } else {
        cout << "fail" << "\n";
    }
    return 0;
}
