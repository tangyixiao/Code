#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

char s[N];

signed main() {
    cin.getline(s, N);
    int c = 0;
    for (int i = 0; s[i]; i++) {
        c += s[i] >= '0' && s[i] <= '9';
    }
    cout << c << "\n";
    return 0;
}
