#include <bits/stdc++.h>
using namespace std;
int n, R;
string s;
int main() {
    cin >> n >> R;
    for (; n; n /= R) {
        if (n % R < 10) {
            s += to_string(n % R);
        } else {
            s += ('A' + n % R - 10);
        }
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}