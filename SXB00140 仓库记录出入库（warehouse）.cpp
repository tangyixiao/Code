#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int a[N];

signed main() {
    int n, k, c = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> k;
    for (int i = 1; i <= n; i++) {
        int s = 0;
        for (int j = i; j <= n; j++) {
            s += a[j];
            if (s == k) {
                c++;
            }
        }
    }
    cout << c << "\n";
    return 0;
}
