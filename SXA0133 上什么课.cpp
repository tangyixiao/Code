#include <bits/stdc++.h>
using namespace std;

int n;

signed main() {
    cin >> n;
    if (n == 1) {
        cout << "swim\n";
    } else if (n == 3) {
        cout << "program\n";
    } else if (n == 5) {
        cout << "read\n";
    } else if (n == 6) {
        cout << "math\n";
    } else {
        cout << "rest\n";
    }
    return 0;
}
