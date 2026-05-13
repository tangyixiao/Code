#include <bits/stdc++.h>
using namespace std;
signed main() {
    int a[4];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[1] - a[0] == a[2] - a[1])
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}