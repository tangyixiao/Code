#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 10010;
int a[MAXN];
int n, k;

bool check(int x) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i] / x;
        if (sum >= k)
            return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    double t;
    int maxv = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &t);
        // 将长度乘以100并四舍五入转化为整数，避免浮点误差
        a[i] = (int)(t * 100 + 0.5);
        if (a[i] > maxv)
            maxv = a[i];
    }
    int l = 1, r = maxv, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%.2f\n", ans / 100.0);
    return 0;
}