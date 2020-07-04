#include<cstring>
#include<cmath>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dow(i,l,r) for(int i=r;i>=l;i--)
#define rep0(i,r) for(int i=0,rr=r;i<rr;i++)
#define pb push_back
#define mp make_pair
#define fir first
#define sec second

const int MAXN=30050;
int n,m,tot,vis[MAXN];
char s[MAXN];

typedef pair< pair<int,int>, pair<int,int> > piir;
piir que[MAXN];

int useful(piir po1,piir po2)
{
	int x1=po1.first.first,y1=po1.first.second,
		l1=po1.second.first,c1=po1.second.second;
	int x2=po2.first.first,y2=po2.first.second,
		l2=po2.second.first,c2=po2.second.second;
	int x3=min(x1,x2),y3=min(y1,y2);
	int x4=max(x1+l1-1,x2+l2-1),y4=max(y1+c1-1,y2+c2-1);
	int l=x4-x3+1,c=y4-y3+1;
	if (max(l1,c1)+max(l2,c2)>=max(l,c)) {
		que[++tot]=mp(mp(x3,y3),mp(l,c));
		vis[tot] = 1;
		return 1;
	}
	return 0;
}


void solve()
{
	scanf("%d",&n);
	tot=0;
	rep(i,1,n) {
		scanf("%s",s+1);
		rep(j,1,n)
			if (s[j]=='#') que[++tot]=mp(mp(i,j),mp(1,1));
	}
	int index=0;
	rep(i,1,tot) vis[i]=1;
	while (1) {
		int flag=0;
		for(int i=tot;i>=1;i--) {
//			if (i==tot[op]) printf("%d %d\n",que[op][i].first.first,que[op][i].first.second);
			if (!vis[i]) continue;
			for(int j=i-1;j>=1;j--) {
				if (!vis[j]) continue;
				if (useful(que[i],que[j])) {
					vis[i]=0;
					vis[j]=0;
					flag=1;
					break;	
				}
			}
			if (flag) break;
		}
		if (!flag) break;
	}
//	printf("%d\n",tot);
	int ans=0;
	rep(i,1,tot)
		if (vis[i])
			ans+=max(que[i].second.first,que[i].second.second); 
	printf("%d\n",ans);
}

int main()                                                                                                                
{
	solve();
	return 0;
}
