#include <bits/stdc++.h>
using namespace std;

int n;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            cout << " ";
        }
        for (int j = 1; j <= n - i + 1; j++) {
            cout << "#";
        }
        cout << "\n";
    }
    return 0;
}
