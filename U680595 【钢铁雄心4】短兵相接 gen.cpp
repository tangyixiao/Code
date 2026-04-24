#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    // 参数：N最大值 M最大值 hp最大值 atk最大值 随机种子

    int maxN = 200000, maxM = 200000;
    int maxHp = 1000000000, maxAtk = 1000000000;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    if (argc > 1)
        maxN = atoi(argv[1]);
    if (argc > 2)
        maxM = atoi(argv[2]);
    if (argc > 3)
        maxHp = atoi(argv[3]);
    if (argc > 4)
        maxAtk = atoi(argv[4]);
    if (argc > 5)
        seed = atoi(argv[5]);

    mt19937 rng(seed);
    uniform_int_distribution<int> distN(1, maxN), distM(1, maxM);
    uniform_int_distribution<int> distHp(1, maxHp), distAtk(1, maxAtk);

    int n = distN(rng), m = distM(rng);
    cout << n << " " << m << "\n";
    for (int i = 0; i < n; ++i)
        cout << distHp(rng) << " " << distAtk(rng) << "\n";
    for (int i = 0; i < m; ++i)
        cout << distHp(rng) << " " << distAtk(rng) << "\n";
    return 0;
}