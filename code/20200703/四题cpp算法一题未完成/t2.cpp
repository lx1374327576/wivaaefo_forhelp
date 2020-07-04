#include<cstring>
#include<cmath>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dow(i,l,r) for(int i=r;i>=l;i--)
#define rep0(i,r) for(int i=0,rr=r;i<rr;i++)
#define pb push_back
#define mp make_pair
#define fir first
#define sec second

int a[505],f[505][505],dp[505][505],n,val[505][505];

void dfs(int l,int r)
{
	if (f[l][r]!=-1) return;
	f[l][r]=0;
	rep(i,l,r-1) {
		if (f[l][i]==-1) dfs(l,i);
		if (f[i+1][r]==-1) dfs(i+1,r);
		if (!f[l][i] || !f[i+1][r]) continue;
		if (val[l][i]!=val[i+1][r]) continue;
		f[l][r]=1;
		val[l][r]=val[l][i]+1;
		break;
	}
}

int calc(int l,int r)
{
	if (f[l][r]) return dp[l][r]=1;
	if (dp[l][r]) return dp[l][r];
	dp[l][r]=n+1;
	rep(i,l,r-1) {
		dp[l][r]=min(dp[l][r],calc(l,i)+calc(i+1,r));
	}
	return dp[l][r];
}

void solve()
{
	scanf("%d",&n);
	rep(i,1,n) 
		scanf("%d",&a[i]);
	memset(f,-1,sizeof(f));
	rep(i,1,n) f[i][i]=1,val[i][i]=a[i];
	dfs(1,n);
//	rep(i,1,n)
//		rep(j,i,n)
//			printf("%d %d %d\n",i,j,f[i][j]);
	printf("%d\n",calc(1,n));
}

int main()                                                                                                                
{
	solve();
	return 0;
}
