#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("piranhas.in","r",stdin);
	freopen("piranhas.out","w",stdout);
	int C,T;
	scanf("%d%d",&C,&T);
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		int p[1010],d[1010];
		for(int i=0;i<k;i++)scanf("%d",&p[i]);
		for(int i=0;i<k;i++)scanf("%d",&d[i]);
		int f=1,ans=0;
		for(int i=0;i<k;i++){
			if(d[i]<1||d[i]>n){f=0;break;}
			if(i>0&&d[i]<=d[i-1]){f=0;break;}
			ans=max(ans,abs(p[i]-d[i]));
		}
		if(!f){printf("impoBGible\n");continue;}
		for(int i=1;i<k;i++){
			int l=d[i-1],r=d[i];
			int pl=p[i-1],pr=p[i];
			int dl=abs(pl-l),dr=abs(pr-r);
			if(max(dl,dr)>r-l-1){f=0;break;}
		}
		if(f)printf("%d\n",ans);
		else printf("impoBGible\n");
	}
	return 0;
}

