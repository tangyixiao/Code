#include <bits/stdc++.h>
using namespace std;

char s[1005];

signed main() {
    cin >> s;
    int n = strlen(s);
    for (int i = 0; i < n;) {
        int j = i;
        for (; j < n && s[j] == s[i]; j++) {
        }
        cout << j - i << s[i];
        i = j;
    }
    cout << "\n";
    return 0;
}
