#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    int N = rand() % 10 + 2;
    int M = rand() % 10 + 1;
    printf("%d %d\n", N, M);
    for (int i = 1; i <= N; i++)
        printf("%d%c", rand() % 2000001 + 1, " \n"[i == N]);
    for (int i = 2; i <= N; i++) {
        int u = i, v = rand() % (i - 1) + 1;
        printf("%d %d\n", u, v);
    }
    while (M--) {
        int op = rand() % 3 + 1;
        int x = rand() % N + 1;
        if (op == 1) {
            int v = rand() % 2000001 + 1;
            printf("1 %d %d\n", x, v);
        } else if (op == 2) {
            int v = rand() % 2000001 + 1;
            printf("2 %d %d\n", x, v);
        } else {
            printf("3 %d\n", x);
        }
    }
    return 0;
}