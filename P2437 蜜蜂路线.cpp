#include <bits/stdc++.h>
using namespace std;
string a[1001] = {"0", "1", "1"};
int n, m;
string gjd(string a, string b) {
    string ans;
    int la[1000] = {0}, lb[1000] = {0};
    int lena = a.length(), lenb = b.length();
    for (int i = 0; i < lena; i++)
        la[lena - 1 - i] = a[i] - '0';
    for (int i = 0; i < lenb; i++)
        lb[lenb - 1 - i] = b[i] - '0';
    int lenc = max(lena, lenb);
    for (int i = 0; i < lenc; i++)
        la[i] += lb[i], la[i + 1] += la[i] / 10, la[i] %= 10;
    if (la[lenc])
        lenc++;
    for (int i = lenc - 1; i >= 0; i--)
        ans += la[i] + '0';
    return ans;
}
int main() {
    cin >> n >> m;
    int ans = m - n + 1;
    for (int i = 3; i <= ans; i++) {
        a[i] = gjd(a[i - 1], a[i - 2]);
    }
    cout << a[ans];
    return 0;
}