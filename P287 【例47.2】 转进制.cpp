#include <bits/stdc++.h>
using namespace std;

long long x;
int m;
char h[] = "0123456789ABCDEF";

void f(long long v) {
    if (v < m) {
        cout << h[v];
    } else {
        f(v / m), cout << h[v % m];
    }
}

signed main() {
    cin >> x >> m;
    f(x);
    cout << "\n";
    return 0;
}