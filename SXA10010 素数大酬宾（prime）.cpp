#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, p[N];

signed main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (!p[i]) {
            cout << i;
            if (i < n) {
                cout << " ";
            }
            for (long long j = (long long)i * i; j <= n; j += i) {
                p[j] = 1;
            }
        }
    }
    cout << "\n";
    return 0;
}
