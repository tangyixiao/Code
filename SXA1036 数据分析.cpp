#include <bits/stdc++.h>
using namespace std;
string s;
int i, c, sum;
signed main() {
    cin >> s;
    c = (int)s.size();
    for (i = 0; i < c; i++) {
        int d = s[i] - '0';
        if (d % 2 == 0) {
            sum += d;
        }
    }
    cout << c << " " << sum << "\n";
    return 0;
}
