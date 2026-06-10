#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    bool p[128] = {}, n[128] = {}, e[128] = {};
    for (int i = 0; i < s.size();) {
        if (s[i] == '|') {
            ++i;
            continue;
        }
        bool f = 0;
        if (s[i] == '~')
            f = 1, ++i;
        char c = s[i++];
        e[c] = 1;
        f ? n[c] = 1 : p[c] = 1;
    }
    int v = 0;
    for (int c = 'A'; c <= 'Z'; ++c)
        v += e[c];
    for (int c = 'a'; c <= 'z'; ++c)
        v += e[c];
    bool g = 0;
    for (int c = 'A'; c <= 'Z'; ++c)
        if (p[c] && n[c])
            g = 1;
    for (int c = 'a'; c <= 'z'; ++c)
        if (p[c] && n[c])
            g = 1;
    unsigned long long ans = g ? (1ULL << v) : ((1ULL << v) - 1);
    cout << ans << '\n';
    return 0;
}