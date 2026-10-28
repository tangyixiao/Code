#include <bits/stdc++.h>
using namespace std;
string s, r;
int st;
bool palin(string t) {
    string u = t;
    reverse(u.begin(), u.end());
    return u == t;
}
void addone(string a, string b, string &c) {
    c.clear();
    int i = (int)a.size() - 1, j = (int)b.size() - 1, car = 0;
    while (i >= 0 || j >= 0 || car) {
        int s = car;
        if (i >= 0) {
            s += a[i] - '0', i--;
        }
        if (j >= 0) {
            s += b[j] - '0', j--;
        }
        c.push_back('0' + s % 10), car = s / 10;
    }
    reverse(c.begin(), c.end());
}
signed main() {
    cin >> s;
    for (; !palin(s) && st <= 30;) {
        r = s;
        reverse(r.begin(), r.end());
        addone(s, r, s);
        st++;
    }
    if (st <= 30 && palin(s)) {
        cout << st << "\n";
    } else {
        cout << "Impossible" << "\n";
    }
    return 0;
}
