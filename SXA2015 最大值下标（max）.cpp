#include <bits/stdc++.h>
using namespace std;

int n, x, mx = -1, id;

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > mx) {
            mx = x;
            id = i;
        }
    }
    cout << id << "\n";
    return 0;
}
