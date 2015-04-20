#include<cstdio>
#include<vector>
#include<cstring>
#define mx 105
#define pb push_back
using namespace std;
int taken[mx];
int cycle[mx];
int p[mx];
bool even[mx];
vector<int>a[mx];
int flag=0;
void dfs(int u)
{
    taken[u]=1;
    //c++;
    //sumc+=w[u];
    for(int i=0;i<a[u].size();i++)
    {
        int v=a[u][i];
        if(!taken[a[u][i]])
        {

            cycle[a[u][i]]=cycle[u]+1;
            if(even[u]) even[v]=0;
            else even[v]=1;
            p[v]=u;
            dfs(a[u][i]);
        }
        else if(p[u]!=v)
        {
            if((cycle[a[u][i]]-cycle[u]+1)%2) flag=1;
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("b.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        for(int i=0;i<mx;i++) a[i].clear();
        memset(taken,0,sizeof(taken));
        memset(cycle,0,sizeof cycle);
        memset(p,-1,sizeof p);
        memset(even,0,sizeof even);

        int n,m;
        //int sum=0;

        scanf("%d %d",&n,&m);
       // if(cas==36)
        //printf("%d %d\n",n,m);

        for(int j=1;j<=m;j++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            //if(cas==36)
             //printf("%d %d\n",u,v);
            a[u].pb(v);
            a[v].pb(u);

        }

        cycle[1]=0;

        flag=0;
        dfs(1);
        int num=0,ans=0;

        for(int j=1;j<=n;j++)
        if(taken[j])
        {
            num++;
            if(!even[j]) ans++;//jader even deg ase tarai ans,,,1 ke 0 (even) dhore
        }
       // if(cas==36) printf("%d\n",num);
        if(flag==1) ans=num;//odd cycle thakle sobai
        if(num==1) ans=0;// shudhu 1 hole no carry


        //if(cas==36)
        printf("Case %d: %d\n",cas,ans);


    }
    return 0;
}
