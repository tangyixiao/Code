#include <bits/stdc++.h>
using namespace std;

int n;

signed main() {
    cin >> n;
    cout << n / 100 + n / 10 % 10 + n % 10 << "\n";
    return 0;
}
