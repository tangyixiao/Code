#include <bits/stdc++.h>
using namespace std;
char s[1005];
signed main() {
    cin.getline(s, 1005);
    int i, len = strlen(s);
    for (i = 0; i < len; i++) {
        if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
            cout << (char)toupper(s[i]);
        }
    }
    cout << "\n";
    return 0;
}
