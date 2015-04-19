#include<bits/stdc++.h>
#define mx 100005
#define pb push_back
#define ll long long
using namespace std;
bool taken[mx];
ll child[mx];
vector<int>ad[mx];
ll ans;
void dfs(int u)
{
    taken[u]=1;
    ll x=0;
    for(int i=0;i<ad[u].size();i++)
    {
        int v=ad[u][i];
        if(!taken[v]){
            dfs(v);
             ll xx=child[v]+1;
            child[u]+=xx;
            x+=(xx*(xx-1)/2);
        }
    }
    ans+=(child[u]*(child[u]-1)/2);
    ans-=x;

}
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        for(int i=0;i<mx;i++)ad[i].clear();
        int n;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            int u, v;
            cin>>u>>v;
            ad[u-1].pb(v-1);
        }
        memset(taken,0,sizeof taken);

        memset(child,0,sizeof child);
        ans=0;
        dfs(0);
        printf("Case %d: %d %lld\n",cas,n-1,ans);



    }



}
