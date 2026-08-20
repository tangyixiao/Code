from build_lib import add

A=r'''#include <bits/stdc++.h>
using namespace std;const int N=1005;int w[255],t[255],f[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,W;cin>>n>>W;for(int i=0;i<n;i++)cin>>w[i]>>t[i];int l=0,r=1000001;while(l+1<r){int m=(l+r)/2;memset(f,0xc0,sizeof f);f[0]=0;for(int i=0;i<n;i++)for(int j=W;j>=0;j--)if(f[j]>-1e9)f[min(W,j+w[i])]=max(f[min(W,j+w[i])],f[j]+t[i]*1000-m*w[i]);if(f[W]>=0)l=m;else r=m;}cout<<l<<'\n';}
'''
AB=r'''#include <bits/stdc++.h>
using namespace std;const int N=25;int w[N],t[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,W,r=0;cin>>n>>W;for(int i=0;i<n;i++)cin>>w[i]>>t[i];for(int s=1;s<(1<<n);s++){long long a=0,b=0;for(int i=0;i<n;i++)if(s>>i&1)a+=w[i],b+=t[i];if(a>=W)r=max(r,(int)(b*1000/a));}cout<<r<<'\n';}
'''
AG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int n=g()%min(250ULL,max(1ULL,z))+1,W=g()%1000+1;cout<<n<<' '<<W<<'\n';for(int i=0;i<n;i++){int x=g()%1000000+1;if(!i)x=max(x,W);cout<<x<<' '<<g()%1000+1<<'\n';}}
'''
AS=r'''#include <bits/stdc++.h>
using namespace std;const int N=20;int w[N],t[N],f[100];int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%14+1,W=g()%50+1,S=0;for(int i=0;i<n;i++)w[i]=g()%20+1,t[i]=g()%30+1,S+=w[i];W=min(W,S);int l=0,r=30001;while(l+1<r){int m=(l+r)/2;memset(f,0xc0,sizeof f);f[0]=0;for(int i=0;i<n;i++)for(int j=W;j>=0;j--)if(f[j]>-1e9)f[min(W,j+w[i])]=max(f[min(W,j+w[i])],f[j]+t[i]*1000-m*w[i]);if(f[W]>=0)l=m;else r=m;}int q=0;for(int z=1;z<(1<<n);z++){long long a=0,b=0;for(int i=0;i<n;i++)if(z>>i&1)a+=w[i],b+=t[i];if(a>=W)q=max(q,(int)(b*1000/a));}if(l!=q)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P4377','P4377 [USACO18OPEN] Talent Show G',r'二分整数答案 $x=\lfloor1000T/W\rfloor$。把每头牛的贡献改成 $1000t_i-xw_i$，用背包判断能否选出总重量至少为 $W$ 且新贡献和非负的集合；重量超过 $W$ 后统一压到 $W$。时间复杂度 $O(NW\log 10^6)$。',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},extra=[('1 1\n1 1\n','1000\n'),('3 5\n2 10\n3 3\n5 20\n','4285\n'),('2 10\n4 100\n6 1\n','10100\n')])

