#include <bits/stdc++.h>
using namespace std;
int a[4];
string s;
signed main() {
    cin >> a[0] >> a[1] >> a[2] >> s;
    sort(a, a + 3);
    cout << a[s[0] - 'A'] << " " << a[s[1] - 'A'] << " " << a[s[2] - 'A'];
    return 0;
}