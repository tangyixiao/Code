#include <bits/stdc++.h>
using namespace std;
long long n, r;
signed main() {
    cin >> n;
    r = (long long)(sqrt((double)n) + 0.5);
    if (r * r == n) {
        cout << "Y" << "\n";
    } else {
        cout << "N" << "\n";
    }
    return 0;
}
