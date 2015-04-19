#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define mx 100005
using namespace std;
bool taken[mx];
vector<int>ad[mx];
int p[mx];
void bfs(int s,int e)
{
    memset(taken,0,sizeof taken);
    memset(p,-1,sizeof p);
    queue<int>q;
    q.push(s);
    taken[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        if(u==e)return;
        for(int i=0;i<ad[u].size();i++)
        {
            int v=ad[u][i];
            if(!taken[v])
            {
                taken[v]=1;p[v]=u;q.push(v);
            }
        }
        q.pop();


    }


}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        for(int i=0;i<mx;i++)ad[i].clear();
        int n;
        scanf("%d",&n);
        vector<int>x;
        for(int i=1;i<=n;i++)
        {
            int xx;
            scanf("%d",&xx);
            x.pb(xx);
        }
        for(int i=0;i<x.size()-1;i++)ad[x[i]].pb(x[i+1]),ad[x[i+1]].pb(x[i]);
        for(int i=0;i<x.size();i++)sort(ad[x[i]].begin(),ad[x[i]].end());
        int st=x[0],ed=x[n-1];
        bfs(st,ed);
        stack<int>ans;
        ans.push(ed);
        while(p[ed]!=-1)
        {
            ed=p[ed];
            ans.push(ed);
        }
        printf("Case %d:\n",cas);
        while(ans.size()>1)printf("%d ",ans.top()),ans.pop();
        printf("%d\n",ans.top());






    }


}

