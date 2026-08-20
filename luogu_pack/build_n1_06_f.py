from build_lib import add

A=r'''#include <bits/stdc++.h>
using namespace std;const int N=100000,E=800000,P=1e9+7;int p[N],u[N+5],l[N+5],k[N+5],o[N+5],s[N+6],c[N+5],x[E+5],y[E+5],z[E+5],t[E+5],w[E+5],a[N+5],b[N+5],d[N+5],q[7],h[64],n,m;bool v[N+5];void F(int n,int*f,int L){memset(f,0,(L+1)*sizeof(int));for(int i=1;i<=n;i++){long long r=0;for(int j=i;j<=n;j+=i)r+=n/j;f[i]=r%P;}}void G(int L){memset(l,0,(L+1)*sizeof(int));memset(o,0,(L+1)*sizeof(int));m=0;for(int i=1;i<=L;i++)if(u[i]){int f=0,g=i;while(g>1)q[f++]=p[k[g]],g/=p[k[g]];h[0]=1;for(int j=1;j<1<<f;j++){int e=j&-j;h[j]=h[j^e]*q[__builtin_ctz(e)];}for(int j=0;j<1<<f;j++)for(int e=j;;e=(e-1)&j){int A=h[j],B=i/A*h[e];if(A<B)x[m]=A,y[m]=B,z[m]=i,l[A]++,l[B]++,m++;if(!e)break;}}for(int i=0;i<m;i++){int A=x[i],B=y[i];if(l[A]<l[B]||l[A]==l[B]&&A<B)swap(A,B);x[i]=A;y[i]=B;o[A]++;}s[1]=0;for(int i=1;i<=L;i++)s[i+1]=s[i]+o[i],c[i]=s[i];for(int i=0;i<m;i++){int j=c[x[i]]++;t[j]=y[i];w[j]=z[i];}}int main(){ios::sync_with_stdio(0);cin.tie(0);u[1]=1;for(int i=2;i<=N;i++){if(!v[i])k[i]=n,p[n++]=i,u[i]=-1;for(int j=0;j<n&&i*p[j]<=N;j++){v[i*p[j]]=1;k[i*p[j]]=j;if(i%p[j]==0){u[i*p[j]]=0;break;}u[i*p[j]]=-u[i];}}int T;cin>>T;while(T--){int A,B,C;cin>>A>>B>>C;if(A>B)swap(A,B);if(B>C)swap(B,C);if(A>B)swap(A,B);F(A,a,C);F(B,b,C);F(C,d,C);G(C);long long r=0;for(int i=1;i<=C;i++)for(int j=s[i];j<s[i+1];j++){int B=t[j],X=w[j];for(int k=s[B];k<s[B+1];k++){int D=t[k];long long Z=1LL*i/__gcd(i,D)*D;if(Z>C)continue;int Y=w[k],V=Z;long long e=(1LL*a[X]*((1LL*b[Y]*d[V]+1LL*b[V]*d[Y])%P)+1LL*a[Y]*((1LL*b[X]*d[V]+1LL*b[V]*d[X])%P)+1LL*a[V]*((1LL*b[X]*d[Y]+1LL*b[Y]*d[X])%P))%P;r=(r+u[i]*u[B]*u[D]*e)%P;}}for(int i=0;i<m;i++){int A=x[i],B=y[i],L=z[i];long long e=(1LL*a[L]*b[L]%P*d[B]+1LL*a[L]*b[B]%P*d[L]+1LL*a[B]*b[L]%P*d[L])%P;r=(r+u[A]*e)%P;e=(1LL*a[L]*b[L]%P*d[A]+1LL*a[L]*b[A]%P*d[L]+1LL*a[A]*b[L]%P*d[L])%P;r=(r+u[B]*e)%P;}for(int i=1;i<=C;i++)r=(r+1LL*u[i]*a[i]%P*b[i]%P*d[i])%P;cout<<(r+P)%P<<'\n';}}
'''
B=r'''#include <bits/stdc++.h>
using namespace std;int f(long long n){int r=0;for(long long i=1;i*i<=n;i++)if(n%i==0)r+=1+(i*i<n);return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){int A,B,C;cin>>A>>B>>C;long long r=0;for(int i=1;i<=A;i++)for(int j=1;j<=B;j++)for(int k=1;k<=C;k++)r+=f(1LL*i*j*k);cout<<r%1000000007<<'\n';}}
'''
C=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100000;mt19937_64 g(s);int T=g()%10+1;z=min(100000ULL,min(max(1ULL,z),200000ULL/T));cout<<T<<'\n';while(T--)cout<<g()%z+1<<' '<<g()%z+1<<' '<<g()%z+1<<'\n';}
'''
D=r'''#include <bits/stdc++.h>
using namespace std;const int N=16,E=1000,P=1e9+7;int u[N],x[E],y[E],z[E],t[E],w[E],g[N],o[N],s[N+1],c[N],a[N],b[N],d[N],m;void F(int n,int*f,int L){memset(f,0,N*sizeof(int));for(int i=1;i<=n;i++)for(int j=i;j<=n;j+=i)f[i]+=n/j;}long long S(int A,int B,int C){if(A>B)swap(A,B);if(B>C)swap(B,C);if(A>B)swap(A,B);F(A,a,C);F(B,b,C);F(C,d,C);memset(g,0,sizeof g);memset(o,0,sizeof o);m=0;for(int i=1;i<=C;i++)if(u[i])for(int j=i+1;j<=C;j++)if(u[j]&&1LL*i/__gcd(i,j)*j<=C)x[m]=i,y[m]=j,z[m]=i/__gcd(i,j)*j,g[i]++,g[j]++,m++;for(int i=0;i<m;i++){int A=x[i],B=y[i];if(g[A]<g[B]||g[A]==g[B]&&A<B)swap(A,B);x[i]=A;y[i]=B;o[A]++;}s[1]=0;for(int i=1;i<=C;i++)s[i+1]=s[i]+o[i],c[i]=s[i];for(int i=0;i<m;i++){int j=c[x[i]]++;t[j]=y[i];w[j]=z[i];}long long r=0;for(int i=1;i<=C;i++)for(int j=s[i];j<s[i+1];j++){int B=t[j],X=w[j];for(int k=s[B];k<s[B+1];k++){int D=t[k],V=i/__gcd(i,D)*D;if(V>C)continue;int Y=w[k];r+=1LL*u[i]*u[B]*u[D]*(a[X]*(b[Y]*d[V]+b[V]*d[Y])+a[Y]*(b[X]*d[V]+b[V]*d[X])+a[V]*(b[X]*d[Y]+b[Y]*d[X]));}}for(int i=0;i<m;i++){int A=x[i],B=y[i],L=z[i];r+=u[A]*(a[L]*b[L]*d[B]+a[L]*b[B]*d[L]+a[B]*b[L]*d[L]);r+=u[B]*(a[L]*b[L]*d[A]+a[L]*b[A]*d[L]+a[A]*b[L]*d[L]);}for(int i=1;i<=C;i++)r+=u[i]*a[i]*b[i]*d[i];return (r%P+P)%P;}int f(int n){int r=0;for(int i=1;i*i<=n;i++)if(n%i==0)r+=1+(i*i<n);return r;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long e=C>2?stoull(v[2]):1;mt19937_64 q(e);for(int i=1;i<N;i++){int X=i;u[i]=1;for(int j=2;j*j<=X;j++)if(X%j==0){X/=j;u[i]=-u[i];if(X%j==0){u[i]=0;break;}}if(u[i]&&X>1)u[i]=-u[i];}while(R--){int A=q()%12+1,B=q()%12+1,C=q()%12+1;long long r=0;for(int i=1;i<=A;i++)for(int j=1;j<=B;j++)for(int k=1;k<=C;k++)r+=f(i*j*k);if(S(A,B,C)!=r%P)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P4619','P4619 [SDOI2018] 旧试题',r'''把约数拆到三个因子中，并要求它们两两互质。对三个互质条件分别使用莫比乌斯反演，可得

$$\sum_{u,v,w}\mu(u)\mu(v)\mu(w)F_A([u,w])F_B([u,v])F_C([v,w]),$$

其中

$$F_X(n)=\sum_{n\mid d}\left\lfloor\frac Xd\right\rfloor.$$

只有平方因子自由的 $u,v,w$ 有贡献。以这些数为点，当 $[u,v]\le C$ 时连边。三个互异点的贡献对应图中的三角形；按度数和编号给边定向后，每个三角形只会作为一条长为二的有向路径出现一次，再补上两个点相等以及三个点相等的情况。

固定平方因子自由的最小公倍数 $L$，其每个质因子可只在左端、只在右端或同时出现，所以边可以按 $3^{\omega(L)}$ 枚举。全范围只有 $760741$ 条无向非自环边，使用静态数组保存。各个 $F$ 数组的计算量为调和级数，图的三角形枚举使用按度定向的经典复杂度界。

空间复杂度 $O(n+m)$。''',{'.cpp':A,' 数据生成.cpp':C,' 暴力.cpp':B,' 对拍.cpp':D},extra=[('1\n1 1 1\n','1\n'),('3\n1 2 3\n2 3 4\n4 5 6\n','14\n91\n750\n'),('1\n3 7 2\n','186\n'),('2\n8 1 5\n6 6 6\n','172\n1668\n')])
