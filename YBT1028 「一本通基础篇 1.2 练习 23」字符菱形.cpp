#include <bits/stdc++.h>
using namespace std;

signed main() {
    char c;
    cin >> c;
    for (int i = 0; i < 5; i++) {
        int k = i <= 2 ? i : 4 - i;
        for (int j = 0; j < 2 - k; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * k + 1; j++) {
            cout << c;
        }
        cout << "\n";
    }
    return 0;
}
