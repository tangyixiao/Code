#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    int s = 2 * n - 1 + 4;
    cout << fixed << setprecision(1) << s * 100.0 / (n * n) << "%" << "\n";
    return 0;
}
