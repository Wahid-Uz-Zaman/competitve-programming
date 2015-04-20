#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int binary_search(int a[],int k,int start)
{
    int end=n-1,mid=(start+end)/2,temp=start;
    while(start<=end)
    {
        if(a[mid]<k && a[mid+1]>=k) return mid;
         else if(a[mid]<k && a[mid+1]<k)
        {
            start=mid+1;
        }
        else end=mid-1;
        mid=(start+end)/2;
        if(mid==n-1) return end;
        //if(mid==temp) return temp-1;

    }
    return temp-1;

}
int main()
{
    int t,a[2004];
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {

        scanf("%d",&n);
        int ans=0;
        for(int j=0;j<n;j++) scanf("%d",&a[j]);
        sort(a,a+n);
        for(int j=0;j<n-2;j++)
        {
            for(int k=j+1;k<n-1;k++)
            {
               ans+=(binary_search(a,a[j]+a[k],k+1)-k);
            }
        }
        printf("Case %d: %d\n",i,ans);


    }
    return 0;
}
