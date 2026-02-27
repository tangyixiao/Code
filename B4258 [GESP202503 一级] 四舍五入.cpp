#include <bits/stdc++.h>
using namespace std;
int n;
double x;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        x = round(x / 10) * 10;
        cout << x << "\n";
    }

    return 0;
}