#include <bits/stdc++.h>
using namespace std;

const int N = 45;
int n;
double h[N];
string g[N], s;
double mh[N], fh[N];
int cm, cf;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> g[i] >> h[i];
        if (g[i] == "male") {
            mh[++cm] = h[i];
        } else {
            fh[++cf] = h[i];
        }
    }
    sort(mh + 1, mh + cm + 1);
    sort(fh + 1, fh + cf + 1);
    cout << fixed << setprecision(2);
    int first = 1;
    for (int i = 1; i <= cm; i++) {
        if (!first) {
            cout << " ";
        }
        first = 0;
        cout << mh[i];
    }
    for (int i = cf; i >= 1; i--) {
        if (!first) {
            cout << " ";
        }
        first = 0;
        cout << fh[i];
    }
    cout << "\n";
    return 0;
}
