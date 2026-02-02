#include <bits/stdc++.h>
using namespace std;
string s;
char ans[100080];
int han, h, len, pd1, pd2;
int check() {
    if (han == 1 || han == h)
        return pd1 + (h - 1) * 2;
    else {
        if (pd2 % 2 == 1)
            return pd1 + (h - han) * 2;
        else
            return pd1 + 2 * (han - 1);
    }
}
int main() {
    cin >> h;
    cin >> s;
    len = s.size();
    s = " " + s;
    han = pd1 = pd2 = 1;
    for (int i = 1; i <= len; i++) {
        ans[pd1] = s[i];
        pd1 = check();
        pd2++;
        if (pd1 > len) {
            han++;
            pd1 = han;
            pd2 = 1;
        }
    }
    for (int i = 1; i <= len; i++)
        cout << ans[i];
    return 0;
}
