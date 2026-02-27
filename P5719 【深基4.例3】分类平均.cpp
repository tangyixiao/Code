#include <bits/stdc++.h>
using namespace std;
int n, k, suma, cnta, sumb, cntb;
double avea, aveb;
signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        if (i % k) {
            sumb += i;
            cntb++;
        } else {
            suma += i;
            cnta++;
        }
    }
    avea = suma * 1.0 / cnta;
    aveb = sumb * 1.0 / cntb;
    cout << fixed << setprecision(1) << avea << " " << aveb;
    return 0;
}