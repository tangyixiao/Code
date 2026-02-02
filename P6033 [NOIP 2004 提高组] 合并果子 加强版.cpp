#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, b, c, cnt, s[2], a[100005], ans;
queue<int> q1, q2;
void read(int& x) {
    int f = 1;
    x = 0;
    char s = getchar();
    while (s < '0' || s > '9') {
        if (s == '-')
            f = -1;
        s = getchar();
    }
    while (s >= '0' && s <= '9') {
        x = x * 10 + s - '0';
        s = getchar();
    }
    x *= f;
}
int Add() {
    int x;
    if (q2.empty() || (!q1.empty() && q1.front() < q2.front())) {
        x = q1.front();
        q1.pop();
    } else {
        x = q2.front();
        q2.pop();
    }
    return x;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read(n);
    for (int i = 1; i <= n; ++i)
        read(b), ++a[b];
    for (int i = 1; i <= 100000; ++i)
        while (a[i]--)
            q1.push(i);
    while (--n) {
        b = Add();
        c = Add();
        ans += b + c;
        q2.push(b + c);
    }
    cout << ans;
}
