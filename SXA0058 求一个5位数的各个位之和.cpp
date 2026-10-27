#include <bits/stdc++.h>
using namespace std;
int n, s;
signed main() {
    cin >> n;
    for (int i = 0; i < 5; i++) {
        s += n % 10, n /= 10;
    }
    cout << s << "\n";
    return 0;
}
