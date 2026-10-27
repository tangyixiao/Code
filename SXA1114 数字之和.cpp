#include <bits/stdc++.h>
using namespace std;
long long n, s;
signed main() {
    cin >> n;
    for (; n > 0;) {
        if (n % 10 >= 5) {
            s += n % 10;
        }
        n /= 10;
    }
    cout << s << "\n";
    return 0;
}
