#include <bits/stdc++.h>
using namespace std;

char s[1005];
int a[1005], c;

signed main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        a[c++] = s[i] - '0';
    }
    for (int i = 0; i < c; i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
