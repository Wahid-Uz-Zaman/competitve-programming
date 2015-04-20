#include<cstdio>
#include<queue>
#include<vector>
#include<cstdlib>
#include<bitset>
#include<iostream>
#include<cstring>

#define max(m,n) m>n?m:n
#define high 20001

using namespace std;
int ans;
void BFS(vector<int> v[],int s,int b[],int p[])
{

    queue<int> q;
    if(!(v[s].empty())){
    q.push(s);
    int x=1,y=0;

    b[s]=1;
    p[s]=-1;

    while(!(q.empty()))
    {
        int u=q.front();



        for(int i=0;i<v[u].size();i++)
        {
            if(b[v[u][i]]==0)
            {
                q.push(v[u][i]);

                p[v[u][i]]=u;
                if(p[u]!=-1) b[v[u][i]]=b[p[u]];
                else b[v[u][i]]= 2;
                if(b[v[u][i]]==2) y++;
                else x++;
            }
        }

        q.pop();
    }
    ans+=max(x,y);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt")
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int num;
        scanf("%d",&num);
        vector<int> a[high];
        int   b[high];
        int  p[high];

        ans=0;
        for(int j=1;j<=num;j++)
        {
            int m,n;
            scanf("%d %d",&m,&n);
            a[m].push_back(n);
            a[n].push_back(m);
        }
        memset(b,0,sizeof(b));
        memset(p,0,sizeof(p));

        for(int j=1;j<high;j++)
        {
            if(b[j]==0)
            {
                BFS(a,j,b,p);

        }}


        printf("Case %d: %d\n",i,ans);




    }
    return 0;
}
