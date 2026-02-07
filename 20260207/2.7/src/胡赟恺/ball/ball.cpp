#include<bits/stdc++.h>
using namespace std;
#define breakaway L=-1;break
string a[100005],s;
int n;
signed main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	while(cin>>s)a[++n]=s;
	int w,l;
	w=l=0;
	for(int i=1;i<=n;i++){
		int L=a[i].size();
		for(int j=0;j<L;j++){
			if(a[i][j]=='E'){
				cout<<w<<' '<<l<<'\n';
				w=l=0;
				breakaway;
			}
			if(a[i][j]=='W'){
				w++;
				if(w>=11&&w-l>=2){
					cout<<w<<' '<<l<<'\n';
					w=l=0;
				}
			}
			if(a[i][j]=='L'){
				l++;
				if(l>=11&&l-w>=2){
					cout<<w<<' '<<l<<'\n';
					w=l=0;
				}
			}
		}
		if(L==-1)break;
	}
	cout<<'\n';
	for(int i=1;i<=n;i++){
		int L=a[i].size();
		for(int j=0;j<L;j++){
			if(a[i][j]=='E'){
				cout<<w<<' '<<l<<'\n';
				w=l=0;
				breakaway;
			}
			if(a[i][j]=='W'){
				w++;
				if(w>=21&&w-l>=2){
					cout<<w<<' '<<l<<'\n';
					w=l=0;
				}
			}
			if(a[i][j]=='L'){
				l++;
				if(l>=21&&l-w>=2){
					cout<<w<<' '<<l<<'\n';
					w=l=0;
				}
			}
		}
		if(L==-1)break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
