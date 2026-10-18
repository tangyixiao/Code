#include <bits/stdc++.h>
using namespace std;

const int N = 105;
char s[N], w[N][N];
int n, k;

signed main() {
    cin.getline(s, N);
    for (int i = 0; s[i]; i++) {
        if (s[i] == ' ') {
            w[n][k] = 0, n++, k = 0;
        } else {
            w[n][k++] = s[i];
        }
    }
    w[n][k] = 0, n++;
    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1) {
            cout << " ";
        }
        cout << w[i];
    }
    cout << "\n";
    return 0;
}