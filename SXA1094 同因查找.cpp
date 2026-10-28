#include <bits/stdc++.h>
using namespace std;
int x, c;
signed main() {
    c = 0;
    for (x = 42; x <= 1000; x += 42) {
        if (c > 0) {
            if (c % 5 == 0) {
                cout << "\n";
            } else {
                cout << " ";
            }
        }
        cout << x;
        c++;
    }
    cout << "\n";
    return 0;
}
