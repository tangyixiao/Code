#include<bits/stdc++.h>
using namespace std;
int c,k,g,m,a[52][52][52],s;
void f(int x,int y,int z){
	int a2=a[x][y][z];
	a[x][y][z]=1000;
	if(x>1)
		if(abs(a2-a[x-1][y][z])<=m)
			f(x-1,y,z);
	if(x<c)
		if(abs(a2-a[x+1][y][z])<=m)
			f(x+1,y,z);
	if(y>1)
		if(abs(a2-a[x][y-1][z])<=m)
			f(x,y-1,z);
	if(y<k)
		if(abs(a2-a[x][y+1][z])<=m)
			f(x,y+1,z);
	if(z>1)
		if(abs(a2-a[x][y][z-1])<=m)
			f(x,y,z-1);
	if(z<g)
		if(abs(a2-a[x][y][z+1])<=m)
			f(x,y,z+1);
	return;
}
int main(){
	freopen("scan.in","r",stdin);
	freopen("scan.out","w",stdout);
	cin>>c>>k>>g>>m;
	for(int i=1;i<=c;i++)
		for(int i2=1;i2<=k;i2++)
			for(int i3=1;i3<=g;i3++)
				cin>>a[i][i2][i3];
	for(int i=1;i<=c;i++)
		for(int i2=1;i2<=k;i2++)
			for(int i3=1;i3<=g;i3++)
				if(a[i][i2][i3]!=1000){
					f(i,i2,i3);
					s++;
				}
	cout<<s;
	return 0;
}