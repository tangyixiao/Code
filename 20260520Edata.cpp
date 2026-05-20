#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    freopen("20260520E1.in", "w", stdout);
    int n = 1000, h = 10000;
    cout << h << " " << n << "\n";
    for (int i = 1; i <= n; i++) {
        int r1 = rand() % 10000 + 1, r2 = rand() % 10000 + 1;
        cout << r1 << " " << r2 << "\n";
    }

    return 0;
}