#include<cstdio>
#include<cstring>
#include<vector>
#define mx(a,b) a>b?a:b
#define max 100010
#define ll long long int
using namespace std;
int  a[max];
int M[4*max];
void initialize(int start,int end,int node)
{
    if(start==end) M[node]=a[start];
    else
    {
        int mid=(start+end)/2;
        initialize(start,mid,2*node);
        initialize(mid+1,end,2*node+1);
        M[node]=M[2*node]+M[2*node+1];

    }
    //printf(" ini %d %d %lld\n",start,end,M[node]);
}
int find (int start,int end,int low,int high,int node)
{
    if(low>end || high<start) return -1;
    if(start>=low && end<=high) return M[node];
    int mid=(start+end)/2;
    int ans1=find(start,mid,low,high,2*node);
    int ans2=find(mid+1,end,low,high,2*node+1);
    if(ans1==-1) return ans2;
    if(ans2==-1) return ans1;
    return ans1+ans2;
}
void update(int start,int end,int index,int  node,int v)
{
    //printf("call %d %d %d %d %lld\n",start,end,index,node,v);
    if(start==end && start==index) M[node]=M[node]+ v;
    else
    {

       int mid=(start+end)/2;
         //printf("%lld %lld %lld\n",start,mid,end);
       if(index>=start && index<=mid)
       update(start,mid,index,2*node,v);
       else update(mid+1,end,index,2*node+1,v);
       //printf(" be %d %d %d\n",start,end,M[node]);
       M[node]=M[node]+ v;
       //printf(" af %d %d %d\n",start,end,M[node]);
    }
   // printf(" ini %d %d %d\n",start,end,M[node]);

}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n;
        int q;
        scanf("%d %d",&n,&q);
        for(int j=1;j<=n;j++) scanf("%d",&a[j]);
        initialize(1,n,1);
        int index;
        printf("Case %d:\n",i);
        for(int j=1;j<=q;j++)
        {
            int com;
            scanf("%d",&com);
            if(com==1)
            {
                scanf("%d",&index);
                printf("%d\n",a[index+1]);
                update(1,n,index+1,1,0-a[index+1]);
                a[index+1]=0;
            }
            else if(com==2)
            {
                ll v;
                scanf("%d %d",&index,&v);
                a[index+1]+=v;
                update(1,n,index+1,1,v);
                //for(int k=1;k<21;k++) printf("\n\n%d %lld\n",k,M[k]);
            }
            else
            {
                int low,high;
                scanf("%d %d",&low,&high);
                int ans=find(1,n,low+1,high+1,1);
                printf("%d\n",ans);
            }
        }
    }
    return 0;

}
