#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define maxn 2005
using namespace std;
int mid;
int n, m;
int mouth[maxn], cake[maxn];
int tot = 0, space;
int sum[maxn], fcake[maxn];
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
bool dfs(int deep, int pos) {
    if (deep <= 0)
        return 1;
    if (tot - space < sum[mid])
        return 0;
    for (int i = pos; i <= n; ++i) {
        if (fcake[i] >= mouth[deep]) {
            fcake[i] -= mouth[deep];
            if (fcake[i] < mouth[1])
                space += fcake[i];
            if (mouth[deep] == mouth[deep - 1]) {
                if (dfs(deep - 1, i))
                    return 1;
            } else if (dfs(deep - 1, 1))
                return 1;
            if (fcake[i] < mouth[1])
                space -= fcake[i];
            fcake[i] += mouth[deep];
        }
    }
    return 0;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &cake[i]);
        tot += cake[i];
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &mouth[i]);
    }
    qsort(cake + 1, n, sizeof(int), cmp);
    qsort(mouth + 1, m, sizeof(int), cmp);
    sum[0] = 0;
    for (int i = 1; i <= m; ++i)
        sum[i] = sum[i - 1] + mouth[i];
    while (sum[m] > tot)
        --m;
    int l = 0, r = m;
    while (l <= r) {
        mid = l + r >> 1;
        for (int i = 1; i <= n; ++i)
            fcake[i] = cake[i];
        space = 0;
        if (dfs(mid, 1))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l - 1;
    puts("");
    return 0;
}
