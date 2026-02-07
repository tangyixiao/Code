#include<bits/stdc++.h>
using namespace std;
int n,T,eqa;
long long cnt,P;
int a[100005],b[100005];
int v[1048576];
signed main(){
	freopen("equation.in","r",stdin);
	freopen("equation.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		cin>>P;
		cnt=0;eqa=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=a[1])eqa=0;
			b[i]=__lg(a[i]);
		}
		if(eqa){
			if(P==a[1]*((1<<(2*b[1]+2))+(1<<(b[1]+1))+1)){
				cout<<((n+2)*(n+1)*n/6)<<'\n';
			}
			else cout<<0<<'\n';
		}
		else if(n<=500){
			for(int i=1;i<n;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<=n;k++)
				if(a[i]*(1<<(b[j]+b[k]+2))+a[j]*(1ll<<(b[k]+1))+a[k]==P)cnt++;
			cout<<cnt<<'\n';
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
