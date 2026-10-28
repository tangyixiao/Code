#include <bits/stdc++.h>
using namespace std;

int n, c1, c2;
double m[45], f[45];
char s[20];

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        double h;
        cin >> s >> h;
        if (s[0] == 'm') {
            m[c1++] = h;
        } else {
            f[c2++] = h;
        }
    }
    sort(m, m + c1);
    sort(f, f + c2);
    cout << fixed << setprecision(2);
    for (int i = 0; i < c1; i++) {
        cout << m[i] << " ";
    }
    for (int i = c2 - 1; i >= 0; i--) {
        cout << f[i];
        if (i != 0) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
