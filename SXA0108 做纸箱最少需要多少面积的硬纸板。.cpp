#include <bits/stdc++.h>
using namespace std;

int a, b, c;

signed main() {
    cin >> a >> b >> c;
    cout << min(a * b + 2 * a * c + 2 * b * c, min(a * c + 2 * a * b + 2 * b * c, b * c + 2 * a * b + 2 * a * c)) << "\n";
    return 0;
}
