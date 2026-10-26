#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, i, j, r;
int num[N], ord[N], rk[N];
double sc[N];

signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> num[i] >> sc[i];
        ord[i] = i;
    }
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            bool sw = false;
            if (sc[ord[j]] > sc[ord[i]]) {
                sw = true;
            } else if (sc[ord[j]] == sc[ord[i]] && num[ord[j]] > num[ord[i]]) {
                sw = true;
            }
            if (sw) {
                int t = ord[i];
                ord[i] = ord[j];
                ord[j] = t;
            }
        }
    }
    for (i = 1; i <= n; i++) {
        if (i == 1) {
            r = 1;
        } else if (sc[ord[i]] == sc[ord[i - 1]]) {
            r = rk[i - 1];
        } else {
            r = i;
        }
        rk[i] = r;
        cout << r << " " << num[ord[i]] << " " << sc[ord[i]] << "\n";
    }
    return 0;
}
