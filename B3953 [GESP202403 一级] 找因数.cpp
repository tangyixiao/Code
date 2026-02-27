#include <bits/stdc++.h>
using namespace std;
int n;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (!(n % i)) {
            cout << i << "\n";
        }
    }
    return 0;
}