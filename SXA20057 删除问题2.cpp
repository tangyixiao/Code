#include <bits/stdc++.h>
using namespace std;

const int N = 250 + 5;
string s;
int k, top;
char st[N];

signed main() {
    cin >> s;
    cin >> k;
    for (int i = 0; i < (int)s.size(); i++) {
        for (; top > 0 && k > 0 && st[top - 1] < s[i];) {
            top--;
            k--;
        }
        st[top++] = s[i];
    }
    for (; k > 0 && top > 0;) {
        top--;
        k--;
    }
    st[top] = 0;
    if (top == 0) {
        cout << 0 << "\n";
    } else {
        cout << st << "\n";
    }
    return 0;
}
