#include <bits/stdc++.h>
using namespace std;

long long m, s;
int n;

signed main() {
    cin >> m;
    while (s <= m) {
        n++;
        s += 1 + (long long)n * (n - 1) / 2;
    }
    cout << n << "\n";
    return 0;
}
