#include <bits/stdc++.h>
using namespace std;
//#define Local

inline long long qpow(long long a,long long x,long long p){
	long long res = 1;
	for (long long t = x; t != 0; t >>= 1) {
		if (t & 1) res = res * a % p;
		a = a * a % p;
	}
	return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef Local
    freopen("pow.in", "r", stdin);
    freopen("pow.out", "w", stdout);
#endif 
	string a;
	string b;
    cin >> a >> b;
	long long mod=1e9+7,res=0;
	
	for(int i=0;i<a.size();i++){
		res=(res*10+a[i]-'0')%mod;

	}
	long long mul = res,ans=1;
for(int i=0;i<b.size();i++){
	ans=(qpow(ans,10,mod)*qpow(mul,b[i]-'0',mod))%mod;

}
	
	cout<<ans;
    return 0;
}
