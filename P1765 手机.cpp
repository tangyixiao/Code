#include <bits/stdc++.h>
using namespace std;
string s;
int ans, num[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
signed main() {
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            ans++;
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            ans += num[s[i] - 'a'];
        }
    }
    printf("%d", ans);
    return 0;
}