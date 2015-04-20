#include<bits/stdc++.h>
#define mx 1005
using namespace std;
int a[mx];
int n;
int func(int x,int m)
{
    int nn=x,c=1;
   // printf("x%d\n",x);
    for(int i=0;i<n;i++)
    {
        if(a[i]>nn){;nn=x;c++;}nn-=a[i];
        //printf("n%d\n",n);
    }
    //printf("c%d\n",c);
   if(c<=m)return 1;
   else return 0;
}
int bins(int sum,int m,int ma)
{
    int start=ma,end=sum,ans;
    while(start<=end)
    {
        int mid=(start+end)>>1;
        //printf("%d %d\n",mid,func(mid,m));
        if(func(mid,m)==1)
        {
            ans=mid;
            end=mid-1;
        }
        else start=mid+1;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int m,sum=0,ma=0;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){scanf("%d",&a[i]);sum+=a[i];if(ma<a[i])ma=a[i];}

        printf("Case %d: %d\n",cas,bins(sum,m,ma));




    }
    return 0;

}
