#include <bits/stdc++.h>
using namespace std;
int n;
inline int mod(string a1) {
    register int i;
    int b = 0, len = a1.size();
    for (i = 0; i < len; ++i) {
        b = ((b << 1) + (b << 3) + (a1[i] ^ 48)) % n;
    }
    return b;
}
inline string chu(string a1) {
    register int i, j;
    int s[10001], b = 0, len = a1.size();
    for (i = 0; i < len; ++i) {
        s[i] = ((b << 1) + (b << 3) + (a1[i] ^ 48)) / n;
        b = ((b << 1) + (b << 3) + (a1[i] ^ 48)) % n;
    }
    i = 0;
    while (!s[i] && i < len) {
        ++i;
    }
    a1 = "";
    while (i < len) {
        a1 += s[i] + '0';
        ++i;
    }
    return a1;
}
string p;
bool v[10005];
queue<string> q;
int main() {
    scanf("%d", &n);
    p = "1";
    q.push(p);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        if (!mod(p)) {
            cout << chu(p) << " " << p;
            return 0;
        }
        if (!v[mod(p + "0")]) {
            v[mod(p + "0")] = true;
            q.push(p + "0");
        }
        if (!v[mod(p + "1")]) {
            v[mod(p + "1")] = true;
            q.push(p + "1");
        }
    }
    return 0;
}
