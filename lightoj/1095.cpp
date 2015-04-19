#include<cstdio>
#include<cmath>
#define mod 1000000007
using namespace std;
int ncr[1001][1001];
long long int a[1001];
int ncr_make()
{
    for(int i=0;i<=1000;i++)
    {
        ncr[i][0]=1;
        for(int j=1;j<i;j++) ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
        ncr[i][i]=1;
    }
}
int facto()
{
    a[0]=a[1]=1;
    for(int i=2;i<1001;i++)
    {
        a[i]=(a[i-1]*i)%mod;
    }
}
int main()
{
    ncr_make();
    facto();
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,m,k,ans=0;
        scanf("%d %d %d",&n,&m,&k);
        for(int j=k+1;j<=m;j++)
        {
            ans=(ans+((((ncr[m][j]*a[n-j])%mod)*ncr[m][k])%mod))%mod;
        }
        ans=(((ncr[m][k]*a[n-k])%mod))%mod;
        printf("Case %d: %d\n",i,ans);



    }

}
