#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N],e[100],vis[N],tp,mx,sum;
long long p,ans,tmp;
int lg(int x){
    int res=0;
    while(x)x/=2,res++;
    return res;
}
int calc(int x,int y,int z){
    long long pre=0,res=0;
    memset(vis,0,sizeof vis);
    for(int i=n;i>=2;i--)
        vis[i]=vis[i+1]+(a[i]==z?1:0);
    for(int i=2;i<n;i++){
        if(a[i-1]==x)pre++;
        if(a[i]==y)res+=pre*vis[i+1];
    }
    return res;
}
signed main(){
    freopen("equation.in","r",stdin); 
    freopen("equation.out","w",stdout);
    ios::sync_with_stdio(false);    
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>p,mx=tp=sum=0,tmp=p;
        while(tmp)
            e[++tp]=tmp%2,tmp/=2;
        for(int i=1;i<=n;i++)
            cin>>a[i],mx=max(mx,lg(a[i])),sum=max(sum,a[i]);
        if(n<3){
            cout<<0<<'\n';
            continue;
        }
        for(int i=1,fli=0;i<=mx;i++){
            fli+=(1<<(i-1))*e[i];
            if(fli>sum)break;
            for(int j=i+1,flj=0;j<=min(tp-1,i+mx+1);j++){
                flj+=(1<<(j-i-1))*e[j];
                if(fli>sum)break;
                if(tp-j>mx)continue;
                int flk=p>>j;
                if(flk>sum)break;
                ans+=calc(flk,flj,fli);
                if(calc(flk,flj,fli));
            }
        }
        cout<<ans<<'\n',ans=0;
    }   
    return 0;
}
/*
1
3 94
5 3 2  
*/