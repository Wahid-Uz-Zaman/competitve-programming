#include<cstdio>
#include<cmath>

#define max 2000010
using namespace std;

long long  int mod=1000000007;

long long  int a[max];

long long int power(long long int n,long long int p)
{
    if(p==0) return 1;
    if(p==1) return n%mod;
    long long int m=power(n,p/2)%mod;
    if(p%2) return (((n*m)%mod)*m)%mod;
    else return ((m%mod)*(m%mod))%mod;

}
void make()
{
    a[1]=a[0]=1;

    for(long long  int i=2;i<max;i++)
    {
        a[i]=(a[i-1]*i)%mod;

    }
}






int main()
{
    make();
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        long long int n,k;
        scanf("%lld %lld",&n,&k);

        long long int ans,s,d;
        s=a[n+k-1];
        d=(power(a[n],mod-2)*s)%mod;
        s=power(a[k-1],mod-2);

        ans=(s*d)%mod;
        printf("Case %d: %lld\n",i,ans);

    }
    return 0;
}
