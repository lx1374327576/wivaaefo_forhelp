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

const int MAXN=40050;
int n,m,tot1=0,tot2=0,use[505][505],col[505][505];

const int px[8]={-1,-2,-2,-1,1,2, 2, 1};
const int py[8]={-2,-1, 1, 2,2,1,-1,-2};

vector<int> G[MAXN];
int mx[MAXN],my[MAXN];
queue<int> que;
int dx[MAXN],dy[MAXN];
bool vis[MAXN];

bool find(int u)
{
    for(int i=0;i<G[u].size();i++)
    {
        if(!vis[G[u][i]]&&dy[G[u][i]]==dx[u]+1)
        {
            vis[G[u][i]]=true;
            if(!my[G[u][i]]||find(my[G[u][i]]))
            {
                mx[u]=G[u][i];
                my[G[u][i]]=u;
                return true;
            }
        }
    }
    return false;
}
int matching()
{
    memset(mx,0,sizeof(mx));
    memset(my,0,sizeof(my));
    int ans=0;
    while(true)
    {
        bool flag=false;
        while(!que.empty()) que.pop();
        memset(dx,0,sizeof(dx));
        memset(dy,0,sizeof(dy));
        for(int i=1;i<=tot1;i++)
            if(!mx[i]) que.push(i);
        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            for(int i=0;i<G[u].size();i++)
                if(!dy[G[u][i]])
                {
                    dy[G[u][i]]=dx[u]+1;
                    if(my[G[u][i]])
                    {
                        dx[my[G[u][i]]]=dy[G[u][i]]+1;
                        que.push(my[G[u][i]]);
                    }
                    else flag=true;
                }
        }
        if(!flag) break;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=tot1;i++)
            if(!mx[i]&&find(i)) ans++;
    }
    return ans;
}

int check(int x,int y)
{
	return col[x][y];
}

void solve()
{
	scanf("%d %d",&n,&m);
	rep(i,1,n) {
		col[i][1]=i%2;
		rep(j,2,n) col[i][j]=1-col[i][j-1];
	}
	rep(i,1,m) {
		int j,k;
		scanf("%d %d",&j,&k);
		use[j][k]=-1;
	}
	tot1=0,tot2=0;
	rep(i,1,n)
		rep(j,1,n) {
			if (use[i][j]==-1) continue;
			if (!check(i,j)) use[i][j]=++tot1;
			else use[i][j]=++tot2;
		} 
	rep(i,1,n) rep(j,1,n) {
		if (check(i,j) || use[i][j]==-1) continue;
		rep0(k,8) {
			int xx=i+px[k],yy=j+py[k];
			if (xx<1 || xx>n || yy<1 || yy>n) continue;
			if (use[xx][yy]==-1) continue;
			G[use[i][j]].pb(use[xx][yy]);	
		}
	}
	printf("%d\n",tot1+tot2-matching());;
}

int main()                                                                                                                
{
	solve();
	return 0;
}
