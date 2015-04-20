#include<cstdio>
#include<cstring>
#define mx(a,b) a>b?a:b
#define max 100005
using namespace std;
int M[4*max];
void change(int start,int end,int low,int high,int node)
{
    if(low>end || high<start) return ;
    if( start>=low && end<=high) {M[node]++;return;}
    int mid=(start+end)/2;
    change (start,mid,low,high,2*node);
    change(mid+1,end,low,high,2*node+1);

}
int totalchange(int start,int end,int index,int node)
{
    //printf(" %d %d %d\n",start,end,index);
    if(start==end && start==index) return M[node];
    else
    {
        int mid=(start+end)/2;
        if(index>=start && index<=mid)
        return M[node]+totalchange(start,mid,index,2*node);
        else   return M[node]+totalchange(mid+1,end,index,2*node+1);
    }

}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        char a[max];
        scanf("%s",a);
        int n=strlen(a);
        //printf("%d\n",n);
        memset(M,0,sizeof(M));
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",i);
        for(int j=1;j<=q;j++)
        {
            char command[2];
            scanf("%s",command);
            if(command[0]=='I')
            {
                int low,high;
                scanf("%d %d",&low,&high);
                change(1,n,low,high,1);
                //for(int k=1;k<25;k++) printf("%d %d\n",k,M[k]);
                //printf("\n\n\n");

            }
            else if(command[0]=='Q')
            {
                int index;
                scanf("%d",&index);
                int ans=a[index-1]-48;
                //printf("as");
                int ch=totalchange(1,n,index,1);
                if(ch%2==0) printf("%d\n",ans);
                else printf("%d\n",ans^1);

            }
            else ;
        }
    }
    return 0;
}
