#include <bits/stdc++.h>
using namespace std;
int n, a[500001], x;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        x ^= a[i];
    }
    if (!x) {
        cout << "lose";
        exit(0);
    }
    for (int i = 1; i <= n; i++) {
        if ((a[i] ^ x) < a[i]) {
            cout << a[i] - (a[i] ^ x) << " " << i << "\n";
            a[i] ^= x;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
