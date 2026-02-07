#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
char c[N];
int cnt=0;
void check(int n){
	int w=0,l=0;
	for(int i=1;i<=cnt;i++){
		if(c[i]=='W') w++;
		else l++;
		if((w>=n||l>=n)&&(abs(w-l))>=2){
			cout<<w<<":"<<l<<endl;
			w=l=0;
		}
	}
	cout<<w<<":"<<l<<endl;
}
signed main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	while(cin>>c[++cnt]){
		if(c[cnt]=='E'){
			cnt--;
			break;
		}
	}
	check(11);
	cout<<endl;
	check(21);
	return 0;
}
