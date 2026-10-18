#include <bits/stdc++.h>
using namespace std;

int n;
char x;

signed main() {
    cin >> n >> x;
    int k = 1;
    for (; k * k * 2 - 1 <= n; k++);
    k--;
    for (int i = 0; i < 2 * k - 1; i++) {
        int t = min(i, 2 * k - 2 - i);
        for (int j = 0; j < t; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * k - 1 - 2 * t; j++) {
            cout << x;
        }
        cout << "\n";
    }
    cout << n - (k * k * 2 - 1) << "\n";
    return 0;
}