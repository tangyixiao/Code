#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,p,ans=1,kln,klm;
signed main() {
	scanf("%lld%lld%lld",&n,&m,&p);
	kln=n,klm=m;
	while(m){
		if(m%2==1)ans=ans*n%p;
		n=n*n%p;
		m>>=1;
	}
	printf("%lld^%lld mod %lld=%lld\n",kln,klm,p,ans);
	return 0;
}