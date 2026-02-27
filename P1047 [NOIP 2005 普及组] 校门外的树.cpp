#include <bits/stdc++.h>
using namespace std;
int L, M, cnt = 0, vis[10010];
int main() {
    memset(vis, 0, sizeof(vis));
    cin >> L >> M;
    for (int i = 0; i <= L; i++)
        vis[i] = 0;
    for (int i = 1; i <= M; i++) {
        int head, tail;
        cin >> head >> tail;
        for (int j = head; j <= tail; j++)
            if (vis[j] == 0)
                vis[j] = 1;
    }
    for (int i = 0; i <= L; i++) {
        if (vis[i] == 0)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}