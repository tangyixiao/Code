#include <bits/stdc++.h>
using namespace std;
string s, s1, s2;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            s1 += s[i];
        }
    }
    sort(s1.begin(), s1.end());
    int id = s1.size() - 1;
    for (; id >= 0 && s1[id] == '0'; id--)
        ;
    s2 = s1.substr(0, id + 1);
    reverse(s2.begin(), s2.end());
    cout << s2;
    return 0;
}