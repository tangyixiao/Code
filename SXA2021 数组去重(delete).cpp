#include <bits/stdc++.h>
using namespace std;

int n;
int a[10005];
bool v[10000005];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!v[a[i]]) {
            v[a[i]] = true;
            if (cnt) {
                cout << " ";
            }
            cout << a[i];
            cnt++;
        }
    }
    cout << "\n";
    return 0;
}
