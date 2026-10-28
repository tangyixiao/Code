#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    int a = n / 100, b = n / 10 % 10, c = n % 10;
    cout << max(a, max(b, c)) - min(a, min(b, c)) << "\n";
    return 0;
}
