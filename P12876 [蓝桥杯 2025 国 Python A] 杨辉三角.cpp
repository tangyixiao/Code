#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5;
int cnt[N];
main() {
	for (int n = 2,cur; n <= N; ++n) {
		cur = n;
		if (cur <= N) {
			if (2 == n) {
				cnt[cur] += 1;
			} else {
				cnt[cur] += 2;
			}
		}
		for (int k = 2; k <= n / 2; ++k) {
			cur = cur * (n - k + 1) / k;
			if (cur > N) {
				break;
			}
			if (2 * k == n) {
				cnt[cur] += 1;
			} else {
				cnt[cur] += 2;
			}
		}
	}

	int n;
	cin >> n;
	map<int,int> mp;
	for (int x = 2; x <= n; ++x) {
		int v = cnt[x];
		mp[v]++;
	}
	for(auto it:mp) {
		cout<<it.first<<" "<<it.second<<"\n";
	}

	return 0;
}
