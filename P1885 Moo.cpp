#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[1000000];
char s1(int n, int t) {
    if (t == 0) {
        if (n == 1)
            return 'm';
        if (n == 2)
            return 'o';
        if (n == 3)
            return 'o';
    }
    if (n <= a[t - 1])
        return s1(n, t - 1);
    if (n == a[t - 1] + 1)
        return 'm';
    if (n > a[t] - a[t - 1])
        return s1(n - (a[t] - a[t - 1]), t - 1);
    return 'o';
}
int s(int x) {
    int su = 3;
    int t1 = 1;
    while (su < x) {
        su = su * 2 + 1 + t1 + 2;
        a[t1] = su;
        t1++;
    }
    return t1 - 1;
}
signed main() {
    cin >> n;
    a[0] = 3;
    int t = s(n);
    cout << s1(n, t);
    return 0;
}
