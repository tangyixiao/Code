#include <bits/stdc++.h>
using namespace std;
struct node {
    int x, s;
};
int n;
bool pd(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}
queue<node> q;
void bfs() {
    q.push({2, 1});
    q.push({3, 1});
    q.push({5, 1});
    q.push({7, 1});
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        if (now.s == n) {
            printf("%d\n", now.x);
            continue;
        }
        for (int i = 1; i <= 9; i += 2) {
            if (pd(now.x * 10 + i)) {
                q.push({now.x * 10 + i, now.s + 1});
            }
        }
    }
}
int main() {
    cin >> n;
    bfs();
}