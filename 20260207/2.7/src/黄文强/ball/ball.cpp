#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][2],b[N][2],n0=1,n1=1;
inline void merge(int x,int y){
	int w0=a[n0][0],w1=b[n1][0];
	int l0=a[n0][1],l1=b[n1][1];
	if(x>=2&&(w0>=11||l0>=11)) ++n0;
	if(y>=2&&(w1>=21||l1>=21)) ++n1;
	return ;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	char ch;
	while(cin>>ch){
		if(ch=='E') break;
		if(ch=='W') ++a[n0][0],++b[n1][0];
		else ++a[n0][1],++b[n1][1];
		int x=abs(a[n0][0]-a[n0][1]);
		int y=abs(b[n1][0]-b[n1][1]);
		merge(x,y);
	}
	for(int i=1;i<=n0;++i)
		cout<<a[i][0]<<':'<<a[i][1]<<'\n';
	cout<<'\n';
	for(int i=1;i<=n1;++i)
		cout<<b[i][0]<<':'<<b[i][1]<<'\n';
	return 0;
}
