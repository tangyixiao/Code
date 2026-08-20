#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int a[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);int n,z=1;cin>>n;for(int i=0;i<n;i++)cin>>a[i];sort(a,a+n);for(int i=0;i<n;i++)for(int j=i;j<n&&a[j]-a[i]<n;j++)z=max(z,j-i+1);int x=n-z;if(a[n-2]-a[0]==n-2&&a[n-1]-a[n-2]>2||a[n-1]-a[1]==n-2&&a[1]-a[0]>2)x=2;cout<<x<<'\n'<<max(a[n-2]-a[0],a[n-1]-a[1])-n+2<<'\n';}
