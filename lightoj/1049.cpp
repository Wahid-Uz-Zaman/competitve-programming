#include<cstdio>
#include<cstring>
#include<vector>
#define max 105
using namespace std;
int main()
{
    //freopen("in2.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int cost[max][max];
        bool taken[max];
        int n;
        vector<int>a[max];
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            a[u].push_back(v);
            a[v].push_back(u);
            cost[u][v]=0;
            cost[v][u]=w;

        }//input
        memset(taken,0,sizeof(taken));
        int u=a[1][0];
        int ans=cost[1][u];
        int ans1=cost[u][1];
        taken[1]=1;
        taken[u]=1;
        for(int j=1;j<n;j++)
        {
            for(int k=0;k<a[u].size();k++)
            {
                int v=a[u][k];
                if(!taken[v]){ans1+=cost[v][u];ans+=cost[u][v];taken[v]=1;u=v;break;}
            }
        }
        ans+=cost[u][1];
        ans1+=cost[1][u];
        //printf("%d\n",ans);
        printf("Case %d: %d\n",i,ans<ans1?ans:ans1);




    }
    return 0;
}
