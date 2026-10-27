#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (i) {
            cout << ' ';
        }
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
