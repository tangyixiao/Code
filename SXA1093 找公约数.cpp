#include <bits/stdc++.h>
using namespace std;

int a, b;

signed main() {
    cin >> a >> b;
    int g = __gcd(a, b);
    for (int i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            cout << i << "\n";
        }
    }
    for (int i = sqrt(g); i >= 1; i--) {
        if (g % i == 0 && i * i != g) {
            cout << g / i << "\n";
        }
    }
    return 0;
}
