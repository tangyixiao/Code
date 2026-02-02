#include <bits/stdc++.h>
using namespace std;
const double step1 = 150, step2 = 400;
const double price1 = 0.4463, price2 = 0.4663, price3 = 0.5663;
double n, ans;
signed main() {
    cin >> n;
    if (n <= step1) {
        ans = n * price1;
    } else {
        if (n <= step2) {
            ans = step1 * price1 + (n - step1) * price2;
        } else {
            ans = step1 * price1 + (step2 - step1) * price2 + (n - step2) * price3;
        }
    }
    cout << fixed << setprecision(1) << ans;
    return 0;
}