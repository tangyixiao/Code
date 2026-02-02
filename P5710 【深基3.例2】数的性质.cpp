#include <bits/stdc++.h>
using namespace std;
int x;
bool flag1, flag2;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> x;
    flag1 = !(x & 1);
    flag2 = (x > 4 && x <= 12);
    cout << (flag1 && flag2) << " " << (flag1 || flag2) << " " << ((flag1 || flag2) && (flag1 ^ flag2)) << " " << (!(flag1 || flag2));
    return 0;
}