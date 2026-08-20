#include<bits/stdc++.h>
using namespace std;
const int N=1e1;
string a[N]={"Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"},x[N],y[N],s;
int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)cin>>x[i]>>s>>s>>s>>s>>y[i];do{int z=0;for(int i=0;i<n;i++)z+=abs(find(a,a+8,x[i])-find(a,a+8,y[i]))!=1;if(!z){for(int i=0;i<8;i++)cout<<a[i]<<'\n';return 0;}}while(next_permutation(a,a+8));}
