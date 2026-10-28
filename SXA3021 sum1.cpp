#include <bits/stdc++.h>
using namespace std;
double m, s;
int n;
signed main() {
    cin >> m;
    while (s <= m) {
        n++;
        s += 1.0 / n;
    }
    cout << n << "\n";
    return 0;
}
