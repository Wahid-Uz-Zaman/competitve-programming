#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define vmx 55
using namespace std;
struct edge
{
    int u;
    int v;
    int w;
    bool operator<(const edge temp) const
    {
        return w<temp.w;
    }
    bool operator==(const edge temp)const
    {
        return w==temp.w;
    }
};
int n;
int pr[vmx];
int mn;

vector <edge> E;
int find(int r)
{
   return (pr[r]==r) ? r:  find(pr[r]);
}

int  mst()
{
    for(int i=1;i<=n;i++) pr[i]=i;
    mn=0;
    int ans=0;
    int count=0;
    for(int i=0;i<E.size();i++)
    {
        int u=E[i].u;
        int v=E[i].v;
        int w=E[i].w;
        int ux=find(u);
        int vx=find(v);
        if(ux!=vx)
        {
            count++;
            pr[ux]=vx;
        }
        else
        {
            ans+=w;
        }
        //if(count==n) break;
    }
    if(count==n-1) return ans;
    return -1;

}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d",&n);
        E.clear();
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int w;
                scanf("%d",&w);
                if(w!=0)
                {
                    if(i==j) ans+=w;
                    else{

                    edge temp;
                    temp.u=i;
                    temp.v=j;
                    temp.w=w;
                    E.push_back(temp);}
                }

            }
        }
        sort(E.begin(),E.end());
        int an=mst();
        if(an==-1) printf("Case %d: %d\n",k,an);
        else printf("Case %d: %d\n",k,ans+an);

    }




    return 0;
}
