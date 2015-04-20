#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define max 1050
using namespace std;
vector<int>a[max];
vector <int>b[max];
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
bool exist[max];
//int dis[max];
//int fin[max];
int comp[max];
int comp_num;
int indeg_comp[max];
int outdeg_comp[max];
int origincomp;
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
    if(u==0) origincomp=comp_num;
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
    if(exist[0]==0) return 0;
    d=0;
    v.clear();
    memset(taken,0,sizeof(taken));
    for(int i=0;i<1000;i++)
    {
        if(exist[i] && !taken[i]) dfs(i);
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
    int ans;
    if(comp_num==1)ans=1;
    else{
    for(int i=0;i<comp_num;i++)
    {
        indeg_comp[i]=0;
        outdeg_comp[i]=0;
    }
    for(int i=0;i<max;i++)
    {
        if(exist[i])
        {
            for(int j=0;j<a[i].size();j++)
            {
                int v=a[i][j];
                if(comp[i]!=comp[v]) {outdeg_comp[comp[i]]++;
                indeg_comp[comp[v]]++;}
            }
        }
    }

    //
    ans=0;
    if(indeg_comp[origincomp]==0 && outdeg_comp[origincomp]==1) ans=1;
    if(ans==1)
    {
        int end=0,i;
        for(i=0;i<comp_num;i++)
        {
            if(i!=origincomp)
            {
                if(indeg_comp[i]==1 && outdeg_comp[i]==1) continue;
                else if(indeg_comp[i]==1 &&outdeg_comp[i]==0 ) {end++;continue;}
                else break;
            }
        }
        if(i==comp_num && end==1) ans=1;
        else ans=0;
    }
    }
    return ans;
}
int main()
{
    //freopen("in2.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        memset(exist,0,sizeof(exist));
        for(int j=0;j<max;j++) {a[j].clear(),b[j].clear();}
        int n;
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
        {
            int k;
            scanf("%d",&k);
            for(int p=1;p<=k;p++)
            {
                int u,v;
                scanf("%d %d",&u,&v);
                a[u].push_back(v);
                exist[u]=exist[v]=1;
                b[v].push_back(u);
            }

        }//input;

        int ans=scc();
        if(ans==1) printf("Case %d: YES\n",i);
        else printf("Case %d: NO\n",i);



    }
    return 0;
}
