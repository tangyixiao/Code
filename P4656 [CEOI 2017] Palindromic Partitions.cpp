#include <cstdio>
#include <cstring>

typedef unsigned long long UL;
const int B = 79;

int T, N;
char str[1000005];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        N = strlen(str);
        UL s1 = 0, s2 = 0, b = 1;
        int ans = 0;
        for (int i = 0; i < N / 2; ++i) {
            s1 = s1 * B + str[i];
            s2 = s2 + str[N - i - 1] * b;
            b = b * B;
            if (s1 == s2) {
                ans += 2;
                s1 = s2 = 0, b = 1;
            }
        }
        if (N % 2 || s1)
            ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
