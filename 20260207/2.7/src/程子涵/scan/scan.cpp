#include<bits/stdc++.h>
//#define int long long
using namespace std;
int a[55][55][55], vis[55][55][55];
int l, w, h, m, cnt;
bool check(int x, int y, int z) {
	if (x < 1 || x > l || y < 1|| y > w || z < 1 || z > h) return 0;
	return 1;
}
void dfs(int i, int j, int k) {
	if (check(i + 1, j, k) == 1 && (abs(a[i][j][k] - a[i + 1][j][k]) <= m) && vis[i + 1][j][k] == 0) {
		vis[i + 1][j][k] = 1;
		dfs(i + 1, j, k);
	}
	if (check(i, j + 1, k) == 1 && (abs(a[i][j][k] - a[i][j + 1][k]) <= m) && vis[i][j + 1][k] == 0) {
		vis[i][j + 1][k] = 1;
		dfs(i, j + 1, k);
	}
	if (check(i, j, k + 1) == 1 && (abs(a[i][j][k] - a[i][j][k + 1]) <= m) && vis[i][j][k + 1] == 0) {
		vis[i][j][k + 1] = 1;
		dfs(i, j, k + 1);
	}
	if (check(i - 1, j, k) == 1 && (abs(a[i][j][k] - a[i - 1][j][k]) <= m) && vis[i - 1][j][k] == 0) {
		vis[i - 1][j][k] = 1;
		dfs(i - 1, j, k);
	}
	if (check(i, j - 1, k) == 1 && (abs(a[i][j][k] - a[i][j - 1][k]) <= m) && vis[i][j - 1][k] == 0) {
		vis[i][j - 1][k] = 1;
		dfs(i, j - 1, k);
	}
	if (check(i, j, k - 1) == 1 && (abs(a[i][j][k] - a[i][j][k - 1]) <= m) && vis[i][j][k - 1] == 0) {
		vis[i][j - 1][k] = 1;
		dfs(i, j, k - 1);
	}
}
signed main() {
	freopen("scan.in", "r", stdin);
	freopen("scan.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> l >> w >> h;
	cin >> m;
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= w; j++) {
			for (int k = 1; k <= h; k++) {
				cin >> a[i][j][k];
			}
		}
	}
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= w; j++) {
			for (int k = 1; k <= h; k++) {
				if (vis[i][j][k] == 0) {
					cnt++;
					vis[i][j][k] = 1;
					dfs(i, j, k);
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
