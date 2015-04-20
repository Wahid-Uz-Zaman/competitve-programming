#include<cstdio>
#include<vector>
#include<cstring>
#define max 1005
using namespace std;
int k;
int n;
int m;

bool visit[max][max];
bool taken[max];
int man[105];
int cur;
void dfs(int s,vector<int>a[])
{
    taken[s]=1;
    visit[cur][s]=1;
    for(int i=0;i<a[s].size();i++)
    {
        int x=a[s][i];
        if(taken[x]==0) dfs(x,a);
    }


}
int main()
{

    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        vector<int>a[max];
        scanf("%d %d %d",&k,&n,&m);
        for(int j=1;j<=k;j++) scanf("%d",&man[j]);
        for(int j=1;j<=m;j++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            a[u].push_back(v);
        }
        for(int j=1;j<=k;j++)
        {
            cur=man[j];
            memset(taken,0,sizeof(taken));
            dfs(cur,a);

        }
        int p,ans=0;
        for(int j=1;j<=n;j++)
        {
            for( p=1;p<=k;p++)
            {
                int x=man[p];
                if(visit[x][j]) continue;
                else break;
            }
            if(p==k+1) ans++;
        }
        printf("Case %d: %d\n",i,ans);
        memset(visit,0,sizeof(visit));
        memset(taken,0,sizeof(taken));

    }
    return 0;
}
