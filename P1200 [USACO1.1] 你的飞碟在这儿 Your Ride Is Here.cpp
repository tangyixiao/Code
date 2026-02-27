#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
string a, b;
int suma = 1, sumb = 1;
signed main() {
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        suma *= (a[i] - 'A' + 1);
    }
    for (int i = 0; i < b.size(); i++) {
        sumb *= (b[i] - 'A' + 1);
    }
    if ((suma % 47) == (sumb % 47)) {
        cout << "GO\n";
    } else {
        cout << "STAY\n";
    }
    return 0;
}