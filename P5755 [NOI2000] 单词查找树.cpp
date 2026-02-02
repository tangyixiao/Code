#include <bits/stdc++.h>
using namespace std;
const int N = 114514;
string s[N];
int n, ans;
int main() {
    for (; cin >> s[++n];) {
    }
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            ans += s[i].size();
            continue;
        }
        int tmp;
        for (tmp = 0; s[i][tmp] == s[i - 1][tmp] && tmp < s[i - 1].size(); tmp++)
            ;
        ans += s[i].size() - tmp;
    }
    printf("%d", ++ans);
    return 0;
}
