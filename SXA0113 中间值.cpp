#include <bits/stdc++.h>
using namespace std;
int n;
signed main() {
    cin >> n;
    if (n % 2 == 1) {
        cout << (n + 1) / 2 << "\n";
    } else {
        cout << n + 1 << "\n";
    }
    return 0;
}
