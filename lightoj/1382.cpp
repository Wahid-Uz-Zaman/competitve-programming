#include<bits/stdc++.h>
#define pb push_back
#define mx 1005
#define ll long long
#define mod 1000000007
using namespace std;
int ncr[mx][mx];
void make()
{
    for(int i=0;i<mx;i++)ncr[i][0]=1,ncr[i][i]=1,ncr[i][1]=i;
    for(int i=3;i<mx;i++)
    {
        for(int j=2;j<i;j++)ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
    }


}
int deg[mx];
ll dp[mx];
vector<int>ad[mx];
int child[mx];
ll ans;
void dfs(int u)
{
    for(int i=0;i<ad[u].size();i++)
    {
        int v=ad[u][i];
        dfs(v);

        dp[u]=(((dp[u]*dp[v])%mod)*ncr[child[u]+child[v]+1][child[v]+1])%mod;
        child[u]+=(child[v]+1);
    }
    //printf("%d %lld\n",u,dp[u]);

}

int main()
{
    make();
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        for(int i=0;i<mx;i++)ad[i].clear();
        //memset(dp,1,sizeof dp);
        for(int i=0;i<mx;i++)dp[i]=1;
        memset(deg,0,sizeof deg);
        memset(child,0,sizeof child);
        int n;
        scanf("%d",&n);
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            ad[u-1].pb(v-1);
            deg[v-1]++;
        }
        for(int i=0;i<n;i++)if(deg[i]==0){dfs(i);ans=dp[i];break;}
        printf("Case %d: %lld\n",cas,ans);

    }

}
