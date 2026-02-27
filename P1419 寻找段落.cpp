#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const double EPS = 1e-5;

int n, S, T;
int a[MAXN];
double sum[MAXN];

bool check(double mid) {

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (a[i] - mid);
    }

    deque<int> q;

    for (int i = S; i <= n; i++) {

        int j = i - S;
        while (!q.empty() && sum[q.back()] > sum[j]) {
            q.pop_back();
        }
        q.push_back(j);

        while (!q.empty() && q.front() < i - T) {
            q.pop_front();
        }

        if (!q.empty() && sum[i] - sum[q.front()] >= 0) {
            return true;
        }
    }

    return false;
}

int main() {

    scanf("%d", &n);
    scanf("%d %d", &S, &T);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    double left = -10000, right = 10000;
    while (right - left > EPS) {
        double mid = (left + right) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    printf("%.3f\n", left);

    return 0;
}