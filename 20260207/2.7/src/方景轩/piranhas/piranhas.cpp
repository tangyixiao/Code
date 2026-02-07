#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e3+1;
int n,k;
int p[N],d[N];
struct node{
	int id,cha;
}a[N];
signed main(){
	freopen("piranhas.in","r",stdin);
	freopen("piranhas.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int sum=0;
		cin>>n>>k;
		for(int i=1;i<=k;i++){
			cin>>p[i];
		}
		for(int i=1;i<=k;i++){
			cin>>d[i];
		}
		for(int i=1;i<=k;i++){
			a[i].id=i;
			a[i].cha=abs(p[i]-d[i]);
			sum+=a[i].cha;
		}
		if(sum%2==1){
			cout<<"impoBGible"<<endl;
		}
		else{
			cout<<sum*2<<endl;
		}
	}
	return 0;
}
