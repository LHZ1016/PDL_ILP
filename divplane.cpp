#include <bits/stdc++.h>
#define ld long double
using namespace std;
const int N=210;
const ld eps=1e-8,inf=1e9;
double ans[N];
int tp[N];
int flag;
namespace LP{
    double a[N][N]; int id[N],n,m;
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
    void solve(int _m,int _n,double f[][N]){
	n=_n,m=_m;
	for (int i=1; i<=n; ++i) id[i]=i,tp[i]=0;
	for (int i=0; i<=m; ++i)
	    for (int j=0; j<=n; ++j)
		a[i][j]=f[i][j];
	flag=0;
	while(true){
	    int i=0,j=0; ld w=-eps;
	    for (int k=1; k<=m; ++k)
		if (a[k][0]<w) w=a[i=k][0];
	    if (!i) break;
	    for (int k=1; k<=n; ++k)
		if (a[i][k]>eps){
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
double Ans;
int ans_z[N];
namespace divplane{

    double a[N][N]; int id[N],n,m;
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
    void work(){
	flag=0;
	while(true){
	    int i=0,j=0; ld w=-eps;
	    for (int k=1; k<=m; ++k)
		if (a[k][0]<w) w=a[i=k][0];
	    if (!i) break;
	    for (int k=1; k<=n; ++k)
		if (a[i][k]>eps){
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
    
    void solve(int _m,int _n,double f[][N]){
	n=_n,m=_m;
	for (int i=1; i<=n; ++i) id[i]=i,tp[i]=0;
	for (int i=0; i<=m; ++i)
	    for (int j=0; j<=n; ++j)
		a[i][j]=f[i][j];
	
	while(true){
	    work();
	    if (!flag) break;
	    int t=0; ld w=eps;
	    for (int i=1; i<=m; ++i)
		if (a[i][0]-floor(a[i][0]+eps)>w)
		    w=a[i][0]-floor(a[i][0]+eps),t=i;
	    if (t==0){
		for (int i=1; i<=n; ++i)
		    ans_z[i]=(int)(ans[i]+eps);
		Ans=(int)(ans[0]+eps),exi=true;
		cout<<Ans<<endl;
		for (int i=1; i<=n; ++i)
		    cout<<ans_z[i]<<" ";
		return;
	    }
	    a[++m][0]=-w;
	    for (int i=1; i<=n; ++i)
		a[m][i]=ceil(a[t][i]-eps)-a[t][i];
	}
	return;
    }
    
}

double a[N*5][N];
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
	scanf("%lf",&a[0][i]);
    for (int i=1; i<=m; ++i){
	for (int j=1; j<=n; ++j)
	    scanf("%lf",&a[i][j]),a[i][j]*=-1;
	scanf("%lf",&a[i][0]);
    }
    LP::solve(m,n,a);
    if (flag==0) puts("Infeasible");
    else if (flag==2) puts("Unbounded");
    else {
	divplane::solve(m,n,a);
	for (int i=0; i<=n; ++i)
	    ans_z[i]=ans[i]+eps;
	cout<<ans_z[0]<<endl;
	for (int i=1; i<=n; ++i)
	    cout<<ans_z[i]<<" ";
    }
    return 0;
}
