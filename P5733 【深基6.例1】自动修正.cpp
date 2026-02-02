#include <bits/stdc++.h>
using namespace std;
string s;
inline void recall(int i, char c) {
    s[i] = ((s[i] >= 'a' && s[i] <= 'z') ? c - 32 : c);
    return;
}
signed main() {
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        recall(i, s[i]);
    }
    cout << s;
    return 0;
}