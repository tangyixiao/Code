#include <bits/stdc++.h>
using namespace std;
int n;
long long f(int k) {
    if (k <= 1) {
        return 1;
    }
    return k * f(k - 1);
}
signed main() {
    cin >> n;
    cout << f(n) << "\n";
    return 0;
}
