#include <bits/stdc++.h>
using namespace std;

const int N = 205;
char s[N];

signed main() {
    cin.getline(s, N);
    for (int i = 0; s[i]; i++) {
        if (s[i] == ' ' && i && s[i - 1] == ' ') {
            continue;
        }
        cout << s[i];
    }
    cout << "\n";
    return 0;
}