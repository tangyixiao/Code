#include <bits/stdc++.h>
using namespace std;

double n, x, y, tot;
int k;

signed main() {
    cin >> n >> x >> y;
    tot = n * 100 + 1e-9;
    k = (int)((tot + y) / (x + y));
    while (k * x + (k - 1) * y > tot) {
        k--;
    }
    while ((k + 1) * x + k * y <= tot) {
        k++;
    }
    cout << k << "\n";
    return 0;
}
