from build_lib import add

A=r'''#include <bits/stdc++.h>
using namespace std;const int N=50005;int p[N],v[N],u[N],s[N];long long f(int n,int m,int k){n/=k;m/=k;if(n>m)swap(n,m);long long r=0;for(int l=1,q;l<=n;l=q+1){q=min(n/(n/l),m/(m/l));r+=1LL*(s[q]-s[l-1])*(n/l)*(m/l);}return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int z=0;u[1]=1;for(int i=2;i<N;i++){if(!v[i])p[z++]=i,u[i]=-1;for(int j=0;j<z&&i*p[j]<N;j++){v[i*p[j]]=1;if(i%p[j]==0){u[i*p[j]]=0;break;}u[i*p[j]]=-u[i];}}for(int i=1;i<N;i++)s[i]=s[i-1]+u[i];int T;cin>>T;while(T--){int a,b,c,d,k;cin>>a>>b>>c>>d>>k;cout<<f(b,d,k)-f(a-1,d,k)-f(b,c-1,k)+f(a-1,c-1,k)<<'\n';}}
'''
AB=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){int a,b,c,d,k,r=0;cin>>a>>b>>c>>d>>k;for(int x=a;x<=b;x++)for(int y=c;y<=d;y++)r+=__gcd(x,y)==k;cout<<r<<'\n';}}
'''
AG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int T=g()%min(50000ULL,max(1ULL,z))+1;cout<<T<<'\n';while(T--){int b=g()%50000+1,a=g()%b+1,d=g()%50000+1,c=g()%d+1,k=g()%50000+1;cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<k<<'\n';}}
'''
AS=r'''#include <bits/stdc++.h>
using namespace std;const int N=105;int u[N],s[N];long long f(int n,int m,int k){n/=k;m/=k;if(n>m)swap(n,m);long long r=0;for(int l=1,q;l<=n;l=q+1){q=min(n/(n/l),m/(m/l));r+=1LL*(s[q]-s[l-1])*(n/l)*(m/l);}return r;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long z=C>2?stoull(v[2]):1;mt19937_64 g(z);u[1]=1;for(int i=1;i<100;i++)for(int j=i+i;j<100;j+=i)u[j]-=u[i];for(int i=1;i<100;i++)s[i]=s[i-1]+u[i];while(R--){int b=g()%50+1,a=g()%b+1,d=g()%50+1,c=g()%d+1,k=g()%20+1;long long A=f(b,d,k)-f(a-1,d,k)-f(b,c-1,k)+f(a-1,c-1,k),B=0;for(int x=a;x<=b;x++)for(int y=c;y<=d;y++)B+=__gcd(x,y)==k;if(A!=B)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P2522','P2522 [HAOI2011] Problem b',r'''设 $F(n,m,k)$ 表示两个上界内 gcd 为 $k$ 的数对数。两数同除 $k$ 后，用莫比乌斯反演：

$$F(n,m,k)=\sum_{i=1}^{\min(\lfloor n/k\rfloor,\lfloor m/k\rfloor)}\mu(i)\left\lfloor\frac{n/k}{i}\right\rfloor\left\lfloor\frac{m/k}{i}\right\rfloor.$$

