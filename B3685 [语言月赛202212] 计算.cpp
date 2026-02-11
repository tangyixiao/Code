#include <bits/stdc++.h>
using namespace std;
int n, suma;
signed main() {
    cin >> n;
    for (; n; n /= 10) {
        suma += n % 10;
    }
    cout << suma << "\n" << suma * suma << "\n" << suma * suma * suma << endl;
    return 0;
}