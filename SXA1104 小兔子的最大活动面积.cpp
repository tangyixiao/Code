#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a = n / 4, b = n / 2 - a;
    cout << a * b << "\n";
    return 0;
}
