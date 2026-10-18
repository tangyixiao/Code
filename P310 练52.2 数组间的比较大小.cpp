#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int a[N], b[N];

signed main() {
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < N; i++) {
        x += a[i] > b[i], y += a[i] == b[i], z += a[i] < b[i];
    }
    cout << x << " " << y << " " << z << "\n";
    cout << (x > z ? "a>b" : x < z ? "a<b"
                                   : "a=b")
         << "\n";
    return 0;
}