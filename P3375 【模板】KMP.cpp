#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int kmp[N], la, lb;
char a[N], b[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> a + 1;
    cin >> b + 1;
    la = strlen(a + 1);
    lb = strlen(b + 1);
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
        while (j > 0 && b[j + 1] != a[i])
            j = kmp[j];
        if (b[j + 1] == a[i])
            j++;
        if (j == lb) {
            cout << i - lb + 1 << endl;
            j = kmp[j];
        }
    }

    for (int i = 1; i <= lb; i++) {
        cout << kmp[i] << " ";
    }
    return 0;
}