预处理 $\mu$ 前缀和，整除分块求 $F$，矩形答案用四次前缀容斥。''',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},extra=[('1\n1 1 1 1 1\n','1\n'),('1\n1 3 1 3 1\n','7\n'),('1\n2 4 3 5 2\n','1\n'),('1\n1 5 1 5 6\n','0\n')])

B=r'''#include <bits/stdc++.h>
using namespace std;const int N=50005;int p[N],v[N],u[N],s[N];long long f(int n,int m){if(n>m)swap(n,m);long long r=0;for(int l=1,q;l<=n;l=q+1){q=min(n/(n/l),m/(m/l));r+=1LL*(s[q]-s[l-1])*(n/l)*(m/l);}return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int z=0;u[1]=1;for(int i=2;i<N;i++){if(!v[i])p[z++]=i,u[i]=-1;for(int j=0;j<z&&i*p[j]<N;j++){v[i*p[j]]=1;if(i%p[j]==0){u[i*p[j]]=0;break;}u[i*p[j]]=-u[i];}}for(int i=1;i<N;i++)s[i]=s[i-1]+u[i];int T;cin>>T;while(T--){int a,b,d;cin>>a>>b>>d;cout<<f(a/d,b/d)<<'\n';}}
'''
BB=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){int a,b,d,r=0;cin>>a>>b>>d;for(int x=1;x<=a;x++)for(int y=1;y<=b;y++)r+=__gcd(x,y)==d;cout<<r<<'\n';}}
'''
BG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int T=g()%min(50000ULL,max(1ULL,z))+1;cout<<T<<'\n';while(T--){int a=g()%50000+1,b=g()%50000+1,d=g()%min(a,b)+1;cout<<a<<' '<<b<<' '<<d<<'\n';}}
'''
BS=r'''#include <bits/stdc++.h>
using namespace std;const int N=105;int u[N],s[N];long long f(int n,int m){if(n>m)swap(n,m);long long r=0;for(int l=1,q;l<=n;l=q+1){q=min(n/(n/l),m/(m/l));r+=1LL*(s[q]-s[l-1])*(n/l)*(m/l);}return r;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long z=C>2?stoull(v[2]):1;mt19937_64 g(z);u[1]=1;for(int i=1;i<100;i++)for(int j=i+i;j<100;j+=i)u[j]-=u[i];for(int i=1;i<100;i++)s[i]=s[i-1]+u[i];while(R--){int a=g()%50+1,b=g()%50+1,d=g()%min(a,b)+1;long long A=f(a/d,b/d),B=0;for(int x=1;x<=a;x++)for(int y=1;y<=b;y++)B+=__gcd(x,y)==d;if(A!=B)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P3455','P3455 [POI 2007] ZAP-Queries',r'''把 $x,y$ 同除以 $d$，问题变成统计两个矩形上界内的互质有序对。由莫比乌斯反演，答案为

$$\sum_i\mu(i)\left\lfloor\frac{a/d}{i}\right\rfloor\left\lfloor\frac{b/d}{i}\right\rfloor.$$

线性筛预处理莫比乌斯前缀和，每组询问整除分块，复杂度 $O(\sqrt n)$。''',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},extra=[('1\n1 1 1\n','1\n'),('1\n3 3 1\n','7\n'),('1\n10 12 2\n','21\n'),('1\n5 5 6\n','0\n')])

C=r'''#include <bits/stdc++.h>
using namespace std;const int N=50005;int p[N],v[N],u[N],m[N],s[N];long long d[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int z=0;u[1]=1;for(int i=2;i<N;i++){if(!v[i])p[z++]=i,u[i]=-1;for(int j=0;j<z&&i*p[j]<N;j++){v[i*p[j]]=1;if(i%p[j]==0){u[i*p[j]]=0;break;}u[i*p[j]]=-u[i];}}for(int i=1;i<N;i++)s[i]=s[i-1]+u[i];for(int i=1;i<N;i++)for(int j=i;j<N;j+=i)m[j]++;for(int i=1;i<N;i++)d[i]=d[i-1]+m[i];int T;cin>>T;while(T--){int n,k;cin>>n>>k;if(n>k)swap(n,k);long long r=0;for(int l=1,q;l<=n;l=q+1){q=min(n/(n/l),k/(k/l));r+=1LL*(s[q]-s[l-1])*d[n/l]*d[k/l];}cout<<r<<'\n';}}
'''
CB=r'''#include <bits/stdc++.h>
using namespace std;int f(int x){int r=0;for(int i=1;i*i<=x;i++)if(x%i==0)r+=1+(i*i<x);return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){int n,m;long long r=0;cin>>n>>m;for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)r+=f(i*j);cout<<r<<'\n';}}
'''
CG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int T=g()%min(50000ULL,max(1ULL,z))+1;cout<<T<<'\n';while(T--)cout<<g()%50000+1<<' '<<g()%50000+1<<'\n';}
'''
CS=r'''#include <bits/stdc++.h>
using namespace std;const int N=105;int u[N],t[N],d[N];int f(int x){int r=0;for(int i=1;i*i<=x;i++)if(x%i==0)r+=1+(i*i<x);return r;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long z=C>2?stoull(v[2]):1;mt19937_64 g(z);u[1]=1;for(int i=1;i<100;i++)for(int j=i+i;j<100;j+=i)u[j]-=u[i];for(int i=1;i<100;i++)for(int j=i;j<100;j+=i)t[j]++;for(int i=1;i<100;i++)d[i]=d[i-1]+t[i];while(R--){int n=g()%50+1,m=g()%50+1;long long A=0,B=0;for(int x=1;x<=min(n,m);x++)A+=1LL*u[x]*d[n/x]*d[m/x];for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)B+=f(i*j);if(A!=B)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P3327','P3327 [SDOI2015] 约数个数和',r'''利用恒等式 $d(ij)=\sum_{a\mid i}\sum_{b\mid j}[\gcd(a,b)=1]$，再对互质条件做莫比乌斯反演，可得

$$\sum_{x=1}^{\min(n,m)}\mu(x)D(\lfloor n/x\rfloor)D(\lfloor m/x\rfloor),$$

其中 $D(t)=\sum_{i=1}^t d(i)$。预处理 $\mu$ 和 $D$，按两个整除商共同分块。''',{'.cpp':C,' 数据生成.cpp':CG,' 暴力.cpp':CB,' 对拍.cpp':CS},extra=[('1\n1 1\n','1\n'),('1\n2 2\n','8\n'),('1\n3 4\n','36\n'),('1\n10 10\n','596\n')])
