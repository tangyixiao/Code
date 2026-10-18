#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    for (int i = 3; i <= n; i += 3) {
        cout << i << (i + 3 > n ? "\n" : " ");
    }
    return 0;
}
