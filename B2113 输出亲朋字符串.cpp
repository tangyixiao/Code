#include <bits/stdc++.h>
using namespace std;
string s1, s2;
signed main() {
    cin >> s1;
    for (int i = 0; i < s1.size() - 1; i++) {
        s2 += (s1[i] + s1[i + 1]);
    }
    s2 += (s1[s1.size() - 1] + s1[0]);
    cout << s2;
    return 0;
}