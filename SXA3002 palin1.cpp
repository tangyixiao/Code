#include <bits/stdc++.h>
using namespace std;
string s, r, t;
int st;
bool palin(const string &a) {
    string u = a;
    reverse(u.begin(), u.end());
    return u == a;
}
string add(string a, string b) {
    string c;
    int i = (int)a.size() - 1, j = (int)b.size() - 1, car = 0;
    while (i >= 0 || j >= 0 || car) {
        int x = car;
        if (i >= 0) {
            x += a[i] - '0', i--;
        }
        if (j >= 0) {
            x += b[j] - '0', j--;
        }
        c.push_back('0' + x % 10), car = x / 10;
    }
    reverse(c.begin(), c.end());
    return c;
}
signed main() {
    cin >> s;
    for (; !palin(s) && st < 30;) {
        r = s;
        reverse(r.begin(), r.end());
        t = add(s, r);
        cout << s << "+" << r << "=" << t << "\n";
        s = t;
        st++;
    }
    if (palin(s)) {
        cout << st << "\n";
    } else {
        cout << "Impossible" << "\n";
    }
    return 0;
}
