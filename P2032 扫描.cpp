#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e6 + 10;
int a[N], q[N], head, tail;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    head = 0, tail = 0;

    for (int i = 1; i <= n; ++i) {
        while (head < tail && a[q[tail - 1]] <= a[i]) {
            tail--;
        }
        if (head < tail && q[head] < i - m + 1) {
            head++;
        }

        q[tail++] = i;
        if (i >= m) {
            printf("%d\n", a[q[head]]);
        }
    }

    return 0;
}