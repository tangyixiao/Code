#include <bits/stdc++.h>
using namespace std;
const int N = 2.2e7 + 5;
int n, m, ans, R[N];
char s[N], t[N];
signed main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    t[0] = '!', t[m = 1] = '@';
    for (int i = 1; i <= n; i++)
        t[++m] = s[i], t[++m] = '@'; 
    t[++m] = '#';
    for (int i = 1, c = 0, r = 0; i < m; i++) {          
        R[i] = r < i ? 1 : min(R[c * 2 - i], r - i + 1); 
        while (t[i - R[i]] == t[i + R[i]])
            R[i]++;
        ans = max(ans, R[i] - 1);
        if (i + R[i] - 1 > r)
            c = i, r = i + R[i] - 1; 
    }
    cout << ans << endl;
    return 0;
}