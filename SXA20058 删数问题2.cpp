#include <bits/stdc++.h>
using namespace std;

char s[305], st[305];
int k, i, top, del;

signed main() {
    cin >> s >> k;
    top = 0;
    del = k;
    for (i = 0; s[i]; i++) {
        while (top > 0 && del > 0 && st[top - 1] > s[i]) {
            top--;
            del--;
        }
        st[top] = s[i];
        top++;
    }
    int keep = top - del;
    int p = 0;
    while (p < keep - 1 && st[p] == '0') {
        p++;
    }
    for (i = p; i < keep; i++) {
        cout << st[i];
    }
    cout << "\n";
    return 0;
}
