#include <bits/stdc++.h>
using namespace std;
signed main() {
    int n;
    cin >> n;
    if (n >= 10 && n <= 99 && n % 2 == 0) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
    return 0;
}
