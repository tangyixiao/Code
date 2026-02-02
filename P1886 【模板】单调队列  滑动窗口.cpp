#include <bits/stdc++.h>
using namespace std;
struct node {
    int id, v;
};
const int N = 1e6 + 5;
deque<node> que, pue;
int n, m, k, M = 1, x, ans[N][3];
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        while (!que.empty() && x >= que.back().v) {
            que.pop_back();
        }

        while (!pue.empty() && x <= pue.back().v) {
            pue.pop_back();
        }
        que.push_back(node{i, x});
        pue.push_back(node{i, x});
        while (i - k >= que.front().id) {
            que.pop_front();
        }
        while (i - k >= pue.front().id) {
            pue.pop_front();
        }

        if (i >= k) {
            ans[M][2] = que.front().v;
            ans[M][1] = pue.front().v;
            M++;
        }
    }
    for (int i = 1; i < M; i++) {
        printf("%d ", ans[i][1]);
    }
    printf("\n");
    for (int i = 1; i < M; i++) {
        printf("%d ", ans[i][2]);
    }
    return 0;
}
