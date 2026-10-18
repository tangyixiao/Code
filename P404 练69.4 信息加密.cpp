#include <bits/stdc++.h>
using namespace std;

const int N = 105;
char s[N];

signed main() {
    cin >> s;
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = char((s[i] - 'a' + 3) % 26 + 'a');
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = char((s[i] - 'A' + 3) % 26 + 'A');
        }
    }
    cout << s << "\n";
    return 0;
}