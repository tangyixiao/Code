#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
char s[N], q[N];
int la, lb, n, i, j, st[N], top, ok, c;
signed main() {
    cin >> (s + 1) >> (q + 1);
    la = strlen(s + 1), lb = strlen(q + 1);
    for (i = 1; i + lb - 1 <= la; i++) {
        int cnt[26], cnt2[26];
        for (j = 0; j < 26; j++) {
            cnt[j] = 0, cnt2[j] = 0;
        }
        for (j = 0; j < lb; j++) {
            char a = tolower(s[i + j]), b = tolower(q[1 + j]);
            cnt[a - 'a']++, cnt2[b - 'a']++;
        }
        ok = 1;
        for (j = 0; j < 26; j++) {
            if (cnt[j] != cnt2[j]) {
                ok = 0;
            }
        }
        if (ok) {
            st[++top] = i - 1;
        }
    }
    if (!top) {
        cout << "NO\n";
    } else {
        for (i = 1; i <= top; i++) {
            if (i > 1) {
                cout << " ";
            }
            cout << st[i];
        }
        cout << "\n";
    }
    return 0;
}
