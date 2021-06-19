#include <bits/stdc++.h>
#include <windows.h>
#define ld long double

using namespace std;
const int N=1010;
const ld eps=1e-14,inf=1e9;
const ld deps=1e-6;
double ans[N];
int tp[N];
int flag;
inline int zh(ld x){
    return (int)(x+deps);
}
inline bool check(ld x){
    return fabs(x-zh(x))>deps;
}
namespace LP{
    ld a[N][105]; int id[N],n,m;
    void pivot(int r,int c){
	swap(id[r+n],id[c]);
	ld t=-a[r][c]; a[r][c]=-1;
	for (int i=0; i<=n; ++i) a[r][i]/=t;
	for (int i=0; i<=m; ++i)
	    if (a[i][c]&&r!=i){
		t=a[i][c]; a[i][c]=0;
		for (int j=0; j<=n; ++j)
		    a[i][j]+=t*a[r][j];
	    }
	return;
    }
    void solve(int _m,int _n,ld f[][105]){
	n=_n,m=_m;
	for (int i=1; i<=n; ++i) id[i]=i,tp[i]=0;
	for (int i=0; i<=m; ++i)
	    for (int j=0; j<=n; ++j)
		a[i][j]=f[i][j];
	flag=0;
	while(true){
	    int i=0,j=0;
	    for (int k=1; k<=m; ++k)
		if (a[k][0]<-eps&&(!i||(rand()&1))) i=k;
	    if (!i) break;
	    for (int k=1; k<=n; ++k)
		if (a[i][k]>eps&&(!j||rand()&1)){
		    j=k; break;
		}
	    if (!j) return;
	    pivot(i,j);
	}
	ld t;
	while(true){
	    int i=0,j=0; ld w=eps;
	    for (int k=1; k<=n; ++k)
		if (a[0][k]>w) w=a[0][j=k];
	    if (!j) break;
	    w=inf;
	    for (int k=1; k<=m; ++k)
		if (a[k][j]<-eps&&(t= (-a[k][0]/a[k][j]) )<w)
		    w=t,i=k;
	    if (!i){
		flag=2; return;
	    }
	    pivot(i,j);
	}
	ans[0]=a[0][0];
	for (int i=n+1; i<=n+m; ++i) tp[id[i]]=i-n;
	for (int i=1; i<=n; ++i)
	    if (tp[i]) ans[i]=a[tp[i]][0];
	    else ans[i]=0;
	flag=1;
	return;
    }
}
bool exi;
ld Ans;
int ans_z[N];

namespace approximate{
    int x[N],v[N],n,m;
    ld a[N][105];
    int rand_solve(int P,int T){
	int W=P/2,rans=-inf;
	while(T--){
	    for (int i=1; i<=n; ++i)
		x[i]=max(0,v[i]-rand()%P+W);
	    int rflag=1,tmp=0;
	    for (int i=1; i<=n; ++i)
		tmp+=x[i]*a[0][i];
	    if (tmp<=rans) continue;
	    for (int i=1; i<=m; ++i){
		int sum=0;
		for (int j=0; j<=n; ++j)
		    sum+=a[i][j]*x[j];
		if (sum<0){
		    rflag=0; break;
		}
	    }
	    if (rflag)
		rans=tmp;
	    if (rans>ans_z[0]){
		exi=1;
		for (int i=1; i<=n; ++i)
		    ans_z[i]=x[i];
		ans_z[0]=rans;
	    }
	}
	return rans;
    }
    const int delta=1e6;//增量
    void solve(int _m,int _n,ld f[][105]){
	m=_m,n=_n;
	for (int i=0; i<=m; ++i)
	    for (int j=0; j<=n; ++j)
		a[i][j]=f[i][j];
	x[0]=1;
	LP::solve(_m,_n,a);
	for (int i=1; i<=n; ++i)
	    v[i]=zh(ans[i]);
	int T=3,S=rand_solve(T,delta),W=delta;//T为上界
	while(1){
	    int tmp=rand_solve(T*2,W+delta);
	    if (tmp<=S) break;
	    T<<=1,W+=delta;
	}
	return;
    }
}

ld a[N*5][105];
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
	scanf("%Lf",&a[0][i]);
    for (int i=1; i<=m; ++i){
	for (int j=1; j<=n; ++j)
	    scanf("%Lf",&a[i][j]),a[i][j]*=-1;
	scanf("%Lf",&a[i][0]);
    }
    approximate::solve(m,n,a);
    if (!exi) cout<<"infeasible";
    else{
	cout<<ans_z[0]<<endl;
	for (int i=1; i<=n; ++i)
	    cout<<ans_z[i]<<" ";
    }
    return 0;
}
