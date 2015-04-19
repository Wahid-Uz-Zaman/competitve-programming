#include<bits/stdc++.h>
#define mx 10005
#define pb push_back
#define ll long long
using namespace std;

int dist[mx];
struct node
{
  int nn;
  int dist;
  node(int x,int y=INT_MAX)
  {
     nn=x;dist=y;
  }
  bool operator<(const node t)const
  {
      return (dist<t.dist)||(dist==t.dist && nn<t.nn);
  }

};
struct edge
{
    int v;int c;
    edge(int x,int y){v=x,c=y;}
};
struct ansr
{
    ll x;int y;
    ansr(ll a, int b){x=a;y=b;}
};
vector<edge>ad[mx];
set<node>s;
bool taken[mx];
ansr mst_prim(int n,int A)
{
    memset(taken,0,sizeof taken);
    ll ans=0;
    int portnum=0;
    //s.insert(node(0,0)),dist[0]=0,taken[0]=1;
    for(int i=0;i<n;i++){s.insert(node(i));dist[i]=INT_MAX;}
    while(!s.empty())
    {
        node cur=*s.begin();
        s.erase(s.find(cur));
        int u=cur.nn,c=cur.dist;
        taken[u]=1;
        if(c<A)ans+=c;
        else {ans+=A;portnum++;}
        for(int i=0;i<ad[u].size();i++)
        {
            edge t=ad[u][i];
            if(taken[t.v])continue;
            if(dist[t.v]>t.c){
                s.erase(s.find(node(t.v,dist[t.v])));
                dist[t.v]=t.c;
                s.insert(node(t.v,dist[t.v]));

            }
        }

    }
    return ansr(ans,portnum);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        for(int i=0;i<mx;i++)ad[i].clear();
        int n,m,A;
        scanf("%d %d %d",&n,&m,&A);
        for(int i=1;i<=m;i++)
        {
            int u,v,c;
            scanf("%d %d %d",&u,&v,&c);
            u--,v--;
            ad[u].pb(edge(v,c));

            ad[v].pb(edge(u,c));
        }
        ansr ans=mst_prim(n,A);
        printf("Case %d: %lld %d\n",cas,ans.x,ans.y);

    }
    return 0;
}
