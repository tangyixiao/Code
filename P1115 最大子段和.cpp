#include<bits/stdc++.h>
using namespace std;
int n,a[2114514],dp[2114514],ans=-114514191;
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    for(int i=1;i<=n;i++){
    	dp[i]=max(dp[i-1]+a[i],a[i]);
    	ans=max(ans,dp[i]);
	}
	printf("%d",ans);
    return 0;
}