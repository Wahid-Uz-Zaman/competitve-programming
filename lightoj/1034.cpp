#include<cstdio>
#include<cstring>
#include<vector>
#define max 100006
using namespace std;
vector<int>top_sort;
vector<int>a[max];
int  taken[max];
void dfs(int s)
{
    taken[s]=1;
    for(int i=0;i<a[s].size();i++)
    {
        int v=a[s][i];
        if(taken[v]==0) dfs(v);
    }
    //taken[s]=2;
    top_sort.push_back(s);
}
void dfs_(int s)
{
    taken[s]=1;
    for(int i=0;i<a[s].size();i++)
    {
        int v=a[s][i];
        if(taken[v]==0) dfs(v);
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        top_sort.clear();
        for(int j=0;j<max;j++) a[j].clear();
        int n,m;
        scanf("%d %d",&n,&m);

        memset(taken,0,sizeof(taken));
        for(int j=1;j<=m;j++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            a[u].push_back(v);
        }

        for(int j=1;j<=n;j++)
        {
            if(taken[j]==0) dfs(j);
        }

        memset(taken,0,sizeof(taken));
        int c=0;
        for(int j=top_sort.size()-1;j>=0;j--)
        {
            int u=top_sort[j];
            if(taken[u]==0)
            {
                c++;
                dfs_(u);
            }




        }
        printf("Case %d: %d\n",i,c);
    }

    return 0;
}
