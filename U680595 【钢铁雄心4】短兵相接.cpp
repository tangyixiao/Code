#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<pll> A(N), B(M);
    ll sumA_hp = 0, sumA_atk = 0;
    for (auto &[hp, atk] : A) {
        cin >> hp >> atk;
        sumA_hp += hp;
        sumA_atk += atk;
    }
    ll sumB_hp = 0, sumB_atk = 0;
    for (auto &[hp, atk] : B) {
        cin >> hp >> atk;
        sumB_hp += hp;
        sumB_atk += atk;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ia = 0, ib = 0, na = N, nb = M;
    double DA = 0.0, DB = 0.0;
    const double eps = 1e-12;

    while (na > 0 && nb > 0) {
        double vA = (double)sumB_atk / na;
        double vB = (double)sumA_atk / nb;

        double curA = A[ia].first - DA;
        double curB = B[ib].first - DB;
        double dtA = curA / vA;
        double dtB = curB / vB;

        if (dtA <= dtB + eps) {
            double dt = dtA;
            DA += vA * dt;
            DB += vB * dt;
            while (ia < N && A[ia].first <= DA + eps) {
                sumA_atk -= A[ia].second;
                sumA_hp -= A[ia].first; // 可选，用于最后计算剩余
                --na;
                ++ia;
            }
        } else {
            double dt = dtB;
            DB += vB * dt;
            DA += vA * dt;
            while (ib < M && B[ib].first <= DB + eps) {
                sumB_atk -= B[ib].second;
                sumB_hp -= B[ib].first;
                --nb;
                ++ib;
            }
        }
    }

    // 清理胜方可能同时死亡的师
    if (na > 0) {
        while (ia < N && A[ia].first <= DA + eps) {
            sumA_hp -= A[ia].first;
            --na;
            ++ia;
        }
        double ans = sumA_hp - na * DA;
        if (ans < 0)
            ans = 0.0;
        cout << "A " << fixed << setprecision(6) << ans << '\n';
    } else {
        while (ib < M && B[ib].first <= DB + eps) {
            sumB_hp -= B[ib].first;
            --nb;
            ++ib;
        }
        double ans = sumB_hp - nb * DB;
        if (ans < 0)
            ans = 0.0;
        cout << "B " << fixed << setprecision(6) << ans << '\n';
    }

    return 0;
}