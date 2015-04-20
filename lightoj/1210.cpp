#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define max 20050
using namespace std;
vector<int>a[max];
vector <int>b[max];
int n;
struct node
{
    int f;
    int num;
    node(int n,int fin){num=n,f=fin;}
    bool operator<(const node t) const{
        return f<t.f;
    }
};
vector<node>v;
bool taken[max];
int d=0;
int comp[max];
int comp_num;
int indeg_comp[max];
int outdeg_comp[max];
void dfs(int u)
{
    taken[u]=1;
    d++;
    //dis[u]=d;
    for(int i=0;i<a[u].size();i++)
    {
        int v=a[u][i];
        if(taken[v]==0) dfs(v);
    }
    d++;
    //fin[u]=d;
    v.push_back(node(u,d));

}
void dfs_(int u)
{
    taken[u]=1;
    comp[u]=comp_num;
    for(int i=0;i<b[u].size();i++)
    {
        int v=b[u][i];
        if(taken[v]==0) dfs_(v);
    }
}

int  scc()
{
    //first dfs
    d=0;
    v.clear();
    memset(taken,0,sizeof(taken));
    for(int i=1;i<=n;i++)
    {
        if(!taken[i]) dfs(i);
    }
    sort(v.begin(),v.end());
    //2nd dfs
    memset(taken,0,sizeof(taken));
    comp_num=0;
    for(int i=v.size()-1;i>=0;i--)
    {
        int u=v[i].num;
        if(!taken[u]) {dfs_(u);comp_num++;};
    }
    //comp_num->num of comp
    if(comp_num==1) return 0;
    int ans;
    memset(indeg_comp,0,sizeof(indeg_comp));
    memset(outdeg_comp,0,sizeof(outdeg_comp));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<a[i].size();j++)
            {
                int v=a[i][j];
                if(comp[i]!=comp[v]) {outdeg_comp[comp[i]]++;
                indeg_comp[comp[v]]++;}
            }
    }

    //
    ans=0;
    int in=0;
    int out=0;
    for(int i=0;i<comp_num;i++)
    {
        if(indeg_comp[i]==0) in++;
        if(outdeg_comp[i]==0) out++;
    }
    ans= in>out?in:out;
    return ans;
}
int main()
{
    //freopen("in2.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        for(int j=0;j<max;j++) {a[j].clear(),b[j].clear();}
        int m;
        scanf("%d %d",&n,&m);
        for(int j=1;j<=m;j++)
        {
                int u,v;
                scanf("%d %d",&u,&v);
                a[u].push_back(v);
                b[v].push_back(u);
        }//input;

        int ans=scc();
        printf("Case %d: %d\n",i,ans);

    }
    return 0;
}
