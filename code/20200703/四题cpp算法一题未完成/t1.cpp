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

int *arr1,*arr2,best,a[50],b[50],val[50],n,m,tot1,tot2;

void dfs(int x,int y,int sum,int z)
{
	if (sum+max(z,tot1-x+1)>=best) return;
	if (x>tot1) {
		best = min(best,sum);
//		printf("%d\n",best);
		return;
	}
	rep(i,y,tot2) {
		if (!arr2[i]) continue;
		int now = min(arr1[x],arr2[i]);
		arr1[x]-=now;
		arr2[i]-=now;
		if (!arr1[x]) dfs(x+1,1,sum+1,z-(arr2[i]==0));
		else dfs(x,i+1,sum+1,z-(arr2[i]==0));
		arr1[x]+=now;
		arr2[i]+=now;
	}
}

void solve()
{
	scanf("%d %d",&n,&m);
	rep(i,1,m) {
		int j,k,l;
		scanf("%d %d %d",&j,&k,&l);
		val[j]+=l;
		val[k]-=l;
	}
	int ans=0;
	rep0(i,n) {
		if (!val[i]) continue;
		rep(j,i+1,n-1) {
			if (val[i]+val[j]==0) {
				val[i]=val[j]=0;
				ans+=1;
				break;
			}
		}
	}
//	printf("%d\n",ans);
	tot1=0,tot2=0;
	rep0(i,n) {
		if (val[i]<0) a[++tot1]=-val[i];
		if (val[i]>0) b[++tot2]=val[i];
	}
	arr1=a,arr2=b;
	if (tot1>tot2) {
		swap(tot1,tot2);
		swap(arr1,arr2);
	}
	sort(arr1+1,arr1+tot1+1,greater<int>());
	sort(arr2+1,arr2+tot2+1,greater<int>());
//	rep(i,1,tot1) printf("%d%s",arr1[i],i<tot1?" ":"\n");
//	rep(i,1,tot2) printf("%d%s",arr2[i],i<tot2?" ":"\n");
	best = 10000; 
	dfs(1,1,0,tot2);
	printf("%d\n",best+ans); 
}

int main()                                                                                                                
{
//	freopen("output.in", "r", stdin);
	solve();
	return 0;
}
