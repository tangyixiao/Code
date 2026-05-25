#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int kmp[N], st[N], pos[N], la, lb, top, k;
string a, b;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> a >> b;
    la = a.size(), lb = b.size();
    a = " " + a, b = " " + b;
    for (int i = 2, j = 0; i <= lb; i++) {
        while (j && b[i] != b[j + 1]) {
            j = kmp[j];
        }
        if (b[j + 1] == b[i]) {
            j++;
        }
        kmp[i] = j;
    }
    for (int i = 1, j = 0; i <= la; ++i) {
        while (j && a[i] != b[j + 1]) {
            j = kmp[j];
        }
        if (a[i] == b[j + 1]) {
            j++;
        }
        pos[i] = j;
        st[++top] = i;
        if (j == lb) {
            top = top - lb;
            j = pos[st[top]];
        }
    }
    for (int i = 1; i <= top; i++) {
        printf("%c", a[st[i]]);
    }
    return 0;
}