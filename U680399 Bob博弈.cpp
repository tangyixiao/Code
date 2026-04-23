#include <bits/stdc++.h>
using namespace std;
int T, n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        int sg = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x && (x & (x - 1)))
                sg ^= 1;
        }
        cout << (sg ? "YE5\n" : "N0\n");
    }
    return 0;
}