#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int T, kmp[N], la, lb, ans;
string a, b;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (cin >> T; T--; ans = 0) {
        cin >> a;
        cin >> b;
        a = " " + a;
        b = " " + b;
        swap(a, b);
        memset(kmp, 0, sizeof(kmp));
        la = a.size();
        lb = b.size();
        for (int i = 2, j = 0; i <= lb; i++) {
            while (j && b[i] != b[j + 1]) {
                j = kmp[j];
            }
            if (b[j + 1] == b[i]) {
                
                j++;
            }
            kmp[i] = j;
        }
        for (int i = 1, j = 0; i <= la; i++) {
            while (j > 0 && b[j + 1] != a[i]) {
                j = kmp[j];
            }
            if (b[j + 1] == a[i]) {
                j++;
            }
            if (j == lb) {
                j = kmp[j];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}