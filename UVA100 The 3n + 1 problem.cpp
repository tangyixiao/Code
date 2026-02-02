#include<bits/stdc++.h>
using namespace std;
long long calculate(long long num) {
	if (num == 1)return 1;
	if (num % 2 == 1)return calculate(3 * num + 1) + 1;
	else return calculate(num / 2) + 1;
}
long long process(long long i,long long j) {
	if (i > j)swap(i, j);
	long long n = 0;
	for (long long k = i; k <= j; k++) {
		n = max(n, calculate(k));
	}
	return n;
}
int main() {
	long long i, j;
	while (cin >> i >> j) {
		cout << i << " " << j << " " << process(i, j) << endl;
	}
    return 0;
}
