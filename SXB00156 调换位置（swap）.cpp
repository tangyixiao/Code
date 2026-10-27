#include <bits/stdc++.h>
using namespace std;
string s;
int p;
signed main() {
    cin >> s;
    p = s.find(',');
    cout << s.substr(p + 1) << "," << s.substr(0, p) << "\n";
    return 0;
}
