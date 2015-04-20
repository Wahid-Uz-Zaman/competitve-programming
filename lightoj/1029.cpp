#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define vmx 1005
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
int mx;
int mn;

vector <edge> E;
int find(int r)
{
   return (pr[r]==r) ? r:  find(pr[r]);
}

int  mst()
{
    for(int i=0;i<=n;i++) pr[i]=i;
    mx=0;mn=0;
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
            mn+=w;
            // printf("%d %d %d %d %d\n",u,v,w,find(u),find(v));
             pr[ux]=vx;



        }
        if(count==n) break;
    }
    int ans=mn;
    //printf("%d min\n",mn);
    for(int i=0;i<=n;i++) pr[i]=i;
    count=0;
    for(int i=E.size()-1;i>=0;i--)
    {
        int u=E[i].u;
        int v=E[i].v;
        int w=E[i].w;
        int ux=find(u);
    int vx=find(v);
        if(ux!=vx)
        {
            count++;
            mx+=w;
            //printf("%d %d %d %d %d\n",u,v,w,pr[u],pr[v]);
            pr[ux]=vx;

        }
        if(count==n) break;
    }
     //printf("%d max\n",mx);
    ans+=mx;
    return ans;

}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        E.clear();
        while(1)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            if(u==0 &&v==0 &&w==0) break;
            if(u==v) continue;
            else
            {
                edge temp;
                temp.u=u;
                temp.v=v;
                temp.w=w;
                E.push_back(temp);

            }
        }
        sort(E.begin(),E.end());
        int ans=mst();
        if(ans%2) printf("Case %d: %d/2\n",i,ans);
        else printf("Case %d: %d\n",i,ans/2);

    }




    return 0;
}
