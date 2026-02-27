#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
int n, a[N];
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
        for (int j = 1; j <= n; j++) {
            cout << a[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}