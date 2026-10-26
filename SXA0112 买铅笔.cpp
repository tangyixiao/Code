#include <bits/stdc++.h>
using namespace std;

int p[5];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> p[0];
    for (int i = 1; i <= 3; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = i + 1; j <= 3; j++) {
            if (p[j] < p[i]) {
                swap(p[i], p[j]);
            }
        }
    }
    cout << p[0] / p[2] << " " << p[0] % p[2] << "\n";
    return 0;
}
