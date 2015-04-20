#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define pb push_back
#define mx 110
using namespace std;
bool taken[mx];
int s[mx];
int e[mx];
vector<int>a[mx];
void bfs(int x,int t[])
{
    taken[x]=1;
    queue<int>q;
    q.push(x);
    t[x]=0;
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        for(int i=0;i<a[tmp].size();i++)
        {
            if(!taken[a[tmp][i]])
            {
                t[a[tmp][i]]=t[tmp]+1;
                taken[a[tmp][i]]=1;
                q.push(a[tmp][i]);
            }
        }
    }


}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        for(int j=0;j<mx;j++) a[j].clear();
        memset(taken,0,sizeof taken);
        memset(s,0,sizeof s);
        memset(e,0,sizeof e);
        int n,m;
        scanf("%d %d",&n,&m);
        for(int j=1;j<=m;j++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            a[u].pb(v);
            a[v].pb(u);
        }
        int start,end;
        scanf("%d %d",&start,&end);
        int ans=-1;
        bfs(start,s);
        memset(taken,0,sizeof taken);
        bfs(end,e);
        for(int j=0;j<n;j++)
        {
            if(ans<s[j]+e[j]) ans=s[j]+e[j];

        }
        printf("Case %d: %d\n",i,ans);

    }

    return 0;
}
