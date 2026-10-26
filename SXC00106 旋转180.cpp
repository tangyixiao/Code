#include <bits/stdc++.h>
using namespace std;

char s[100005];

signed main() {
    cin >> s;
    int n = strlen(s);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '6') {
            cout << '9';
        } else if (s[i] == '9') {
            cout << '6';
        } else {
            cout << s[i];
        }
    }
    cout << "\n";
    return 0;
}
