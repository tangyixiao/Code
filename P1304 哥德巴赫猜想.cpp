#include <bits/stdc++.h>
using namespace std;
int n;
bool is_prime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}
int main() {
    cin >> n;
    for (int i = 4; i <= n; i += 2) {
        for (int j = 2; j <= i / 2; j++) {
            if (is_prime(i - j) && is_prime(j)) {
                cout << i << "=" << j << "+" << i - j << endl;
                break;
            }
        }
    }
    return 0;
}