#include<bits/stdc++.h>
#define int long long
using namespace std;
int tw,tl;
string s="";
signed main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	char ch;
	while(cin>>ch){
		if(ch=='E') break;
		s=s+ch;
	}
	int l=s.size();
	for(int i=0;i<l;i++){//11
		if(s[i]=='W') tw++;
		if(s[i]=='L') tl++;
		if(tw==11||tl==11){
			printf("%lld:%lld\n",tw,tl);
			tw=0,tl=0;
		}
	}
	printf("%lld:%lld\n",tw,tl);
	cout<<"\n";
	tw=0,tl=0;
	for(int i=0;i<l;i++){
		if(s[i]=='W') tw++;
		if(s[i]=='L') tl++;
		if(tw==21||tl==21){
			printf("%lld:%lld\n",tw,tl);
			tw=0,tl=0;
		}
	}
	printf("%lld:%lld\n",tw,tl);
	return 0;
}