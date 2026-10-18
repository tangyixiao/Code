#include <bits/stdc++.h>
using namespace std;

const int N = 205;
char s[N];

signed main() {
    cin.getline(s, N);
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            cout << char((s[i] - 'A' - 5 + 26) % 26 + 'A');
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            cout << char((s[i] - 'a' - 5 + 26) % 26 + 'a');
        } else {
            cout << s[i];
        }
    }
    cout << "\n";
    return 0;
}