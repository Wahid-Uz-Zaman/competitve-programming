#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>

#define MAX 30000
using namespace std;
//int ans;
int w[ MAX];
bool used[ MAX];
struct weight{
    int x;
    int ew;
    };
 vector<int>maxtemp;
 vector<int>ans;
void dfs(vector<struct weight>a[],int s)
{
    used[s]=true;
    for(int i=0;i<a[s].size();i++)
    {
        struct weight temp=a[s][i];
        if(!(used[temp.x])) dfs(a,temp.x);
    }
    maxtemp.clear();
    for(int i=0;i<a[s].size();i++)
    {
        struct weight d=a[s][i];
         maxtemp.push_back(w[d.x]+d.ew);
    }
    sort(maxtemp.begin(),maxtemp.end(),greater<int>());
    ans.push_back(maxtemp[0]+maxtemp[1]);
    w[s]=maxtemp[0];
    printf("%d %d\n",s,w[s]);



}
int main()
{

    freopen("in.txt","r",stdin);
    int t;

    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        //ans=0;
        memset(w,0,sizeof(w));
        memset(used,0,sizeof(used));
        maxtemp.clear();
        ans.clear();

        vector<struct weight>a[MAX];

        for(int j=1;j<n;j++)
        {
            int p,q,w;
            struct weight d,e;
            scanf("%d %d %d",&p,&q,&w);

            d.x=q;
            e.x=p;
            d.ew=e.ew=w;

            a[p].push_back(d);
            a[q].push_back(e);
        }
        dfs(a,0);
        sort(ans.begin(),ans.end(),greater<int>());

        printf("Case %d: %d\n",i,ans[0]);
    }
    return 0;
}
