#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const double eps = 1e-6, goal = 24.0;
namespace _24game {
    enum Op { ADD,
              SUB,
              MUL,
              DIV };
    char opChar(Op op) {
        switch (op) {
        case ADD:
            return '+';
        case SUB:
            return '-';
        case MUL:
            return '*';
        case DIV:
            return '/';
        }
        return '+';
    }

    double calc(double a, double b, Op op) {
        switch (op) {
        case ADD:
            return a + b;
        case SUB:
            return a - b;
        case MUL:
            return a * b;
        case DIV:
            return (fabs(b) < eps) ? 1e18 : a / b;
        }
        return 0;
    }
} // namespace _24game
using namespace _24game;
int a, b, c, d;
set<string> expres;
inline void dfs(int dep, double nums[4], string expr[4]);
inline void init();
signed main() {
    init();
    int nums[4] = {a, b, c, d};
    sort(nums, nums + 4);
    do {
        double dnum[4];
        string strexpr[4];
        for (int i = 0; i < 4; i++) {
            dnum[i] = nums[i];
            strexpr[i] = to_string(nums[i]);
        }
        dfs(4, dnum, strexpr);
    } while (next_permutation(nums, nums + 4));
    cout << expres.size();
    return 0;
}
inline void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> c >> d;
    return;
}
inline void dfs(int dep, double nums[4], string expr[4]) {
    if (dep == 1) {
        if (fabs(nums[0] - goal) < eps) {
            expres.insert(expr[0]);
        }
        return;
    }
    for (int i = 0; i < dep; i++) {
        for (int j = 0; j < dep; j++) {
            if (i != j) {
                double nnum[3];
                string nexprs[3];
                int now = 0;
                for (int k = 0; k < dep; k++) {
                    if (k != i && k != j) {
                        nnum[now] = nums[k];
                        nexprs[now] = expr[k];
                        now++;
                    }
                }
                for (int op = 0; op < 4; op++) {
                    double res = calc(nums[i], nums[j], (Op)op);
                    if (op != DIV || fabs(nums[j]) < eps) {
                        string nexprs1 = "(" + expr[i] + opChar((Op)op) + expr[j] + ")";
                        nnum[now] = res;
                        nexprs[now] = nexprs1;

                        dfs(dep - 1, nnum, nexprs);

                        if (op == SUB || op == DIV) {
                            double res2 = calc(nums[j], nums[i], (Op)op);
                            if (op != DIV || fabs(nums[i]) < eps) {
                                string nexprs2;
                                nexprs2 = "(" + expr[j] + opChar((Op)op) + expr[i] + ")";
                                nnum[now] = res2;
                                nexprs[now] = nexprs2;
                                dfs(dep - 1, nnum, nexprs);
                            }
                        }
                    }
                }
            }
        }
    }
    return;
}