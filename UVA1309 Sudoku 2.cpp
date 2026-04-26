#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define lowbit(x) ((x) & (-(x)))

int num[1 << 17], mk[1 << 17];
int s[20][20];
char tt[20][20];
int mp[20 * 20][20][20], mps[20 * 20][20][20], mp2[20 * 20][20][20];

void init() {
    for (int i = 0; i < (1 << 16); i++)
        for (int j = i; j; j -= lowbit(j))
            num[i]++;
    for (int i = 0; i < 16; i++)
        mk[1 << i] = i;
}

void rel(int x, int y, int z) {
    tt[x][y] = z + 'A';
    for (int i = 0; i < 16; i++) {
        s[x][i] &= ~(1 << z);
        s[i][y] &= ~(1 << z);
    }
    int bx = x - x % 4, by = y - y % 4;
    for (int i = bx; i < bx + 4; i++)
        for (int j = by; j < by + 4; j++)
            s[i][j] &= ~(1 << z);
    s[x][y] = 1 << z;
}

bool dfs(int cnt) {
    if (!cnt)
        return true;
    int cntt = cnt;
    memcpy(mp[cntt], s, sizeof(s));
    memcpy(mps[cntt], tt, sizeof(tt));

    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++)
            if (tt[i][j] == '-') {
                if (!s[i][j]) {
                    memcpy(s, mp[cntt], sizeof(mp[cntt]));
                    memcpy(tt, mps[cntt], sizeof(mps[cntt]));
                    return false;
                }
                if (num[s[i][j]] == 1) {
                    cnt--;
                    rel(i, j, mk[s[i][j]]);
                }
            }

    for (int i = 0; i < 16; i++) {
        int all = 0, only = (1 << 16) - 1, drawn = 0;
        for (int j = 0; j < 16; j++) {
            only &= ~(all & s[i][j]);
            all |= s[i][j];
            if (tt[i][j] != '-')
                drawn |= s[i][j];
        }
        if (all != (1 << 16) - 1) {
            memcpy(s, mp[cntt], sizeof(mp[cntt]));
            memcpy(tt, mps[cntt], sizeof(mps[cntt]));
            return false;
        }
        while (only) {
            int k = lowbit(only);
            if (!(drawn & k)) {
                cnt--;
                for (int p = 0; p < 16; p++)
                    if (s[i][p] & k) {
                        rel(i, p, mk[k]);
                        break;
                    }
            }
            only -= k;
        }
    }

    for (int j = 0; j < 16; j++) {
        int all = 0, only = (1 << 16) - 1, drawn = 0;
        for (int i = 0; i < 16; i++) {
            only &= ~(all & s[i][j]);
            all |= s[i][j];
            if (tt[i][j] != '-')
                drawn |= s[i][j];
        }
        if (all != (1 << 16) - 1) {
            memcpy(s, mp[cntt], sizeof(mp[cntt]));
            memcpy(tt, mps[cntt], sizeof(mps[cntt]));
            return false;
        }
        while (only) {
            int k = lowbit(only);
            if (!(drawn & k)) {
                cnt--;
                for (int p = 0; p < 16; p++)
                    if (s[p][j] & k) {
                        rel(p, j, mk[k]);
                        break;
                    }
            }
            only -= k;
        }
    }

    for (int bi = 0; bi < 4; bi++)
        for (int bj = 0; bj < 4; bj++) {
            int bx = bi * 4, by = bj * 4;
            int all = 0, only = (1 << 16) - 1, drawn = 0;
            for (int i = bx; i < bx + 4; i++)
                for (int j = by; j < by + 4; j++) {
                    only &= ~(all & s[i][j]);
                    all |= s[i][j];
                    if (tt[i][j] != '-')
                        drawn |= s[i][j];
                }
            if (all != (1 << 16) - 1) {
                memcpy(s, mp[cntt], sizeof(mp[cntt]));
                memcpy(tt, mps[cntt], sizeof(mps[cntt]));
                return false;
            }
            while (only) {
                int k = lowbit(only);
                if (!(drawn & k)) {
                    cnt--;
                    for (int i = bx; i < bx + 4; i++)
                        for (int j = by; j < by + 4; j++)
                            if (s[i][j] & k) {
                                rel(i, j, mk[k]);
                                goto next_in_block;
                            }
                next_in_block:;
                }
                only -= k;
            }
        }

    if (!cnt)
        return true;

    int minc = 16, x = -1, y = -1, S = 0;
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++)
            if (tt[i][j] == '-' && num[s[i][j]] < minc) {
                minc = num[s[i][j]];
                x = i, y = j;
                S = s[i][j];
            }
    memcpy(mp2[cntt], s, sizeof(s));
    while (S) {
        int k = mk[lowbit(S)];
        memcpy(s, mp2[cntt], sizeof(mp2[cntt]));
        rel(x, y, k);
        if (dfs(cnt - 1))
            return true;
        S -= lowbit(S);
    }
    memcpy(s, mp[cntt], sizeof(mp[cntt]));
    memcpy(tt, mps[cntt], sizeof(mps[cntt]));
    return false;
}

int main() {
    init();
    char line[20];
    int first = 1;
    while (true) {

        if (fgets(line, sizeof(line), stdin) == NULL)
            break;
        while (line[0] == '\n') {
            if (fgets(line, sizeof(line), stdin) == NULL)
                break;
        }
        if (feof(stdin))
            break;

        line[strcspn(line, "\n")] = '\0';
        strcpy(tt[0], line);

        for (int i = 1; i < 16; i++) {
            fgets(line, sizeof(line), stdin);
            line[strcspn(line, "\n")] = '\0';
            strcpy(tt[i], line);
        }

        for (int i = 0; i < 16; i++)
            for (int j = 0; j < 16; j++)
                s[i][j] = (1 << 16) - 1;

        int cnt = 0;
        for (int i = 0; i < 16; i++)
            for (int j = 0; j < 16; j++)
                if (tt[i][j] != '-')
                    rel(i, j, tt[i][j] - 'A');
                else
                    cnt++;

        dfs(cnt);

        if (!first)
            putchar('\n');
        first = 0;

        for (int i = 0; i < 16; i++)
            printf("%s\n", tt[i]);
    }
    return 0;
}