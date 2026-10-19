#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 100; i *= 10) {
        cout << n / i % 10;
    }
    cout << "\n";
    return 0;
}
