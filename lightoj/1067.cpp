#include<cstdio>
#include<cmath>
#define mod 1000003
#define max 1000003
using namespace std;


long int a[max];

long long int power(long long int n,long long int p)
{
    if(p==0) return 1;
    if(p==1) return n;
    long long int m=power(n,p/2);
    if(p%2) return (n*(m%mod)*(m%mod))%mod;
    else return ((m%mod)*(m%mod))%mod;

}
void make()
{
    a[1]=a[0]=1;

    for(long long int i=2;i<max;i++)
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

        long long int ans=(a[n]%mod*power(a[k],mod-2)%mod)%mod*power(a[n-k],mod-2)%mod;
        printf("Case %d: %lld\n",i,ans);

    }
    return 0;
}
