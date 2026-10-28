#include <bits/stdc++.h>
using namespace std;

string s;

signed main() {
    cin >> s;
    int i = 0, n = s.size();
    while (i < n) {
        int j = i;
        while (j < n && s[j] == s[i]) {
            j++;
        }
        if (j - i == 1) {
            cout << s[i];
        } else {
            cout << j - i << s[i];
        }
        i = j;
    }
    cout << "\n";
    return 0;
}
