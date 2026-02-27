#include <bits/stdc++.h>
using namespace std;
struct node {
    int a;
    int b;
} a[1005];
bool cmp(node a, node b) {
    if (a.a != b.a)
        return a.a < b.a;
    else
        return a.b < b.b;
}
int main() {
    int n;
    double ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a;
        a[i].b = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        ans += a[i].a * (n - i);
    ans /= n;
    for (int i = 1; i <= n; i++)
        cout << a[i].b << " ";
    cout << endl;
    printf("%.2f\n", ans);
    return 0;
}