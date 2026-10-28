#include <bits/stdc++.h>
using namespace std;

string a, b, c;

string sub(string x, string y) {
    int i = (int)x.size() - 1, j = (int)y.size() - 1, t = 0;
    string r;
    for (; i >= 0;) {
        int d = x[i] - '0' - t;
        if (j >= 0) {
            d -= y[j] - '0';
        }
        if (d < 0) {
            d += 10;
            t = 1;
        } else {
            t = 0;
        }
        r += (char)('0' + d);
        i--;
        j--;
    }
    for (; r.size() > 1 && r.back() == '0';) {
        r.pop_back();
    }
    reverse(r.begin(), r.end());
    return r;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    for (; a.size() > 1 && a[0] == '0';) {
        a.erase(a.begin());
    }
    for (; b.size() > 1 && b[0] == '0';) {
        b.erase(b.begin());
    }
    bool neg = false;
    if (a.size() != b.size()) {
        neg = a.size() < b.size();
    } else if (a != b) {
        neg = a < b;
    }
    if (neg) {
        c = sub(b, a);
        cout << '-';
    } else {
        c = sub(a, b);
    }
    cout << c << "\n";
    return 0;
}
