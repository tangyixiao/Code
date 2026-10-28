#include <bits/stdc++.h>
using namespace std;
int n, i;
signed main() {
    cin >> n;
    for (i = 2; i <= n; i += 3) {
        if (i > 2) {
            cout << " ";
        }
        cout << i;
    }
    cout << "\n";
    return 0;
}
