#include<bits/stdc++.h>
using namespace std;
const int N=1e1;
string a[N]={"Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"},x[N],y[N],s,t;
int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)cin>>x[i]>>s>>s>>s>>s>>y[i];do{bool f=1;for(int i=0;i<n;i++){int p=find(a,a+8,x[i])-a,q=find(a,a+8,y[i])-a;if(abs(p-q)>1)f=0;}if(f){for(int i=0;i<8;i++)cout<<a[i]<<'\n';return 0;}}while(next_permutation(a,a+8));}
