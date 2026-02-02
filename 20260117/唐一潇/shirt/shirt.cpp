#include <bits/stdc++.h>
using namespace std;
int n, sum;
signed main() {
    freopen("shirt.in", "r", stdin);
    freopen("shirt.out", "w", stdout);
    cin >> n;
    sum = 20 * 12 * 9 * n + 15 * n;
    cout << sum / 240 << " ";
    sum %= 240;
    cout << sum / 12 << " ";
    sum %= 12;
    cout << sum;
    return 0;
}