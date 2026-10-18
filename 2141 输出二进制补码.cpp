#include <bits/stdc++.h>
using namespace std;

signed main() {
    int a;
    cin >> a;
    for (int i = 31; i >= 0; i--) {
        cout << ((a >> i) & 1);
    }
    cout << "\n";
    return 0;
}
