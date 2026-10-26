#include <bits/stdc++.h>
using namespace std;
string s;
long long ssum, num;
signed main() {
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '+') {
            ssum += num, num = 0;
        } else {
            num = num * 10 + (s[i] - '0');
        }
    }
    ssum += num;
    cout << ssum << "\n";
    return 0;
}
