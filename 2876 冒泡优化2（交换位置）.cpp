#include <bits/stdc++.h>
using namespace std;

int n;
int a[505];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int last = n;
    for (; last > 1;) {
        int nl = 0;
        for (int j = 1; j < last; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                nl = j;
            }
        }
        if (nl == 0) {
            break;
        }
        for (int j = 1; j <= n; j++) {
            if (j > 1) {
                cout << " ";
            }
            cout << a[j];
        }
        cout << "\n";
        last = nl;
    }
    return 0;
}
