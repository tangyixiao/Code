#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;

int T, a[N], n, pos[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("pali.in", "r", stdin);
    freopen("pali.out", "w", stdout);

    cin >> T;
    while (T--) {
        cin >> n;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            pos[i] = -1;
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            if (flag) {
                break;
            }
            if (pos[a[i]] != -1) {
                if (i - pos[a[i]] >= 2) {
                    flag = true;
                }
            } else {
                pos[a[i]] = i;
            }
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}