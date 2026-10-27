#include <bits/stdc++.h>
using namespace std;

int n, r;

signed main() {
    cin >> n;
    r = n % 9;
    if (r == 0) {
        r = 9;
    }
    cout << r << "\n";
    return 0;
}
