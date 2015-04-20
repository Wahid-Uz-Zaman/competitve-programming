#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include<algorithm>
#include<vector>
#define inf 1000000009
#define mx 600
#define pb push_back
using namespace std;
int dist[mx];
int costfunc[mx][mx];
vector<int>a[mx];
struct node
{
    int cost;
    int no;
    node(int x,int y)
    {
        cost=x,no=y;
    }
    bool operator<(const node t)const
    {
        return cost<t.cost ||(cost==t.cost && no<t.no);
    }
};
void ini()
{
    for(int i=0;i<mx;i++) dist[i]=inf;
}
void dijkstra(int s)
{
    ini();
    dist[s]=0;
    set<node> S;
    S.insert(node(dist[s],s));
    while(!S.empty())
    {
        node tmp=*S.begin();
        S.erase(S.begin());
        int u=tmp.no;
        for(int i=0;i<a[u].size();i++)
        {
            int v=a[u][i];

            if(dist[v]>max(dist[u],costfunc[u][v]))
            {

                if(dist[v]!=inf) S.erase(S.find(node(dist[v],v)));
                dist[v]=max(dist[u],costfunc[u][v]);
                S.insert(node(dist[v],v));
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
        memset(costfunc,0,sizeof costfunc);
        int n,m;
        scanf("%d %d",&n,&m);
        for(int j=1;j<=m;j++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            a[u].pb(v);
            a[v].pb(u);
            if(costfunc[u][v]==0){
            costfunc[u][v]=w;
            costfunc[v][u]=w;
            }
            else
            {
                costfunc[v][u]=costfunc[u][v]=min(costfunc[u][v],w);

            }
        }
        int s;
        scanf("%d",&s);
        dijkstra(s);
        //for(int j=1;j<=n;j++) printf("%d %d\n",j,dist[j]);
        //if(dist[n]==inf) printf("Case %d: Impossible\n",i);
        //else printf("Case %d: %d\n",i,dist[n]);
        printf("Case %d:\n",i);
        for(int j=0;j<n;j++)
        {
            if(dist[j]!=inf) printf("%d\n",dist[j]);
            else printf("Impossible\n");
        }



    }
    return  0;
}
