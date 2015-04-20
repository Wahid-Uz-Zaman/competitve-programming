#include<cstdio>
#include<algorithm>
#define mx 100010
#define inf 100000003
using namespace std;
int a[mx];
int aux[4*mx][2];
int ans[2];
void init(int s,int e,int node)
{
    if(s==e)
    {
        aux[node][0]=aux[node][1]=a[s];
    }
    else
    {
        int m=(s+e)/2;
        init(s,m,2*node);
        init(m+1,e,2*node+1);
        aux[node][0]=max(aux[2*node][0],aux[2*node+1][0]);
        aux[node][1]=min(aux[2*node][1],aux[2*node+1][1]);

    }
}
void find(int s,int e,int l,int h,int node)
{
    if(s>h || e<l) return ;
    if(s>=l && e<=h)
    {
        ans[0]=max(ans[0],aux[node][0]);
        ans[1]=min(ans[1],aux[node][1]);
        return;
    }
    int m=(s+e)/2;
    find(s,m,l,h,2*node);
    find(m+1,e,l,h,2*node+1);
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,d;
        scanf("%d %d",&n,&d);
        for(int j=1;j<=n;j++) scanf("%d",&a[j]);
        init(1,n,1);
        int maxdif=-1;
        for(int j=1;j+d-1<=n;j++)
        {
            ans[0]=-1;
            ans[1]=inf;
            find(1,n,j,j+d-1,1);
            maxdif=max(maxdif,(ans[0]-ans[1]));
        }

        printf("Case %d: %d\n",i,maxdif);
    }
    return 0;
}
