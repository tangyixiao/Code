#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, a[N];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        int t = a[i], j = i - 1;
        while (j >= 1 && a[j] > t) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;
        for (int k = 1; k <= n; k++) {
            cout << a[k];
            if (k < n) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
