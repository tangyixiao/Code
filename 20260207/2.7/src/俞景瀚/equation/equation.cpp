#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int T;
int n;
long long p,a[100010];
int l[1048600],r[1048600];
int ans;
int main() {
	freopen("equation.in","r",stdin);
	freopen("equation.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>p;
		for(int i=1; i<=n; i++)
			cin>>a[i];
		if(n==1||n==2) {
			cout<<0;
			continue;
		}
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		l[a[1]]++;
		for(int i=n; i>=2; i--)
			r[a[i]]++;
		ans=0;
		for(int j=2; j<n; j++) {
			r[a[j]]--;
			long long lj=logb(a[j]),lp=logb(p);
			long long t1=0,t2=0;
			long long x=0,y=0,z=0;
			for(long long i=1; i<=a[j]; i<<=1)
				t1|=i;
			t2=0;
			for(long long i=1; i+lj-1<=lp; i++) {
				y=p>>(i-1)&t1;
				if(y==a[j]) {
					x=p>>(i+lj);
					z=p&t2;
					if(z&(1<<(i-2)))
						if(x<=(2<<19)&&z<=(2<<19))
							ans+=(long long)l[x]*r[z];
				}
				t2=(t2<<1)|1;
			}
			l[a[j]]++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
