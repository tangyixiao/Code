#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

struct G {
    int maps[10][10];
};

int n;

G now;

G last[10];

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct Info {
    int x, y;
    int flag;

    Info(int dx, int dy, int flag) {
        x = dx;
        y = dy;
        this->flag = flag;
    }
    Info() {}
};

Info steps[10];

int cnt = 0;

bool visited[10][10];

bool checkp(int x, int y) {
    if (x >= 0 && y >= 0 && x < 5 && y < 7 && !visited[x][y] && now.maps[x][y])
        return true;
    return false;
}

bool marks[10][10];

bool updates[10][10];

int maxx, maxy;

int minx, miny;

void dfsupdate(int x, int y, int dire, int d) {
    visited[x][y] = true;
    maxx = max(maxx, x);
    minx = min(minx, x);
    maxy = max(maxy, y);
    miny = min(miny, y);
    if (dire == -1) {
        for (int i = 0; i < 4; i++) {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if (checkp(dx, dy))
                if (now.maps[x][y] == now.maps[dx][dy])
                    dfsupdate(dx, dy, i, d + 1);
        }
    } else {
        int dx = x + dir[dire][0];
        int dy = y + dir[dire][1];
        if (checkp(dx, dy))
            if (now.maps[x][y] == now.maps[dx][dy])
                dfsupdate(dx, dy, dire, d + 1);
    }
    visited[x][y] = false;
}

bool update(int x, int y) {
    maxx = maxy = 0;
    minx = miny = 100;
    dfsupdate(x, y, -1, 1);
    bool flag = false;
    if (maxx - minx + 1 >= 3) {
        for (int i = minx; i <= maxx; i++) {
            marks[i][y] = true;
            updates[i][y] = true;
        }
        flag = true;
    }
    if (maxy - miny + 1 >= 3) {
        for (int i = miny; i <= maxy; i++) {
            marks[x][i] = true;
            updates[x][i] = true;
        }
        flag = true;
    }
    return flag;
}

void updateall() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++)
            if (marks[i][j])
                now.maps[i][j] = 0, marks[i][j] = false;
        for (int j = 0; j < 7; j++)
            if (!now.maps[i][j]) {
                int ind = 0;
                for (int k = j + 1; k < 7; k++)
                    if (now.maps[i][k])
                        now.maps[i][j + ind] = now.maps[i][k], ind++, now.maps[i][k] = 0;
                break;
            }
    }
}

bool check() {
    for (int i = 0; i < 5; i++)
        if (now.maps[i][0] != 0)
            return false;
    return true;
}

bool move(int x, int y, int k) {
    int targetx, targety;
    if (k) {
        if (x == 4)
            return false;
        else {
            int t = now.maps[x][y];
            now.maps[x][y] = now.maps[x + 1][y];
            now.maps[x + 1][y] = t;
            steps[cnt++] = Info(x, y, 1);
            targetx = x + 1;
            targety = y;
            if (!now.maps[x][y]) {
                for (int i = x; i <= x + 1; i++)
                    for (int j = 0; j < 7; j++)
                        if (!now.maps[i][j]) {
                            int ind = 0;
                            for (int k = j + 1; k < 7; k++)
                                if (now.maps[i][k]) {
                                    if (i == x + 1 && y == k)
                                        targety = j + ind;
                                    now.maps[i][j + ind] = now.maps[i][k], ind++,
                                                    now.maps[i][k] = 0;
                                }
                            break;
                        }
            }
        }
    } else {
        if (x == 0)
            return false;
        else {
            int t = now.maps[x][y];
            now.maps[x][y] = now.maps[x - 1][y];
            now.maps[x - 1][y] = t;
            steps[cnt++] = Info(x, y, -1);
            targetx = x - 1;
            targety = y;
            if (!now.maps[x][y]) {
                for (int i = x - 1; i <= x; i++)
                    for (int j = 0; j < 7; j++)
                        if (!now.maps[i][j]) {
                            int ind = 0;
                            for (int k = j + 1; k < 7; k++)
                                if (now.maps[i][k]) {
                                    if (i == x - 1 && y == k)
                                        targety = j + ind;
                                    now.maps[i][j + ind] = now.maps[i][k], ind++,
                                                    now.maps[i][k] = 0;
                                }
                            break;
                        }
            }
        }
    }
    bool flag = false;
    if (update(x, y) | update(targetx, targety))
        flag = true;
    while (flag) {
        updateall();
        flag = false;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 7 && now.maps[i][j] != 0; j++)
                if (updates[i][j]) {
                    updates[i][j] = false;
                    if (update(i, j))
                        flag = true;
                }
    }
    return true;
}

void dfs(int d, int x, int y, int k) {
    if (d > n)
        return;
    last[d] = now;
    if (move(x, y, k)) {
        if (check()) {
            if (d == n) {
                for (int i = 0; i < cnt; i++)
                    cout << steps[i].x << " " << steps[i].y << " " << steps[i].flag << endl;
                exit(0);
            } else {
                bool flag = false;
                if ((d - n) % 2 == 0) {
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 7; j++)
                            if (last[1].maps[i][j] && last[1].maps[i][j + 1]) {
                                for (int t = 0; t < (d - n); t++)
                                    cout << i << " " << j << " 1" << endl;
                                break;
                                flag = true;
                            }
                        if (flag)
                            break;
                    }
                    for (int i = 0; i < cnt; i++)
                        cout << steps[i].x << " " << steps[i].y << " " << steps[i].flag << endl;
                    exit(0);
                }
            }
        }
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 7 && now.maps[i][j] != 0; j++)
                if (i != 0 && !now.maps[i - 1][j])
                    for (int l = 1; l >= 0; l--)
                        dfs(d + 1, i, j, l);
                else
                    dfs(d + 1, i, j, 1);
        cnt--;
    }
    now = last[d];
}

int main() {
    cin >> n;
    for (int i = 0; i < 5; i++) {
        int x;
        int ind = 0;
        while (cin >> x) {
            if (x == 0)
                break;
            now.maps[i][ind] = x;
            ind++;
        }
    }
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 7 && now.maps[i][j] != 0; j++)
            if (i != 0 && !now.maps[i - 1][j])
                for (int k = 1; k >= 0; k--)
                    dfs(1, i, j, k);
            else
                dfs(1, i, j, 1);
    cout << -1 << endl;
}
