#include <bits/stdc++.h>
using namespace std;

int n, x, a, b, c;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x < 60) {
            a++;
        } else if (x < 80) {
            b++;
        } else {
            c++;
        }
    }
    cout << fixed << setprecision(2);
    cout << a * 100.0 / n << "%" << "\n";
    cout << b * 100.0 / n << "%" << "\n";
    cout << c * 100.0 / n << "%" << "\n";
    return 0;
}
