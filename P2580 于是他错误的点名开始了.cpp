#include <cstdio>

const int N = 500010;

char s[60];
int n, m, ch[N][26], tag[N], tot = 1;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%s", s + 1);
        int u = 1;
        for (int j = 1; s[j]; ++j) {
            int c = s[j] - 'a';
            if (!ch[u][c])
                ch[u][c] =
                    ++tot;
            u = ch[u][c];
        }
        tag[u] = 1;
    }

    scanf("%d", &m);

    while (m--) {
        scanf("%s", s + 1);
        int u = 1;
        for (int j = 1; s[j]; ++j) {
            int c = s[j] - 'a';
            u = ch[u][c];
            if (!u)
                break;
        }
        if (tag[u] == 1) {
            tag[u] = 2;
            puts("OK");
        } else if (tag[u] == 2)
            puts("REPEAT");
        else
            puts("WRONG");
    }

    return 0;
}