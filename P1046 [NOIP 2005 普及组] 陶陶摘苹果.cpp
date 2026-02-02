#include<bits/stdc++.h>
using namespace std;
const int n=10;
int a[14],h,ans;
int main(){
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	scanf("%d",&h);
	h+=30;
	for(int i=1;i<=n;i++){
		if(h>=a[i]){
			ans++;
		}
	}
	printf("%d",ans);
	return 0; 
}