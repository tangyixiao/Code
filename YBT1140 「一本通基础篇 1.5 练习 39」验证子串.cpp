#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;

char a[N], b[N];

signed main() {
    cin >> a >> b;
    if (strstr(b, a)) {
        cout << a << " is substring of " << b << "\n";
    } else if (strstr(a, b)) {
        cout << b << " is substring of " << a << "\n";
    } else {
        cout << "No substring\n";
    }
    return 0;
}
