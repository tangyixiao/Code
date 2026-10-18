#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    for (int i = -n; i <= n; i++) {
        cout << i << (i == n ? "\n" : " ");
    }
    return 0;
}
