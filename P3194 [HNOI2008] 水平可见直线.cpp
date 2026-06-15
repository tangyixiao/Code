#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
int s[N], top, n, ans[N];
inline void read(int &x) {
    x = 0;
    char c;
    int sign = 1;
    do {
        c = getchar();
        if (c == '-')
            sign = -1;
    } while (c < '0' || c > '9');
    do {
        x = x * 10 + c - '0';
        c = getchar();
    } while (c <= '9' && c >= '0');
    x *= sign;
}
struct str {
    int a, b, id;
} a[N];
const bool cmp(str a, str b) {
    if (a.a != b.a)
        return a.a > b.a;
    else
        return a.b > b.b;
}
const bool cmop(int a, int b) { return a < b; }
double sol(int i, int j) { return (double)(a[i].b - a[j].b) / (double)(a[j].a - a[i].a); }
int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i].a);
        read(a[i].b);
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        if (a[i].a == a[i - 1].a && i != 1)
            continue;
        while (top > 1 && sol(s[top], i) >= sol(s[top], s[top - 1]))
            top--;
        s[++top] = i;
        ans[top] = a[i].id;
    }
    sort(ans, ans + top + 1, cmop);
    for (int i = 1; i <= top; i++)
        printf("%d ", ans[i]);
    return 0;
}