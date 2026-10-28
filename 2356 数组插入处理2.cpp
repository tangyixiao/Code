#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, a, b, p[N];

signed main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = n + 1; i > b; i--) {
        p[i] = p[i - 1];
    }
    p[b] = a;
    for (int i = 1; i <= n + 1; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << p[i];
    }
    cout << "\n";
    return 0;
}
