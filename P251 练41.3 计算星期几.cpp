#include <bits/stdc++.h>
using namespace std;

const int M = 7;
char *s[] = {"Sunday", "Monday", "Tuesday", "Wednesday",
             "Thursday", "Friday", "Saturday"};
long long a, b;

signed main() {
    cin >> a >> b, a %= M;
    long long r = 1;
    for (; b; b >>= 1, a = a * a % M) {
        if (b & 1) {
            r = r * a % M;
        }
    }
    cout << s[r] << "\n";
    return 0;
}