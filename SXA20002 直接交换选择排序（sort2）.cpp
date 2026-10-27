#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;
int n, a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[j] < a[i]) {
                swap(a[i], a[j]);
            }
        }
        for (int j = 1; j <= n; j++) {
            cout << a[j];
            if (j < n) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
