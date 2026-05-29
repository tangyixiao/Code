#include <cstdio>
#include <cstring>
using namespace std;

const int MAXH = 2500;
const int MINH = 1;

int c[MAXH + 1];

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        int N;
        scanf("%d", &N);
        memset(c, 0, sizeof(c));
        int L = 2 * N - 1;
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < N; ++j) {
                int x;
                scanf("%d", &x);
                ++c[x];
            }
        }
        printf("Case #%d:", tc);
        for (int v = MINH; v <= MAXH; ++v) {
            if (c[v] & 1) {
                printf(" %d", v);
            }
        }
        printf("\n");
    }
    return 0;
}