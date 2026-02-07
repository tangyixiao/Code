#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,p;
int a[N];
int qpow(int base,int w){
	int ans=1,t=base;
	while(w!=0){
		if(w&1){
			ans=ans*t;
		}
		t=t*t;
		w=w>>1;
	}
	return ans;
}
signed main(){
	freopen("equation.in","r",stdin);
	freopen("equation.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int cnt=0;
		cin>>n>>p;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					int sum=0;
					int aj,ak;
					int s=1;
					while(1){
						int w=qpow(2,s);
					    if(a[j]/w>=1){
							aj=s;
							s++;
						} 
						else break;
					}
					s=1;
					while(1){
						int w=qpow(2,s);
						if(a[k]/w>=1){
							ak=s;
							s++;
						} 
						else break;
					}
					sum+=a[i]*qpow(2,aj+ak+2)+a[j]*qpow(2,ak+1)+a[k];
				    if(sum==p){
						cnt++;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
