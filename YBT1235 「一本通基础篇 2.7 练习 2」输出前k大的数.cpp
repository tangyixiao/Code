#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N], n, k;

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int p = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[p]) {
                p = j;
            }
        }
        swap(a[i], a[p]);
        cout << a[i] << "\n";
    }
    return 0;
}
