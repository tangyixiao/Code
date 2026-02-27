#include <bits/stdc++.h>
using namespace std;
int task;
const int N = 9e5 + 5;
const int n = 100;
const int inf = 2e9;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> task;
    if (task == 1) {
        cout << inf << " " << inf << "\n";
    } else if (task == 2) {
        for (int i = 1; i <= N; i++) {
            cout << 'a';
        }
    } else if (task == 3) {
        cout << n << "\n";
        int f = -1;
        for (int i = 1; i <= n; i++) {
            cout << f << " ";
            f = -f;
        }
    }
    return 0;
}
