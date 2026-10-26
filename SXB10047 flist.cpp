#include <bits/stdc++.h>
using namespace std;
string in, lv, res;
void go(string li, string ll) {
    if (li.size() == 0) {
        return;
    }
    char r = ll[0];
    int p = li.find(r), i;
    string ln = li.substr(0, p), rn = li.substr(p + 1), l1, l2;
    for (i = 0; i < (int)ll.size(); i++) {
        if (ln.find(ll[i]) != string::npos) {
            l1 += ll[i];
        } else if (rn.find(ll[i]) != string::npos) {
            l2 += ll[i];
        }
    }
    res += r;
    go(ln, l1);
    go(rn, l2);
}
signed main() {
    cin >> in >> lv;
    go(in, lv);
    cout << res << "\n";
    return 0;
}
