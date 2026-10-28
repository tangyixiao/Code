#include <bits/stdc++.h>
using namespace std;
int n, a, b;
signed main() {
    cin >> n;
    a = n / 100, b = n % 100;
    cout << (a + b) * (a + b) << "\n";
    return 0;
}
