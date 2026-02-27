#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10, M = 7e6 + 10;

LL q1[N], q2[M], q3[M];
int h1, t1, h2, t2, h3, t3;
int n, m, Q, u, v, t;
LL delta;

LL get_max() {
    LL res = -1e18;
    int k = 0;
    if (h1 < t1 && q1[h1] + delta > res) {
        res = q1[h1] + delta;
        k = 1;
    }
    if (h2 < t2 && q2[h2] + delta > res) {
        res = q2[h2] + delta;
        k = 2;
    }
    if (h3 < t3 && q3[h3] + delta > res) {
        res = q3[h3] + delta;
        k = 3;
    }
    if (k == 1)
        h1++;
    else if (k == 2)
        h2++;
    else if (k == 3)
        h3++;
    return res;
}

int main() {
    scanf("%d%d%d%d%d%d", &n, &m, &Q, &u, &v, &t);

    vector<LL> a(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);

    sort(a.begin(), a.end(), greater<LL>());

    h1 = t1 = h2 = t2 = h3 = t3 = 0;
    for (int i = 0; i < n; i++)
        q1[t1++] = a[i];
    delta = 0;

    vector<LL> ans;
    for (int i = 1; i <= m; i++) {
        LL x = get_max();
        if (i % t == 0)
            ans.push_back(x);

        LL len1 = x * u / v; 
        LL len2 = x - len1;  
        q2[t2++] = len1 - delta - Q;
        q3[t3++] = len2 - delta - Q;

        delta += Q; 
    }

    for (size_t i = 0; i < ans.size(); i++) {
        if (i)
            putchar(' ');
        printf("%lld", ans[i]);
    }
    putchar('\n');

    vector<LL> res;
    int cnt = 0;
    while (h1 < t1 || h2 < t2 || h3 < t3) {
        LL x = get_max();
        cnt++;
        if (cnt % t == 0)
            res.push_back(x);
    }
    for (size_t i = 0; i < res.size(); i++) {
        if (i)
            putchar(' ');
        printf("%lld", res[i]);
    }
    putchar('\n');

    return 0;
}