B=r'''#include <bits/stdc++.h>
using namespace std;const int N=105;double a[N][N],b[N][N],u[N],v[N],d[N];int p[N],q[N];bool z[N];int n;bool C(double x){memset(u,0,sizeof u);memset(v,0,sizeof v);memset(p,0,sizeof p);for(int i=1;i<=n;i++){p[0]=i;fill(d+1,d+n+1,1e100);memset(z,0,sizeof z);int j=0;do{z[j]=1;int k=p[j],y=0;double e=1e100;for(int l=1;l<=n;l++)if(!z[l]){double c=x*b[k][l]-a[k][l]-u[k]-v[l];if(c<d[l])d[l]=c,q[l]=j;if(d[l]<e)e=d[l],y=l;}for(int l=0;l<=n;l++)if(z[l])u[p[l]]+=e,v[l]-=e;else d[l]-=e;j=y;}while(p[j]);do{int y=q[j];p[j]=p[y];j=y;}while(j);}double s=0;for(int j=1;j<=n;j++)s+=a[p[j]][j]-x*b[p[j]][j];return s>=0;}int main(){ios::sync_with_stdio(0);cin.tie(0);cin>>n;for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>b[i][j];double l=0,r=10000;for(int k=0;k<60;k++){double m=(l+r)/2;if(C(m))l=m;else r=m;}cout<<fixed<<setprecision(6)<<l<<'\n';}
'''
BB=r'''#include <bits/stdc++.h>
using namespace std;const int N=11;long long a[N][N],b[N][N];int p[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>b[i][j];iota(p,p+n,0);long long A=0,B=1;do{long long x=0,y=0;for(int i=0;i<n;i++)x+=a[i][p[i]],y+=b[i][p[i]];if(x*B>A*y)A=x,B=y;}while(next_permutation(p,p+n));cout<<fixed<<setprecision(6)<<(double)A/B<<'\n';}
'''
BP=r'''#include <bits/stdc++.h>
using namespace std;const int N=19,M=1<<18;double a[N][N],b[N][N],f[M];int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>b[i][j];double l=0,r=10000;for(int z=0;z<55;z++){double x=(l+r)/2;fill(f,f+(1<<n),-1e100);f[0]=0;for(int s=0;s<(1<<n);s++){int i=__builtin_popcount((unsigned)s);for(int j=0;j<n;j++)if(!(s>>j&1))f[s|1<<j]=max(f[s|1<<j],f[s]+a[i][j]-x*b[i][j]);}if(f[(1<<n)-1]>=0)l=x;else r=x;}cout<<fixed<<setprecision(6)<<l<<'\n';}
'''
BG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):8;mt19937_64 g(s);int n=g()%min(100ULL,max(1ULL,z))+1;cout<<n<<'\n';for(int k=0;k<2;k++)for(int i=0;i<n;i++){for(int j=0;j<n;j++)cout<<g()%10000+1<<' ';cout<<'\n';}}
'''
BS=r'''#include <bits/stdc++.h>
using namespace std;const int N=9;double a[N][N],b[N][N],u[N],v[N],d[N];int p[N],q[N],o[N];bool z[N];int n;bool C(double x){memset(u,0,sizeof u);memset(v,0,sizeof v);memset(p,0,sizeof p);for(int i=1;i<=n;i++){p[0]=i;fill(d+1,d+n+1,1e100);memset(z,0,sizeof z);int j=0;do{z[j]=1;int k=p[j],y=0;double e=1e100;for(int l=1;l<=n;l++)if(!z[l]){double c=x*b[k][l]-a[k][l]-u[k]-v[l];if(c<d[l])d[l]=c,q[l]=j;if(d[l]<e)e=d[l],y=l;}for(int l=0;l<=n;l++)if(z[l])u[p[l]]+=e,v[l]-=e;else d[l]-=e;j=y;}while(p[j]);do{int y=q[j];p[j]=p[y];j=y;}while(j);}double s=0;for(int j=1;j<=n;j++)s+=a[p[j]][j]-x*b[p[j]][j];return s>=-1e-9;}int main(int Cc,char**V){ios::sync_with_stdio(0);cin.tie(0);int R=Cc>1?stoi(V[1]):1000;unsigned long long S=Cc>2?stoull(V[2]):1;mt19937_64 g(S);while(R--){n=g()%7+1;for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=g()%30+1,b[i][j]=g()%30+1;double l=0,r=30;for(int k=0;k<55;k++){double m=(l+r)/2;if(C(m))l=m;else r=m;}iota(o,o+n,1);double x=0;do{double A=0,B=0;for(int i=1;i<=n;i++)A+=a[i][o[i-1]],B+=b[i][o[i-1]];x=max(x,A/B);}while(next_permutation(o,o+n));if(abs(l-x)>1e-7)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P3705','P3705 [SDOI2017] 新生舞会',r'二分答案 $x$，把配对 $(i,j)$ 的权值改为 $a_{i,j}-xb_{i,j}$。若最大权完美匹配的权值和非负，则存在比值至少为 $x$ 的方案。每次用 Hungarian 算法求完美匹配，复杂度 $O(n^3\log\varepsilon^{-1})$。',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},parts=[BB,BP],extra=[('1\n5\n2\n','2.500000\n'),('2\n10 1\n1 10\n2 9\n9 2\n','5.000000\n'),('2\n3 8\n7 2\n1 1\n1 1\n','7.500000\n')])

C=r'''#include <bits/stdc++.h>
using namespace std;const int N=2505;int h[N],to[N],nx[N],s[N],p[N],o[N],z[N],e,c,n,k;double f[N][N],v[N];void D(int x){for(int i=h[x];i;i=nx[i])o[++c]=to[i],D(to[i]);z[x]=c-(x?find(o+1,o+c+1,x)-o:0)+1;}bool C(double x){for(int i=1;i<=n;i++)v[i]=p[i]-x*s[i];for(int j=0;j<=k;j++)f[n+1][j]=j?-1e100:0;for(int i=n;i;i--)for(int j=0;j<=k;j++){f[i][j]=f[i+z[o[i]]][j];if(j)f[i][j]=max(f[i][j],f[i+1][j-1]+v[o[i]]);}return f[1][k]>=0;}int main(){ios::sync_with_stdio(0);cin.tie(0);cin>>k>>n;for(int i=1,r;i<=n;i++){cin>>s[i]>>p[i]>>r;to[++e]=i;nx[e]=h[r];h[r]=e;}D(0);double l=0,r=10000;for(int i=0;i<35;i++){double m=(l+r)/2;if(C(m))l=m;else r=m;}cout<<fixed<<setprecision(3)<<l<<'\n';}
'''
CB=r'''#include <bits/stdc++.h>
using namespace std;const int N=24;int s[N],p[N],r[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int k,n;cin>>k>>n;for(int i=0;i<n;i++)cin>>s[i]>>p[i]>>r[i];long long A=0,B=1;for(int z=0;z<(1<<n);z++)if(__builtin_popcount((unsigned)z)==k){bool f=1;long long a=0,b=0;for(int i=0;i<n;i++)if(z>>i&1){if(r[i]&&!(z>>(r[i]-1)&1))f=0;a+=p[i];b+=s[i];}if(f&&a*B>A*b)A=a,B=b;}cout<<fixed<<setprecision(3)<<(double)A/B<<'\n';}
'''
CG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int n=g()%min(2500ULL,max(1ULL,z))+1,k=g()%n+1;cout<<k<<' '<<n<<'\n';for(int i=1;i<=n;i++)cout<<g()%10000+1<<' '<<g()%10000+1<<' '<<g()%i<<'\n';}
'''
CS=r'''#include <bits/stdc++.h>
using namespace std;const int N=20;int s[N],p[N],r[N],o[N],z[N],c;double f[N][N],v[N];bool C(double x,int n,int k){for(int i=1;i<=n;i++)v[i]=p[i]-x*s[i];for(int j=0;j<=k;j++)f[n+1][j]=j?-1e100:0;for(int i=n;i;i--)for(int j=0;j<=k;j++){f[i][j]=f[i+z[o[i]]][j];if(j)f[i][j]=max(f[i][j],f[i+1][j-1]+v[o[i]]);}return f[1][k]>=0;}int main(int Cc,char**V){ios::sync_with_stdio(0);cin.tie(0);int R=Cc>1?stoi(V[1]):1000;unsigned long long S=Cc>2?stoull(V[2]):1;mt19937_64 g(S);while(R--){int n=g()%14+1,k=g()%n+1;c=0;for(int i=1;i<=n;i++)s[i]=g()%30+1,p[i]=g()%30+1,r[i]=g()%i;function<void(int)>D=[&](int x){for(int i=1;i<=n;i++)if(r[i]==x)o[++c]=i,D(i);if(x)z[x]=c-(find(o+1,o+c+1,x)-o)+1;};D(0);double l=0,h=30;for(int i=0;i<50;i++){double m=(l+h)/2;if(C(m,n,k))l=m;else h=m;}double q=0;for(int m=0;m<(1<<n);m++)if(__builtin_popcount((unsigned)m)==k){bool F=1;double a=0,b=0;for(int i=1;i<=n;i++)if(m>>(i-1)&1){if(r[i]&&!(m>>(r[i]-1)&1))F=0;a+=p[i];b+=s[i];}if(F)q=max(q,a/b);}if(abs(l-q)>1e-7)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P4322','P4322 [JSOI2016] 最佳团体',r'二分性价比 $x$，令每人的新权值为 $P_i-xS_i$。按推荐树的 DFS 序做 DP：状态 $(i,j)$ 可跳过第 $i$ 个节点的整棵子树，也可选它并继续处理下一个节点，从而自动满足选择祖先的限制。单次检查 $O(NK)$。',{'.cpp':C,' 数据生成.cpp':CG,' 暴力.cpp':CB,' 对拍.cpp':CS},extra=[('1 1\n2 5 0\n','2.500\n'),('2 3\n2 6 0\n1 10 1\n1 1 0\n','5.333\n'),('1 3\n10 1 0\n2 8 1\n3 9 0\n','3.000\n')])
