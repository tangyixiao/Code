#include<bits/stdc++.h>
using namespace std;
string s;
int cnta,cntb;
int w,l,ww,ll,aw[10005],al[10005],bw[10005],bl[10005];
void print(){
	for(int i=1;i<=cnta;i++) cout<<aw[i]<<':'<<al[i]<<endl;
	cout<<endl;
	for(int i=1;i<=cntb;i++) cout<<bw[i]<<':'<<bl[i]<<endl;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	while(cin>>s){
		int len=s.size();
		for(int i=0;i<len;i++){
			if(s[i]=='E'){
				aw[++cnta]=w;
				al[cnta]=l;
				bw[++cntb]=ww;bl[cntb]=ll;
				print();
				return 0;
			}
			if(s[i]=='L'){l++;ll++;}
			else {w++;ww++;}
			if(l+w==11){
				aw[++cnta]=w;
				al[cnta]=l;
				l=0;w=0; 
			}
			if(ll+ww==21){
				bw[++cntb]=ww;bl[cntb]=ll;
				ll=0;ww=0;
			}
		}
	}
	return 0;
}