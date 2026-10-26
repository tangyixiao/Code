#include <bits/stdc++.h>
using namespace std;
int a, b;
signed main() {
    cin >> a >> b;
    while (b) {
        int t = a % b;
        a = b, b = t;
    }
    cout << a << "\n";
    return 0;
}
