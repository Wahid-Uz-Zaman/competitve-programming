#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#define max 30000
using namespace std;
vector<int>av[max];
int ans;
int taken[max];

void dfs(int s)
{
    taken[s]=1;
    for(int i=0;i<av[s].size();i++)
    {
        int u=av[s][i];
        if(taken[u]==0) dfs(u);
        else if(taken[u]==1)
        {
            ans=1;
            return;
        }
        else;
    }
    taken[s]=2;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int m;
        scanf("%d",&m);
        map<string,int>a;
        int k=0;
        for(int j=1;j<=m;j++)
        {
            char x[15],y[15];
            scanf("%s %s",x,y);
            pair<map<string,int>::iterator,bool>ret;
            ret=a.insert(pair<string,int>(x,k));
            if(ret.second==true) k++;
            ret=a.insert(pair<string,int>(y,k));
            if(ret.second==true) k++;
            int u=a[x];
            int v=a[y];
            av[u].push_back(v);

        }
        //k node size
        memset(taken,0,sizeof(taken));
        ans=0;
        for(int j=0;j<k;j++)
        {
            if(ans==1) break;
            if(taken[j]==0) dfs(j);
        }
        if(ans==1) printf("Case %d: No\n",i);
        else printf("Case %d: Yes\n",i);
        for(int j=0;j<max;j++) av[j].clear();
    }

    return 0;
}
