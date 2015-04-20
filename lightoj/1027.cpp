#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int a[101];
        int n,sum=0,count=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++) scanf("%d",&a[j]);
        for(int j=0;j<n;j++){

             if(a[j]<0)
             {
                 sum+=((-1)*a[j]);
                 count++;
             }
            else sum+=a[j];}
        if(n-count)
        {
            int te=gcd(sum,n-count);
            printf("Case %d: %d/%d\n",i,sum/te,(n-count)/te);
        }
        else printf("Case %d: inf\n",i);


    }
    return 0;
}
