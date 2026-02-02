#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main() {
    int ok = 0;
    int n = 50;
    freopen("duipai.log", "w", stdout);
    for (int i = 1; i <= n; ++i) {
        system("data.exe");
        system("std.exe");
        double begin = clock();
        system("baoli.exe");
        double end = clock();

        double t = (end - begin);
        if (system("fc std.out baoli.out")) {
            printf("测试点#%d Wrong Answer\n", i);
        } else if (t > 1000) // 1秒
        {
            printf("测试点#%d Time Limited Exceeded 用时 %.0lfms\n", i, t);
        } else {
            printf("测试点#%d Accepted 用时%.0lfms\n", i, t);
            ok++; // AC数量+1
        }
    }
    printf("\n");
    double res = 100.0 * ok / n;
    printf("共 %d 组测试数据，AC数据 %d 组。 得分%.1lf。", n, ok, res);
}