#include<cstdio>
#define mod 1000000007
#define mx 60
#define ll long long int
using namespace std;
ll ncr[mx][mx];

void ncr_make()
{
    for(ll i=0;i<mx;i++) ncr[i][0]=1,ncr[i][i]=1;
    for(ll i=2;i<mx;i++)
    {
        for(ll j=1;j<i;j++) ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1]);
    }
}
int main()
{
    ncr_make();
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,m,k;
        scanf("%d %d %d",&n,&k,&m);
        ll ans=ncr[n-1][k-1];
        ll p=-1;
        for(int j=1;n-j*m>=1;j++)
        {
            ll x=ncr[k][j]*ncr[n-j*m-1][k-1]*p;
            ans+=x;
            p=-p;
        }
        printf("Case %d: %lld\n",i,ans);


    }

    return 0;
}
