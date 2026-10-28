#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int a[N];

signed main() {
    int n, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    double ave = (double)s / n;
    cout << fixed << setprecision(1) << "AVE=" << ave << "\n";
    int f = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > ave) {
            if (!f) {
                cout << " ";
            }
            cout << i << ":" << a[i];
            f = 0;
        }
    }
    cout << "\n";
    return 0;
}
