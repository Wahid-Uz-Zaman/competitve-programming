//component e 0 origin ,end 1 tai hobe ..baki comp er indeg==oitdweg==1

#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define mx 51000
using namespace std;
vector<int>a[mx];
vector <int>b[mx];
struct ans
{
    int vertex;
    int size;
    ans(int v,int s)
    {
        vertex=v;
        size=s;
    }
    bool operator<(const ans t) const{
        return  (size<t.size) || (size==t.size && vertex>t.vertex);
    }
};
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
vector<ans>answer;
bool taken[mx];
int d=0;
int comp[mx];
int comp_num;
int cnt;
int smallest;
int comp_size[mx];
int indeg[mx];
int outdeg[mx];
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
    v.push_back(node(u,d));

}
void dfs_(int u)
{
    cnt++;
    smallest=min(smallest,u);
    taken[u]=1;
    comp[u]=comp_num;
    for(int i=0;i<b[u].size();i++)
    {
        int v=b[u][i];
        if(taken[v]==0) dfs_(v);
    }
}

void  scc(int n)
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
    for(int j=1;j<=n;j++) comp[j]=-1;
    for(int i=v.size()-1;i>=0;i--)
    {
        int u=v[i].num;
        if(!taken[u])
        {
            cnt=0;smallest=u;dfs_(u);
            if(cnt==1) comp[u]=-1;
            else
            {
                comp_size[comp_num]=cnt;
                answer.push_back(ans(smallest,cnt));
            }
            comp_num++;
        };
    }
    //comp_num->num of comp
}
void dfs_path(int u)
{
    cnt++;
    taken[u]=1;
    for(int i=0;i<a[u].size();i++)
    {
        int v=a[u][i];
        if(comp[v]!=-1){cnt+=(comp_size[comp[v]]);
            return;}
        if(!taken[v]) dfs_path(v);

    }
    return ;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("in1.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {

        int n;
        scanf("%d",&n);
       // printf("%d\n",n);
        for(int j=1;j<=n;j++)
        {
            a[j].clear(),b[j].clear();
            indeg[j]=0;
            outdeg[j]=0;
        }
        for(int j=1;j<=n;j++)
        {
                int u,v;
                scanf("%d %d",&u,&v);
                //printf("%d %d\n",u,v);
                a[u].push_back(v);
                indeg[v]++;
                outdeg[u]++;
                b[v].push_back(u);

        }//input;
       answer.clear();
       scc(n);
       //for(int j=1;j<=n;j++) printf("%d %d\n",j,comp[j]);
       memset(taken,0,sizeof(taken));
       for(int j=1;j<=n;j++)
       {
           if(indeg[j]==0)
           {
               cnt=0;
               memset(taken,0,sizeof(taken));
               dfs_path(j);
               answer.push_back(ans(j,cnt));
           }
       }
       //for(int j=0;j<answer.size();j++)printf("%d %d\n",answer[j].vertex,answer[j].size);
       sort(answer.begin(),answer.end());
      printf("Case %d: %d\n",i,answer[answer.size()-1].vertex);

    }
    return 0;
}
