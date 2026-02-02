#include <bits/stdc++.h>
using namespace std;
int fh[514], vis[514], n, sa, eb;
struct node {
    int h, d;
};
void bfs() {
    queue<node> q;
    q.push(node{sa, 0});
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        if (now.h == eb) {
            cout << now.d << endl;
            return;
        }
        int nh = now.h + fh[now.h];
        if (nh >= 1 && nh <= n && vis[nh] == 0) {
            vis[nh] = 1;
            q.push(node{nh, now.d + 1});
        }
        nh = now.h - fh[now.h];
        if (nh >= 1 && nh <= n && vis[nh] == 0) {
            vis[nh] = 1;
            q.push(node{nh, now.d + 1});
        }
    }
    cout << -1;
}
int main() {
    scanf("%d%d%d", &n, &sa, &eb);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &fh[i]);
    }
    bfs();
    return 0;
}