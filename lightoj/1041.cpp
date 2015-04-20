#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<map>
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
    int count=0;
    for(int i=0;i<E.size();i++)
    {
        int ux=find(E[i].u);
        int vx=find(E[i].v);
        if(ux!=vx)
        {
            count++;
            mn+=E[i].w;
            pr[ux]=vx;
        }

        if(count==n-1) break;
    }
    if(count==n-1) return mn;
    return -1;

}

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int m;
        scanf("%d",&m);
        map<string,int>a;
        E.clear();
        int k=1;
        for(int j=1;j<=m;j++)
        {
            char x[55],y[55];
            int w;
            scanf("%s %s %d",x,y,&w);
            pair<map<string,int>::iterator,bool>ret;
            ret=a.insert(pair<string,int>(x,k));
            if(ret.second==true) k++;
            ret=a.insert(pair<string,int>(y,k));
            if(ret.second==true) k++;
            int u=a[x];
            int v=a[y];
            edge temp;
            temp.u=u;
            temp.v=v;
            temp.w=w;
            E.push_back(temp);


        }
        n=k-1;
        //printf("%d\n",k);
        sort(E.begin(),E.end());
        int an=mst();
        if(an==-1) printf("Case %d: Impossible\n",i);
        else printf("Case %d: %d\n",i,an);
    }


    return 0;
}
