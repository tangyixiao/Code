#include <bits/stdc++.h>
using namespace std;

int x;

signed main() {
    cin >> x;
    int a = !(x % 2), b = x > 4 && x <= 12;
    cout << (a && b) << " " << (a || b) << " " << (a != b) << " " << (!a && !b)
         << "\n";
    return 0;
}