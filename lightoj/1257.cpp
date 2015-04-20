#include<cstdio>
#include<cstring>
#include<vector>
#define max 30005
#define mx(a,b) a>b?a:b
using namespace std;
int n;
bool taken[max];
int cost[max];
int cost_temp[max];
struct edge
{
    int v;
    int w;
};

void dfs(int s,vector<edge>a[max])
{
    taken[s]=1;
    for(int i=0;i<a[s].size();i++)
    {
        edge tp=a[s][i];
        int v,w;
        v=tp.v;
        w=tp.w;
        if(!taken[v]) {cost[v]=cost[s]+w;dfs(v,a);}
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        vector<edge>a[max];
        scanf("%d",&n);
        for(int j=1;j<n;j++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            edge tp;
            tp.v=v;
            tp.w=w;
            a[u].push_back(tp);
            tp.v=u;
            a[v].push_back(tp);


        }
        memset(taken,0,sizeof(taken));
        memset(cost,0,sizeof(cost));

        dfs(0,a);
        int ans=-1,m;
        for(int j=0;j<n;j++)
        {
            if(cost[j]>ans) {m=j;ans=cost[j];}
        }


        ans=0;

            memset(taken,0,sizeof(taken));
            memset(cost,0,sizeof(cost));
             dfs(m,a);
                int x;
             for(int j=0;j<n;j++)
             {
                if(cost[j]>ans) {ans=cost[j];x=j;}
                cost_temp[j]=cost[j];
             }
                ans=0;

            memset(taken,0,sizeof(taken));
            memset(cost,0,sizeof(cost));
             dfs(x,a);
             printf("Case %d:\n",i);
            for(int j=0;j<n;j++)
             {
                printf("%d\n",mx(cost[j],cost_temp[j]));
             }





    }
    return 0;
}
