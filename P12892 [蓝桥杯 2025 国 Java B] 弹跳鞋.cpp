#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int n;
    cin >> n;
    int x = ceil((-1 + sqrt(1 + 8 * n)) / 2);
    while (((x + 1) * x / 2) % 2 != n % 2)
        x++;
    cout << x;
    return 0;
}
