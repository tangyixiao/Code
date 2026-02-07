#include<bits/stdc++.h>
using namespace std;
string s;
char c;
struct node{
	int w,l,id;
}a[100001];
int l;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>c){
		s+=c;
		if(c=='E')break;
	}
	l=s.size();
	l--;
	for(int i=0;i<l;i++){
		a[i].id=i;
		a[i].l=a[i-1].l;
		a[i].w=a[i-1].w;
		if(s[i]=='W')a[i].w=a[i-1].w+1;
		if(s[i]=='L')a[i].l=a[i-1].l+1;
	}
	
	
	//11分
	int ww=0,ll=0;
	for(int i=0;i<l;i++){
		if(a[i].w-ww>=11||a[i].l-ll>=11){
			printf("%d:%d\n",a[i].w-ww,a[i].l-ll);
			ww=a[i].w;
			ll=a[i].l;
		}
	}
	//cout<<a[l-1].l-ll<<" "<<a[l-1].w-ww<<endl;
	if(a[l-1].w!=0||a[l-1].l!=0)printf("%d:%d\n\n",a[l-1].w-ww,a[l-1].l-ll);
	
	
	//21分
	ww=0;
	ll=0;
	for(int i=0;i<l;i++){
		if(a[i].w-ww>=21||a[i].l-ll>=21){
			printf("%d:%d\n",a[i].w-ww,a[i].l-ll);
			ww=a[i].w;
			ll=a[i].l;
		}
	}
	//cout<<a[l-1].l-ll<<" "<<a[l-1].w-ww<<endl;
	if(a[l-1].w!=0||a[l-1].l!=0)printf("%d:%d\n\n",a[l-1].w-ww,a[l-1].l-ll);
	return 0;
}
