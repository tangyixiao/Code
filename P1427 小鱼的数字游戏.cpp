#include <bits/stdc++.h>
using namespace std;
inline void f() {
    int a;
    cin >> a;
    if (a == 0) {
        return;
    }
    f();
    cout << a << " ";
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    f();
    return 0;
}