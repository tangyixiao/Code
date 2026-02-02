#include <bits/stdc++.h>
using namespace std;
int a;
inline void y(int x) {
    x += 5;
    x *= 3;
    cout << x << " ";
    return;
}
inline void l(int x) {
    x *= 3;
    x += 5;
    cout << x << " ";
    return;
}
signed main() {
    cin >> a;
    y(a);
    l(a);
    return 0;
}