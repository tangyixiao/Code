#include <bits/stdc++.h>
using namespace std;

int t, n, a, b, c;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        a = 0, b = 0, c = 0;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            if (x == 0) {
                ++a;
            } else {
                if (x == 1) {
                    ++b;
                } else {
                    ++c;
                }
            }
        }
        cout << a + min(b, c) + abs(b - c) / 3 << '\n';
    }
    return 0;
}