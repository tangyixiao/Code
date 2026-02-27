#include <bits/stdc++.h>
using namespace std;
int n;
inline void f(int x) {
    if (x == 1) {
        cout << x << " ";
        return;
    }
    f(x & 1 ? x * 3 + 1 : x / 2);
    cout << x << " ";
    return;
}
signed main() {
    cin >> n;
    f(n);
    return 0;
}